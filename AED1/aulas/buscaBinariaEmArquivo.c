#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

typedef struct tipoAluno {
  char nome[40];
  char pibic; // verdadeiro ou falso
  char curso[40];
  float coeficienteRendimento;
  unsigned id;
} tipoAluno;




void preencheDadosAlunoAleatoriamente(tipoAluno *al) {
  unsigned long aleat = rand();

  al->coeficienteRendimento = rand()%1000;
  al->coeficienteRendimento/=100;
  al->pibic = rand()%2;
  switch(aleat%5) {
  case 0: 
    strcpy(al->curso,"Geografia");
    break;
  case 1: 
    strcpy(al->curso,"Matematica");
    break;
 case 2: 
    strcpy(al->curso,"Ciência da Computacao");
    break;
 case 3: 
    strcpy(al->curso,"Engenharia de Software");
    break;
 case 4: 
    strcpy(al->curso,"Engenharia de Computação");
    break;
  }

  switch(aleat%10) {
  case 0: 
    strcpy(al->nome,"Jose ");
    break;
  case 1: 
    strcpy(al->nome,"Hermenildo ");
    break;
 case 2: 
    strcpy(al->nome,"Ricenilda ");
    break;
 case 3: 
    strcpy(al->nome,"Adexandrina ");
    break;
 case 4: 
    strcpy(al->nome,"Eltironio ");
    break;
 case 5: 
    strcpy(al->nome,"Belizarino ");
    break;
 case 6: 
    strcpy(al->nome,"Ufandisson ");
    break;
 case 7: 
    strcpy(al->nome,"Icompino ");
    break;
 case 8: 
    strcpy(al->nome,"Manauarisson ");
    break;
 case 9: 
    strcpy(al->nome,"Ana ");
    break;
  }


  switch(rand()%6) {
  case 0: 
    strcat(al->nome," ");
    break;
  case 1: 
    strcat(al->nome,"da ");
    break;
 case 2: 
    strcat(al->nome,"de ");
    break;
 case 3: 
    strcat(al->nome,"do ");
    break;
 case 4: 
    strcat(al->nome,"das ");
    break;
 case 5: 
    strcat(al->nome,"dos ");
    break;

  }


 switch(aleat%10) {
  case 0: 
    strcat(al->nome,"Silva  ");
    break;
  case 1: 
    strcat(al->nome,"Souza ");
    break;
 case 2: 
    strcat(al->nome,"Pereira ");
    break;
 case 3: 
    strcat(al->nome,"Ramalho ");
    break;
 case 4: 
    strcat(al->nome,"Gomes ");
    break;
 case 5: 
    strcat(al->nome,"Messias ");
    break;
 case 6: 
    strcat(al->nome,"Cardozo ");
    break;
 case 7: 
    strcat(al->nome,"Icompino ");
    break;
 case 8: 
    strcat(al->nome,"Dores ");
    break;
 case 9: 
    strcat(al->nome,"Melo ");
    break;
  }

  switch(rand()%6) {
  case 0: 
    strcat(al->nome," ");
    break;
  case 1: 
    strcat(al->nome,"da ");
    break;
 case 2: 
    strcat(al->nome,"de ");
    break;
 case 3: 
    strcat(al->nome,"do ");
    break;
 case 4: 
    strcat(al->nome,"das ");
    break;
 case 5: 
    strcat(al->nome,"dos ");
    break;

  }


  switch(rand()%10) {
  case 0: 
    strcat(al->nome,"Silva  ");
    break;
  case 1: 
    strcat(al->nome,"Souza ");
    break;
 case 2: 
    strcat(al->nome,"Pereira ");
    break;
 case 3: 
    strcat(al->nome,"Ramalho ");
    break;
 case 4: 
    strcat(al->nome,"Gomes ");
    break;
 case 5: 
    strcat(al->nome,"Messias ");
    break;
 case 6: 
    strcat(al->nome,"Cardozo ");
    break;
 case 7: 
    strcat(al->nome,"Icompino ");
    break;
 case 8: 
    strcat(al->nome,"Dores ");
    break;
 case 9: 
    strcat(al->nome,"Melo ");
    break;
  }

}


