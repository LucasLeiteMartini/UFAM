#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct tipoJogador{
    char nome[40];
    unsigned pontuacao;
}tipoJogador;

typedef struct tipoNo{
    tipoJogador dado;
    struct tipoNo *prox;
}tipoNo;

typedef struct tipoListaCircular{
    tipoNo  *atual;
}tipoListaCircular;

void criaListaCircular(tipoListaCircular *l){
    l->atual = NULL;
}

void insereNaListaCircular(tipoListaCircular *l, tipoJogador dado){
    tipoNo *aux;

    aux = (tipoNo*)malloc(sizeof(tipoNo));
    aux->dado = dado;
    if(!l->atual){
        l->atual = aux;
        aux->prox = aux;
    }else{
        aux->prox = l->atual->prox;
        l->atual->prox = aux;
    }

}

void moveParaOProximo(tipoListaCircular *l){
    l->atual = l->atual->prox;
}

void mostraListaCircular(tipoListaCircular *l){
    tipoNo *aux;
    aux = l->atual;
    do{
        printf("%s \n",aux->dado.nome);
        printf("%u \n",aux->dado.pontuacao);
        aux = aux->prox;
    }while(aux != l->atual);
}

int mostraPosicao(tipoListaCircular *l, char *chave){
    tipoNo *aux;
    int cont = 1;
    aux = l->atual;
    if(aux){
        do{
            if(strcmp(aux->dado.nome, chave) == 0){
                return cont;
            }
        }while(aux != l->atual);
    }
    return 0;
}

tipoJogador *obtemJogadorAtual(tipoListaCircular *l) {
  if(l->atual) {
  return &(l->atual->dado);
  }
  return NULL;
}

tipoJogador *ultimoDaRodada(tipoListaCircular *l){
    tipoNo *aux;
    aux = l->atual;
    if(aux){
        while(aux->prox != l->atual){
            aux = aux->prox;
        }
        return &(aux->dado);
    }
    return NULL;
}

int geraNumAleatorio(){
    return rand()%11;
}

int main(){
    tipoListaCircular l1;
    int x;
    tipoJogador tmp;
    criaListaCircular(&l1);

    srand(time(NULL));

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
}