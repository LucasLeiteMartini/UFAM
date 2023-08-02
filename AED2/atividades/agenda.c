#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listase.h"


typedef struct tipoEvento{
    char data[11];
    char hora[6];
    char descricao[141];
}tipoEvento;

int comparar_evento(void* m1, void* m2){
    
}

void imprimir_lse(void* elem){
    tipoEvento* aux = elem;

    printf("%s", aux->data);
    printf("%s", aux->hora);
    printf("%s", aux->descricao);

}

