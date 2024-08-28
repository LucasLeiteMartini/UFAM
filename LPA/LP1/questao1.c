#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

#define ERRO_ARQUIVO_OPEN 5
#define ERRO_POUCOS_ARGUMENTOS 7

typedef struct evento_t{
    double tempo;
    int alvo;
    int tipo;
}evento_t;

typedef struct lista_eventos_t{
    evento_t* evento;
    struct lista_eventos_t* prox;
}lista_eventos_t;

void imprimir_eventos(evento_t* evento){
    printf("%.6f\t%d\t%d\n", evento->tempo, evento->alvo, evento->tipo);
}

evento_t* criar_evento(double tempo, int alvo, int tipo){
    evento_t* novo_evento = malloc(sizeof(evento_t));
    novo_evento->tempo = tempo;
    novo_evento->alvo = alvo;
    novo_evento->tipo = tipo;

    return novo_evento;
}

bool lista_eventos_adicionar_inicio(evento_t* evento, lista_eventos_t** lista){
    lista_eventos_t *item_novo = malloc(sizeof(lista_eventos_t));
    if (item_novo == NULL) return false; // Falta memória?
    item_novo->evento = evento; // Seta o novo item
    item_novo->prox = *lista; // O próximo do novo item será a lista
    *lista = item_novo; // Aqui, estamos mudando o ponteiro da lista
    return true;    
}

void lista_eventos_listar(lista_eventos_t* lista){
    lista_eventos_t* cam = lista;
    
    while(cam->prox != NULL){
        imprimir_eventos(cam->evento);
        cam = cam->prox;
    }
}

int main(int argc, char **argv){

    if(argc != 2){
        return ERRO_POUCOS_ARGUMENTOS;
    }

    FILE *arquivo = fopen(argv[1],"r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return ERRO_ARQUIVO_OPEN;
    }

    double tempo; 
    int alvo, tipo;
    evento_t* novo;
    lista_eventos_t* lista;

    while(!feof(arquivo)){
        fscanf(arquivo, "%lf\t%d\t%d\n", &tempo, &alvo, &tipo);
        novo = criar_evento(tempo, alvo, tipo);
        lista_eventos_adicionar_inicio(novo, &lista);
    }

    lista_eventos_listar(lista);

    return 0;
}