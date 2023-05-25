#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo{

    int dado;
    struct tipoNo *prox;

}tipoNo;

typedef struct tipoLista{
    
    tipoNo *prim;
    unsigned numElem;

}tipoLista;

/* Cria uma lista encadeada vazia
    para que você possa chamar a função, deve passar o endereço de uma variavel do tipo lista*/

void criaLista(tipoLista *l){
    l->prim = NULL;
    l->numElem = 0;
}

void inserirElemNaLista(tipoLista *l, int valor){
    
    tipoNo *aux;
    
    l->numElem++;
    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->dado = valor;
    aux->prox = l->prim;
    l->prim = aux;
}

void mostrarLista(tipoLista *l){
    tipoNo *aux;

    aux = l->prim;

    while(aux){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int busacNaLista(tipoLista *l, int chave){
    tipoNo *aux;

    aux = l->prim;
    while(aux){
        if(aux->dado == chave) return 1;
        aux = aux->prox;
    }
    return 0;
}

int main(){
    tipoLista l1,l2;
    tipoLista *p;
    tipoLista *pp;
    p = &l1;
    pp = &l2;
    criaLista(p);
    criaLista(pp);
    inserirElemNaLista(p,5);
    inserirElemNaLista(p,7);
    inserirElemNaLista(p,4);
    mostrarLista(p);
}