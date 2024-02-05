#include "stdio.h"
#include "stdlib.h"
#include "fila.h"


typedef struct musica{

    char nome[60];
    char genero[60];
    int duracao;

}t_musica;

criar_fila_reproducao();
adicionar_fila_reproducao();
avancar_fila_reproducao(int k);
retroceder_fila_reproducao(int k);
pausar_fila_reproducao();
reproduzir_fila_reproducao();