typedef struct tipoNo {
  tipoAluno dado;
  struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista {
  tipoNo *prim;
   tipoNo *ult;
  unsigned numElementos;
  char nomeEquipe[30];
} tipoLista;


/* indica quantos bytes tenho no arquivo */

unsigned long tamanhoArquivo(FILE *f) {

struct stat buf;
fstat(fileno(f), &buf);
return buf.st_size;
}



/* Uma versão que muitos programadores usam
 */

int tamanhoArquivoAlternativa(FILE *f) {
  unsigned long tmp,tamanho;
  tmp= ftell(f);
  fseek(f,0, SEEK_END);
  tamanho = ftell(f);
  fseek(f,tmp, SEEK_SET);
  return tamanho;
}



void mostraAluno(tipoAluno al) {
  printf("ID: %u\n",al.id);
  printf("Nome: %s\n",al.nome);
  printf("Curso: %s\n",al.curso);
  printf("Coeficiente de Rendimento: %.2f\n",al.coeficienteRendimento);
  if( al.pibic)  {
    printf("É aluno de pibic\n"); 
  }
  else {
    printf("Não é aluno de pibic\n");
  }
}



float mediaCoeficiente(tipoLista *pLista) {
  tipoNo *aux;
  unsigned cont = 0;
  float soma = 0.0;
  aux = pLista->prim;

  while(aux) {
    soma = soma + aux->dado.coeficienteRendimento;
    cont++;
    aux = aux -> prox;
  }
  if(cont) {
    soma = soma/cont;
  }
  return soma;
}


void mostraLista(tipoLista *pLista) {
  tipoNo *aux;

  aux = pLista->prim;

  while(aux) {
    mostraAluno(aux->dado);
    aux = aux -> prox;
  }
}



void insereElementoInicioLista(tipoLista *pLista, tipoAluno *al) {

  tipoNo *aux;
  aux = (tipoNo *) malloc (sizeof(tipoNo) );
  aux->dado = *al;
  aux->prox = pLista->prim;
  if(pLista->prim == NULL) {
    pLista->ult = aux;
  }
  pLista->prim = aux;
  pLista->numElementos++;
}



void insereElementoFinalLista(tipoLista *pLista, tipoAluno *al) {

  tipoNo *aux;
  aux = (tipoNo *) malloc (sizeof(tipoNo) );
  aux->dado = *al;
  aux->prox = NULL;
  if(pLista->ult) {
    pLista->ult->prox = aux;
  }
  else {
    pLista->prim = aux; 
  }
  pLista->ult = aux;
  pLista->numElementos++;
}

/*
w : cria arquivo. Se arquivo já existia, o arquivo é zerado. Só pode escrever
r : abre para leitura. So abre se o aquivo já existe.
r+: leitura e escrita (so abre se ja existe)
w+: leitura e escrita, mas cria o arquivo e zera se ja existe
a: apenas para adicionar informacao
*/



void gravaVetorEmBinario(char *nomeArquivo, tipoAluno *vet, unsigned tamanho) {
  FILE *fp;

  fp = fopen(nomeArquivo,"w");
  if(fp == NULL) {
    printf("não foi possivel criar o arquivo %s\n",nomeArquivo);
    exit(1);
  }
  fwrite(vet, sizeof(tipoAluno), tamanho, fp);
}

tipoAluno * carregaVetorEmBinario(char *nomeArquivo) {
  FILE *fp;
  tipoAluno *tmp;
  unsigned long tamanho, numRegistros;
  fp = fopen(nomeArquivo,"r");
  if(fp == NULL) {
    printf("não foi possivel abrir o arquivo %s\n",nomeArquivo);
    exit(1);
  }
  tamanho = tamanhoArquivo(fp);

  tmp = (tipoAluno*) malloc(tamanho);
  numRegistros = tamanho/sizeof(tipoAluno);
  fread(tmp, sizeof(tipoAluno), numRegistros, fp);
  return tmp;
}


int buscarBinariaPorId(FILE *fp, unsigned chave, tipoAluno *al) {
   long int inicio,fim, meio;
   inicio = 0;
   fim = (tamanhoArquivo(fp)/sizeof(tipoAluno))-1;
   while( inicio <= fim ) {
     meio = (inicio+ fim) /2;
     fseek(fp,meio *sizeof(tipoAluno), SEEK_SET);
     fread(al, sizeof(tipoAluno) , 1,fp);
     if(  chave > al->id ) { inicio = meio+1;  }
    else {
      if( chave < al->id ) {	fim = meio-1;      }
      else {	return 1;      }
    }
  }
    return 0;
}


int buscarBinariaPorIdVetor(tipoAluno *vet, 
		       unsigned numElementos,
		       unsigned chave, 
		       tipoAluno *al) {
   long int inicio,fim, meio;
   inicio = 0;
   fim = numElementos-1;
   while( inicio <= fim ) {
     meio = (inicio+ fim) /2;
     if(  chave > vet[meio].id ) { inicio = meio+1;  }
    else {
      if( chave <  vet[meio].id ) {	fim = meio-1;      }
      else {  *al = vet[meio];	return 1;      }
    }
  }
    return 0;
}




int main() {
  tipoAluno al;
  FILE *fp;
  unsigned id=0;

  fp = fopen("ArquivoALunos","r");
  if(fp == NULL) {
    exit(1);
  }
  
  while(id != 1000000000) {
    printf("entre com um id:");
    scanf("%u%*c",&id);
    if(buscarBinariaPorId(fp,id,&al)) {
      printf("Encontrado:\n");
      mostraAluno(al);
    }
    else {
      printf("registro não encontrado no arquivo\n");
    }

  }


  fclose(fp);
}

