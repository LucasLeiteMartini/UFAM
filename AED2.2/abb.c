#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "abb.h"

typedef struct no t_no;
struct no{
    void* info;
    t_no *sae;
    t_no *sad;
    t_no *ancestral;
};

t_no* criar_no(void* info, t_no* ancestral){
    t_no* novo = malloc(sizeof(t_no));

    novo->info = info;
    novo->ancestral = ancestral;
    novo->sad = NULL;
    novo->sae = NULL;

    return novo;
}

struct abb{
    t_no* raiz;
    int tamanho;
    
    t_imprimir_abb impressora;
    t_comparar_abb comparar;
};

t_abb* criar_abb(t_imprimir_abb impressora, t_comparar_abb comparar){
    t_abb* nova = malloc(sizeof(t_abb));
    nova->raiz = NULL;
    nova->tamanho=0;
    nova->impressora = impressora;
    nova->comparar = comparar;

    return nova;
}

static t_no* _inserir_abb(t_no* raiz, t_no* ancestral, void* info, t_comparar_abb comparar){
    if (raiz == NULL){
        return criar_no(info, ancestral);
    }else{
        int k = comparar(raiz->info, info);
        if (k >= 0){ // inserir esquerda
            
            raiz->sae = _inserir_abb(raiz->sae,raiz, info, comparar);
        }else{
            
            raiz->sad = _inserir_abb(raiz->sad, raiz, info, comparar);
        }
        return raiz;
    }
}

void inserir_abb(t_abb *abb, void* info){

    abb->raiz = _inserir_abb(abb->raiz, NULL, info, abb->comparar);
    abb->tamanho++;

}

void _mostrar_abb(t_no* no, t_imprimir_abb impressora){
    if (no == NULL){
        return;
    }
    _mostrar_abb(no->sae, impressora);
    printf("no: %p sae:%p sad:%p\n", no, no->sae, no->sad);
    impressora(no->info);
    _mostrar_abb(no->sad, impressora);
}

void mostrar_abb(t_abb* abb){
    _mostrar_abb(abb->raiz, abb->impressora);
}

#define max(a,b) (a>b?a:b)
static int _altura_abb(t_no* raiz){
    if (raiz == NULL){
        return -1;
    }else{
        return max(_altura_abb(raiz->sae), _altura_abb(raiz->sad)) + 1;
    }
}

int altura_abb(t_abb* abb){
    return _altura_abb(abb->raiz);
}

int _vazia_abb(t_no* raiz){
     return (raiz == NULL);
}

int vazia_abb(t_abb* abb){
    return ((abb!=NULL) && _vazia_abb(abb->raiz));
}

int tamanho_abb(t_abb* abb){
    return abb->tamanho;
}