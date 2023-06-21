#include <stdio.h>
#include <stdlib.h>   // para o malloc!
#include <string.h>
#include <time.h>

typedef struct tipoJogador {
  char nome[40];
  unsigned pontuacao;
} tipoJogador;

typedef struct tipoNo {
  tipoJogador d;
  struct tipoNo *prox;
} tipoNo;


typedef struct tipoListaCircular {
  tipoNo * atual;
} tipoListaCircular;

                  
void criaListaCircular(tipoListaCircular *l) {
   l->atual = NULL;
}

                                   
void insereNaListaCircular(tipoListaCircular *l, tipoJogador dado) {
  tipoNo *aux;

  aux = (tipoNo *) malloc(sizeof(tipoNo));
  aux->d   = dado;
  if(l->atual == NULL)  {
    l->atual = aux;
    aux->prox = aux;
  }
  else {
    aux->prox = l->atual->prox;
    l->atual->prox = aux;
   }

}

void moveParaProximo(tipoListaCircular *l) {
  l->atual = l->atual->prox;
}

void mostraListaCircular(tipoListaCircular *l) {
  tipoNo * aux;

  aux = l->atual;
  if(aux) {
    do {
      printf("%s \n",aux->d.nome);
      printf("%u\n",aux->d.pontuacao);
      aux = aux->prox;
    } while(aux != l->atual);
  }
}




void gravaListaCircular(tipoListaCircular *l, char *arquivo) {
  tipoNo * aux;
  FILE *fp;

  fp = fopen(arquivo,"w");
  if(fp == NULL ) {
    printf("Erro na criação do arquivo\n"); exit(1);
  }
  aux = l->atual;
  if(aux) {
    do {
      fprintf(fp,"%s \n",aux->d.nome);
      fprintf(fp,"%u\n",aux->d.pontuacao);
      aux = aux->prox;
    } while(aux != l->atual);
  }
  fclose(fp);
}




int lerListaCircular(tipoListaCircular *l, char *arquivo) {
  tipoNo * aux;
  FILE *fp;
  tipoJogador tmp;
  int retornoScanf;

  fp = fopen(arquivo,"r");
  if(fp == NULL ) {
    printf("Não encontrei arquivo do jogo\n");
    return 0;
  }
 
  do {
    fscanf(fp, "%[^\n]%*c",tmp.nome); 
    retornoScanf = fscanf(fp, "%d%*c",&tmp.pontuacao);
    if(retornoScanf == 1) {
       insereNaListaCircular(l,tmp);
    }
  }while (retornoScanf != EOF);
  return 1;
  fclose(fp);
}






int mostraPosicao(tipoListaCircular *l, char* chave) {
  tipoNo * aux;
  int cont = 1;
  aux = l->atual;
  if(aux) {
    do {
      if (strcmp(aux->d.nome, chave) == 0) {return cont;}
      cont++;
      aux = aux->prox;
    } while(aux != l->atual);
  }
  return 0;
}


tipoJogador *obtemJogadorAtual(tipoListaCircular *l) {
  if(l->atual) {
  return &(l->atual->d);
  }
  return NULL;
}

tipoJogador *ultimoDaRodada(tipoListaCircular *l) {
  tipoNo * aux;
  aux = l->atual;
  if(aux) {
    while(aux->prox != l->atual) {
      aux = aux->prox;
    }
    return &(aux->d);
  }
  return NULL;
}



/* ALTERE PARA VIRAR A BUSCA EM LISTA CIRCULAR USANDO A FUNCAO MOSTRA (ACIMA) COMO MODELO
 

tipoJogador * buscaNaListaLista(tipoLista *l,char nome[]) {
  tipoNo * aux;

  aux = l->prim;
  while(aux !=NULL) {
    if(strcmp(nome, aux->d.nome)==0) {
      return &(aux->d);
    }
    aux = aux->prox;
  }
  return NULL;
}
*/




/* 
ALERE PARA VIRAR A REMOVE DA LISTA CIRCULAR USANDO AS DICAS DA FUNCAO MOSTRA

void removeDaLista(tipoLista *l,char nome[]) {
  tipoNo * aux,*tmp;

  aux = l->prim;
  if(aux) {   // Se há elementos na lista!
    if(strcmp(nome,aux->d.nome)==0) {
      l->prim = aux->prox;
      free(aux);
    }
    else {
       while(aux->prox !=NULL) {
	if(strcmp(nome, aux->prox->d.nome)==0) {
	  tmp = aux->prox;
	  aux->prox = tmp->prox;
	  free(tmp);
	  return;
	}
	aux = aux->prox;
      }

    }
  }
}
*/

int geraNumeroAleatorio() {
  return rand()%11;
}


int main() {
  tipoListaCircular l1;
  int x;
  tipoJogador tmp;
 criaListaCircular(&l1);

 srand(time(NULL));  


 if(lerListaCircular(&l1,"dadosDoJogo") == 0) {

   printf("Entre com o nome dos 4 jogadores\n");
   for(x = 0 ; x < 4; x++) {
     printf("Entre com o nome: ");
     scanf("%[^\n]%*c",tmp.nome);
     tmp.pontuacao = 0;
     insereNaListaCircular(&l1,tmp);
   }
 }

 printf("situação atual do jogo\n");
 mostraListaCircular(&l1);
   
  // O JOGO PROPRIAMENtE DITo

  char continua = 1;
  int palpite, numeroGerado;
  tipoJogador *daVez;
  while(continua) {
    daVez = obtemJogadorAtual(&l1);
    if(daVez) {
      printf("Próximo a jogar: %s\n",daVez->nome );
      printf("Entre com um número: ");
      scanf("%d%*c",&palpite);
      numeroGerado = geraNumeroAleatorio();
      if(numeroGerado == palpite) {
	printf("Parabéns! você acertou!\n");
	daVez->pontuacao++;
      }
      else {
	printf("Lamento, o número correto era: %d\n",numeroGerado);
      }
      moveParaProximo(&l1);
      printf("Desejam continuar (SIM = 1/NÃO = 0) ?\n");
      scanf("%hhd%*c",&continua);
    }
    else {
      continua = 0;
    }
   
      }

  printf("resultado do jogo\n");
  mostraListaCircular(&l1);

  printf("Deseja salvar jogo em arquivo  (SIM = 1/NÃO = 0) ?\n");
  scanf("%hhd%*c",&continua);
  // AQUI VAMOS SALVAR OS DADOS
  gravaListaCircular(&l1,"dadosDoJogo");
  
}

