#include "stdlib.h"
#include "vetordinamico.h"
#include "diciodinamico.h"
#include "listase.h"

struct dicio_dinamico{
    t_vd* vd;
    int fator_carga;
    int tamanho;
    t_comparar_dd comparar;
};

typedef int(*t_comparar_dd)(void*, void*);
typedef struct colisao{
    int chave;
    void* carga;
}t_colisao;


t_colisao* criar_colisao(int chave, void* carga){
    t_colisao* c = malloc(sizeof(t_colisao));
    c->chave = chave;
    c->carga = carga;

    return c;
}

int comparar_colisao(void* c1, void* c2){
    t_colisao* cc1 = c1;
    t_colisao* cc2 = c2;

    return cc1->chave - cc2->chave;
}

static int funcao_hashing(t_dd *dd , int chave){
    return chave % dd->tamanho;
}

int primo_perto(int n){
    if(n%2 == 0){return n++;}
    else if((n%3 == 0) || (n%5 == 0) || (n%7 == 0)){return n+2;}
    else{return n;} 
}


t_dd* criar_dd(int fator_carga, int tam){
    t_dd* dd = malloc(sizeof(t_dd));
    dd->tamanho = primo_perto(tam);
    
    dd->vd = criar_vd();
    for(int i=0;i<dd->tamanho;i++){
        t_lse* lse = criar_lse(NULL, comparar_colisao);
        inserir_vd(dd->vd, lse);
    }
    dd->fator_carga = fator_carga;
    dd->comparar = comparar_colisao;

    return dd;    
};


int inserir_dd(t_dd *dd, int chave, void*carga){
    int k = funcao_hashing(dd, chave);
    t_lse* colisoes = acessar_vd(dd->vd, k);
    t_colisao* colisao = buscar_lse(colisoes, (void*) &chave);
    if (colisao == NULL){
        inserir_lse(colisoes,criar_colisao(chave, carga));
        return 1;
    }
    return 0;
}

void* consultar_dd(t_dd *dd, int chave){

    int k = funcao_hashing(dd, chave);
    t_lse* colisoes = acessar_vd(dd->vd, k);
    t_colisao* colisao = buscar_lse(colisoes, (void*) &chave);
    if (colisao != NULL){
        return colisao->carga;
    }
    return NULL;
}

void* remover_dd(t_dd *dd, int chave){
    int k = funcao_hashing(dd, chave);
    t_lse* colisoes = acessar_vd(dd->vd, k);
    t_colisao* colisao = remover_procurado_lse(colisoes, (void*) &chave);
    void* carga = NULL;
    if (colisao != NULL){
        carga = colisao->carga;
        free(colisao);
    }
    return carga;
}

