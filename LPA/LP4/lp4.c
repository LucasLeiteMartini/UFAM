#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct evento_t{
    double tempo;
    int alvo;
    int tipo;
}evento_t;

typedef struct lista_eventos_t{
    evento_t* evento;
    struct lista_eventos_t* prox;
}lista_eventos_t;


typedef struct lista_vizinhos_t {
    int vizinho;
    struct lista_vizinhos_t* prox;
} lista_vizinhos_t;

typedef struct no_t {
    int id;
    double x;
    double y;
    lista_vizinhos_t* vizinhos;
} no_t;

typedef no_t* grafo_t;

bool lista_eventos_adicionar_ordenado(evento_t *evento, lista_eventos_t **lista){
    lista_eventos_t* item_novo = malloc(sizeof(lista_eventos_t));
    item_novo->evento = evento;
    item_novo->prox = NULL;

    if(!*lista){
        *lista = item_novo;
        return true;
    }

    lista_eventos_t* item_atual = *lista;

    if(evento->tempo < item_atual->evento->tempo){
        item_novo->prox = item_atual;
        *lista = item_novo;
    }else{
        while(item_atual->prox != NULL && item_atual->prox->evento->tempo < evento->tempo){
            item_atual = item_atual->prox;
        }
        item_novo->prox = item_atual->prox;
        item_atual->prox = item_novo;
    }

}

bool lista_vizinhos_adicionar(int vizinho, lista_vizinhos_t** lista) {
    lista_vizinhos_t* novo_vizinho = malloc(sizeof(lista_vizinhos_t));
    if (!novo_vizinho) return false;
    
    novo_vizinho->vizinho = vizinho;
    novo_vizinho->prox = *lista;
    *lista = novo_vizinho;
    return true;
}


grafo_t grafo_criar(int tam) {
    grafo_t grafo = malloc(tam * sizeof(no_t));
    
    for (int i = 0; i < tam; i++) {
        grafo[i].vizinhos = NULL;
    }
    
    return grafo;
}

void grafo_atualizar_vizinhos(int tam, double raio_comunicacao, grafo_t grafo) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (i != j) {
                double distancia = sqrt(pow(grafo[i].x - grafo[j].x, 2) + pow(grafo[i].y - grafo[j].y, 2));
                if (distancia <= raio_comunicacao) {
                    lista_vizinhos_adicionar(grafo[j].id, &grafo[i].vizinhos);
                }
            }
        }
    }
}
