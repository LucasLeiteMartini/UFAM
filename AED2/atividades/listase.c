#include <stdio.h>
#include <stdlib.h>
#include "listase.h"

typedef struct elem_se{
    void* carga_util;
    struct elem_se* prox;
}t_elemmento_lse;

t_elemmento_lse* criar_elemento(void* carga_util){
    t_elemmento_lse* novo = (t_elemmento_lse*) malloc(sizeof(t_elemmento_lse));
    novo->carga_util = carga_util;
    novo->prox = NULL;

    printf("Criando %p, %p, %p\n", novo, novo->carga_util, novo->prox);
    
    return novo;
}

typedef struct t_lse{
    t_elemmento_lse* inicio;
    t_elemmento_lse* fim;
    int tamanho;
    //operacoes
    t_imprimir_lse imprimir;
    t_comparar_lse comparar;
}t_lse;

t_lse* criaLista(t_imprimir_lse imprimir, t_comparar_lse comparar){
    t_lse *l = (t_lse*) malloc(sizeof(t_lse));

    l->inicio = l->fim = NULL;
    l->tamanho = 0;
    l->imprimir = imprimir;
    l->comparar = comparar;

    return l;
}

void insererir_lse(t_lse *lse, void* carga_util){
    t_elemmento_lse* novo = criar_elemento(carga_util);
    
    if(!lse->inicio){
        lse->inicio = lse->fim = novo;
    }else{
        novo->prox = lse->inicio;
        lse->inicio = novo;
    }
    lse->tamanho++;
}

void* remover_lse(t_lse *lse){
    void* carga_util = NULL;
    t_elemmento_lse *removivel = lse->inicio;
    
    if(lse->inicio){
        carga_util = removivel->carga_util;
        lse->inicio = removivel->prox;
        free(removivel);
        lse->tamanho --;
    }
    return carga_util;
}

void* acessar_lse(t_lse *lse, int pos){
    void* carga_util = NULL;
    pos = pos%lse->tamanho;
    t_elemmento_lse *cam = lse->inicio;
    if(lse->inicio){
        int i = 1;
        while(i<pos){
            cam = cam->prox;
            i++;
        }
        carga_util = cam->prox;
    }
    return carga_util;
}

void imprimir_lse(t_lse *lse){
    t_elemmento_lse *cam = lse->inicio;
    while(cam){
        lse->imprimir(cam->carga_util);
        cam = cam->prox;
    }
}

int main(){
    return 0;
}