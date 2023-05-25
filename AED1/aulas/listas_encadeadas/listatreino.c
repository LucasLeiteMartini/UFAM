#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoPessoa{
    char nome[30];
    char endereco[20];
    float altura;
}tipoPessoa;

typedef struct tipoNo{
    tipoPessoa dado;
    struct tipoNo *prox;
}tipoNo;

typedef struct tipoLista{
    tipoNo *prim;
}tipoLista;

void questao01(tipoLista *l, float chave){
    tipoNo *aux;
    tipoNo *tmp;
    tmp = (tipoNo*) malloc(sizeof(tipoNo));
    aux = l->prim;
    tmp = aux;

    while(aux){
        if(aux->dado.altura == chave){
            free(tmp);
        }
        aux = aux->prox;
        tmp = aux;
    }

}

void questao02(tipoLista *l){
    tipoNo *aux;

    aux = l->prim->prox;

    while(aux){
        printf("%.2f", aux->dado.altura);
    }
}

void questao03(tipoLista *l, int tam){
    tipoNo *aux;
    int tamAux = tam;
    aux = l->prim;

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tamAux; j++){
            if(j == tamAux){
                printf("%.2f", aux->dado.altura);
            }
            aux = aux->prox;
            tamAux--;
        }
    }
}