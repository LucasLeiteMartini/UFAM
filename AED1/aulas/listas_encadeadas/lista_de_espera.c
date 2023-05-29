#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tipoPaciente{
    char nome[40];
    int idade;

}tipoPaciente;

typedef struct tipoNo{
    tipoPaciente dado;
    struct tipoNo *prox;
}tipoNo;

typedef struct tipoLista{
    tipoNo *prim;
    tipoNo *ult;
}tipoLista;

void criaLista(tipoLista *l){
    l->prim = NULL;
    l->ult = NULL;
}

int verifica(tipoLista *l){

    if(l->prim == NULL){
        return 1;
    }

    return 0;
}

void insereNaFila(tipoLista *l, tipoPaciente paciente){
    tipoNo *aux;
    
    aux = (tipoNo*) malloc(sizeof(tipoNo));

    aux->dado = paciente;
    aux->prox = NULL;
    if(!l->prim){
        l->prim = aux;
        l->ult = aux;
    }else{
        l->ult->prox = aux;
    }
        l->ult = aux;

}

void removeFila(tipoLista *l){
    tipoNo *aux;

    aux = l->prim;
    l->prim = aux->prox;
    free(aux);

    if(l->prim){
        l->ult = NULL;
    }
    free(aux);
}

int mostraPosicao(tipoLista *l, char chave[]){
    tipoNo *aux;
    int count = 0;

    aux = l->prim;

    while(aux){
        if(strcmp(aux->dado.nome, chave)!=0){
            count++;
            aux = aux->prox;
        }
    }
    return count;

}