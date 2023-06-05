#include <stdio.h>
#include <stdlib.h>


typedef struct tipoCompra{
    char nome[40];
    float preco;
}tipoCompra;

typedef struct tipoNo{
    tipoCompra dado;
    struct tipoNo *prox;
}tipoNo;

typedef struct tipoLista{
    tipoNo *prim;
}tipoLista;

void criaLista(tipoLista *l){
    l->prim = NULL;
}

void insereNaLista(tipoLista *l, tipoCompra dado){
    tipoNo *aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));

    aux->dado = dado;
    aux->prox = l->prim;
    l->prim = aux;

}

void mostraLista(tipoLista *l){

    tipoNo *aux;

    aux = l->prim;

    printf("Sua lista de compras:\n\n");
    while(aux){

        printf("%s\n", aux->dado.nome);
        printf("%.2f\n", aux->dado.preco);
        printf("\n\n");

        aux = aux->prox;

    }
}

float valorTotal(tipoLista *l){
    tipoNo *aux;

    float total = 0.0;

    aux = l->prim;

    while(aux){

        total += aux->dado.preco;
        aux = aux->prox;

    }
    return total;
}

int main(){
    tipoLista l1;

    criaLista(&l1);

    tipoCompra c1 = {"jambu",25.0};
    tipoCompra c2 = {"alface",55};
    tipoCompra c3 = {"leite",16.5};

    insereNaLista(&l1,c1);
    insereNaLista(&l1,c2);
    insereNaLista(&l1,c3);

    mostraLista(&l1);

    printf("Seu total é: %.2f\n", valorTotal(&l1));

}