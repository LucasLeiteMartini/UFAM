#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoEvento{
    char data[11];
    char hora[6];
    char descricao[141];
    int prioridade;
}tipoEvento;