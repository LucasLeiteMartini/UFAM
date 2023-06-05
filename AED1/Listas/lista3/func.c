#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
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

    tipoNo *aux,*tmp;

    if(l->prim->dado.altura == chave){
        tmp = l->prim;
        l->prim = tmp->prox;
        free(tmp);
    }else{
        aux = l->prim;
        while(aux->prox && aux->prox->dado.altura != chave){
            aux = aux->prox; 
            
        }
        
        tmp = aux->prox;
        aux->prox = tmp->prox;
        free(tmp);

    }
}

void criaLista(tipoLista *l){
    l->prim = NULL;
}

void insereNaLista(tipoLista *l, tipoPessoa dado){
    tipoNo *aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->dado = dado;
    aux->prox = l->prim;
    l->prim = aux;

}

void mostraLista(tipoLista *l){
    tipoNo *aux;

    aux = l->prim;
    
    while(aux){
        printf("%s\n",aux->dado.nome);
        printf("%s\n", aux->dado.endereco);
        printf("%.2f\n", aux->dado.altura);
        printf("\n");
        aux = aux->prox;
    }
}

int main(){

    tipoLista l1;

    tipoPessoa p1 = {"kaike","rua7",1.87};
    tipoPessoa p2 = {"martini","rua77",2.50};
    tipoPessoa p3 = {"dridrigo","rua777",1.65};
    tipoPessoa p4 = {"jhon","rua7777",1.38};

    criaLista(&l1);

    insereNaLista(&l1,p1);
    insereNaLista(&l1,p2);
    insereNaLista(&l1,p3);
    insereNaLista(&l1,p4);

    printf("Antes da mudanca\n");
    printf("\n");
    
    mostraLista(&l1);

    questao01(&l1, 2.50);

    printf("Depois da mudanca\n");
    printf("\n");
    mostraLista(&l1);

    return 0;
}