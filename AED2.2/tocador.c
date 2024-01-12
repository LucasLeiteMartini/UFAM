#include "stdio.h"
#include "stdlib.h"
#include "listase.h"


typedef struct musica{
    char nome[60];
    int duracao;
    char genero[30];
}t_musica;

void imprimir_musica()