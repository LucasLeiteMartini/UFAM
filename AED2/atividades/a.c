#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoEvento{
    char data[11];
    char hora[6];
    char descricao[141];
    int prioridade;
}tipoEvento;

typedef struct tipoNo{
    tipoEvento evento;
    struct tipoNo *prox;
}tipoNo;

typedef struct tipoAgenda{
    tipoNo *prim;
}tipoAgenda;

void criaAgenda(tipoAgenda *a){
    a->prim = NULL;
}

void adicionaEvento(tipoAgenda *a, tipoEvento evento){
    tipoNo *aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));

    aux->evento = evento;
    aux->prox = a->prim;
    a->prim = aux;

}

int main(){

    


    return 0;
}