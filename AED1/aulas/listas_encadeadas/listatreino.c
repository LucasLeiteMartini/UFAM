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

    if(l->prim){
        if(l->prim->dado.altura == chave){
            aux = l->prim;
            l->prim = aux->prox;
            free(aux);
        }else{
            aux = l->prim;
            while(aux->prox){
                if(aux->prox != NULL && aux->prox->dado.altura != chave) aux = aux->prox;
            }
            if(aux->prox){
            tmp = aux->prox;
            aux->prox = tmp->prox;
            free(tmp);
            }
        }
    }    

}

void questao02(tipoLista *l){
    tipoNo *aux;

    aux = l->prim->prox;

    while(aux){
        printf("%.2f", aux->dado.altura);
        aux = aux->prox->prox;
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

void criaLista(tipoLista *l){
    l->prim = NULL;
}

void insereNaLista(tipoLista *l, tipoPessoa info){

    tipoNo *aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));
    aux->dado= info;
    aux -> prox = l->prim;
    l->prim = aux;
}

void mostraLista(tipoLista *l){
    tipoNo *aux;

    aux = l->prim;

    while(aux){
        printf("%s\n", aux->dado.nome);
        printf("%s\n", aux->dado.endereco);
        printf("%.2f\n", aux->dado.altura);
        printf("\n");
        aux = aux->prox;
    }

}

int main(){
    tipoLista l1;

    criaLista(&l1);

    tipoPessoa p1 = {"carlos","rua12",1.89};
    tipoPessoa p2 = {"lucas","rua432",1.75};
    tipoPessoa p3 = {"maria","rua553",1.55};
    tipoPessoa p4 = {"roberto","rua7",1.94};

    insereNaLista(&l1,p1);
    insereNaLista(&l1,p2);
    insereNaLista(&l1,p3);
    insereNaLista(&l1,p4);

    questao01(&l1,1.74);

    mostraLista(&l1);

}