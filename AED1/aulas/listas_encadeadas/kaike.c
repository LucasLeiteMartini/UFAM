#include <stdio.h>
#include <stdlib.h>


typedef struct tipoCidade{
    char nome[30];
    float pib;
    int pop;
}tipoCidade;

typedef struct tipoNo{
    tipoCidade dado;
    struct tipoNo *prox;
}tipoNo;

typedef struct tipoLista{
    tipoNo *prim;
}tipoLista;


int questao(tipoLista *pl, char chave[]){
    tipoNo *aux, *tmp;
    
    aux = pl->prim;
    if(pl->prim == NULL){
        return NULL;
    }
    else{
        if(strcmp(pl->prim->dado.nome, chave) == 0){
            tmp = pl->prim;
            pl->prim = aux->prox;
            free(tmp);
        }
        else{
            aux = aux->prox;
            while(aux){
                if(strcmp(aux->dado.nome, chave) == 0){
                    tmp = aux->prox;
                    aux ->prox = tmp ->prox;
                    free(tmp);
                }
            }
        }
    }
}