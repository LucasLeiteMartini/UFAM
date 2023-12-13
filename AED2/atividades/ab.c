#include "time.h" 
#include "stdio.h"
#include "stdlib.h"
#include "ab.h"

typedef struct no t_no;
struct no{
    void* info;
    t_no* ancestral;
    t_no* sae;
    t_no* sad;
};

static t_no* criar_no(void* info, t_no* ancestral){
    t_no* novo = malloc(sizeof(t_no));
    novo->info = info;
    novo->sad = NULL;
    novo->sae = NULL;
    novo->ancestral = ancestral;

    return novo;
}

struct abb{
    t_no* raiz;
    int tamanho;
    t_comparar_abb comparar;
    t_destruir_abb destruir;
};

typedef struct abb t_abb;
typedef int(*t_comparar_abb)(void*, void*);
typedef void(*t_destruir_abb)(void* info);

t_abb* criar_abb(t_comparar_abb comparar){
    t_abb *abb = malloc(sizeof(t_abb));
    abb->raiz = NULL;
    abb->tamanho = 0;
    abb->comparar = comparar;
    return abb;
}

#define MAX(a,b) (a>b?a:b)
static int _altura_abb(t_no* raiz){
    if (raiz != NULL){
        return MAX(_altura_abb(raiz->sae), _altura_abb(raiz->sad)) + 1;
    }else{
        return -1;
    }
}

int altura_abb(t_abb *abb){

    return _altura_abb(abb->raiz);
}

static int _tamanho_abb(t_no* no){
    if (no == NULL)
        return 0;
    return _tamanho_abb(no->sae) + _tamanho_abb(no->sad) + 1;
}

int tamanho_abb(t_abb *abb){
    return abb->tamanho;
}

void* _buscar_abb(t_no* raiz, t_comparar_abb comparar, void* chave){
    if(raiz == NULL){
        return NULL;
    }
    int status = comparar(raiz->info, chave);
    if(status == 0){
        return raiz->info;
    }
    else if(status >0){
        return _buscar_abb(raiz->sae, comparar, chave);
    }
    else{
        return _buscar_abb(raiz->sad, comparar, chave);
    }
}

void* buscar_abb(t_abb *abb, void* chave){
    return _buscar_abb(abb->raiz, abb->comparar, chave);
}

static int sorteio(){
    static int primeira_vez = 1;
    if (primeira_vez){
        primeira_vez = 0;
        srand(time(NULL));
    }
    return (rand() % 2); // gera o valor entre [0,1]
}

static t_no* _inserir_abb(t_no* raiz, t_no* ancestral, void* info, t_comparar_abb comparar){
    if (raiz == NULL){
        return criar_no(info, ancestral);
    }else{
        int status = comparar(raiz->info, info);
        if (status > 0){ // inserir SAE 
            raiz->sae = _inserir_abb(raiz->sae, raiz, info, comparar);
        }else if(status < 0){ // SAD
            raiz->sad = _inserir_abb(raiz->sad, raiz, info, comparar);
        }
        return raiz;
    }
}

void inserir_abb(t_abb *abb, void* info){
    abb->raiz = _inserir_abb(abb->raiz,NULL,info, abb->comparar);
    abb->tamanho++;
}

t_no* _podar_abb(t_no *raiz, int *tamanho, t_destruir_abb destruir){
    if(raiz==NULL){
        return;
    }
    _podar_abb(raiz->sae, tamanho, destruir);
    _podar_abb(raiz->sad, tamanho, destruir);
    destruir(raiz->info);
    free(raiz);
    *tamanho = *tamanho-1;
    return NULL;
}

void podar_abb(t_abb *abb, void* podavel){
    t_no* raiz = _buscar_abb(abb->raiz,abb->comparar, podavel);
    if(raiz->ancestral != NULL){
        if (raiz->ancestral->sad == raiz){
            raiz->ancestral->sad = NULL;
        }else{
            raiz->ancestral->sae = NULL;
        }
    }
//    abb->tamanho -= _tamanho_abb(raiz);
   _podar_abb(raiz, &(abb->tamanho), abb->destruir);

}

void _imprimir_abb(t_no* raiz){
    if (raiz == NULL){
        return;
    }
    _imprimir_abb(raiz->sae);
    _imprimir_abb(raiz->sad);
    printf("%p\n", raiz->info);

}

void imprimir_abb(t_abb *abb){
    _imprimir_abb(abb->raiz);
}

static t_no* _remover_abb(t_no* raiz, t_comparar_abb comparar, t_destruir_abb destruir, void* chave){
    if(raiz == NULL){
        return;
    }
    int status = comparar(raiz->info, chave);
    if(status == 0){
        if((raiz->sad == NULL) && (raiz->sae == NULL)){
            destruir(raiz->info);
            free(raiz);
        }
        else if(raiz->sae == NULL){
            raiz->sad->ancestral = raiz->ancestral;
            t_no* sad = raiz->sad;
            destruir(raiz->info);
            free(raiz);

            return sad;
        }
        else{//tem descendentes sae sad
        }
    }
    else if(status > 0){
       raiz->sae = _remover_abb(raiz->sae, comparar, destruir, chave);
    }
    else if(status < 0){
        raiz->sad = _remover_abb(raiz->sad, comparar, destruir, chave);
    }


}

void remover_abb(t_abb* abb, void* chave){
    _remover_abb(abb->raiz, abb->comparar, abb->destruir, chave);
}
