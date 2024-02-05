#include "stdio.h"
#include "stdlib.h"
#include "listase.h"
#include "fila.h"

typedef struct fila{
    t_lse* elementos;
    int tamanho;
}t_fila;

t_fila* criar_fila(){
    t_fila* f = malloc(sizeof(t_fila));
    f->tamanho = 0;
    f->elementos = criar_lse(NULL,NULL);
    return f;
}
void enfileirar(t_fila* f, void* elem){
    if (f){
        f->tamanho++;
        inserir_final_lse(f->elementos, elem);
    }
}

void* desenfileirar(t_fila* f){
    void* elem = NULL;
    if (f && (f->tamanho>0)){
        elem = remover_lse(f->elementos);
        f->tamanho--;
    }
    return elem;
}

int tamanho_fila(t_fila* f){
    return f->tamanho;
}

void* acessar_fila(t_fila* f, int pos){
    void* elem = acessar_lse(f->elementos, pos);

    return elem;

}

void* primeiro_fila(t_fila* f){
	void* carga = NULL;

    if(f && (f->tamanho > 0)){
        carga = acessar_lse(f->elementos, 1);
    }    

    return carga;
}
