#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

bool lista_vizinhos_adicionar(int vizinho, lista_vizinhos_t** lista) {
    lista_vizinhos_t* novo_vizinho = malloc(sizeof(lista_vizinhos_t));
    if (!novo_vizinho) return false;
    
    novo_vizinho->vizinho = vizinho;
    novo_vizinho->prox = *lista;
    *lista = novo_vizinho;
    return true;
}

void lista_vizinhos_imprimir(lista_vizinhos_t* lista) {
    lista_vizinhos_t* cam = lista;
    while (cam != NULL) {
        printf("%d ", cam->vizinho);
        cam = cam->prox;
    }
}

grafo_t grafo_criar(int tam) {
    grafo_t grafo = malloc(tam * sizeof(no_t));
    
    for (int i = 0; i < tam; i++) {
        grafo[i].vizinhos = NULL;
    }
    
    return grafo;
}

void grafo_imprimir(int tam, grafo_t grafo) {
    for (int i = 0; i < tam; i++) {
        printf("NÓ %d: ", grafo[i].id);
        lista_vizinhos_imprimir(grafo[i].vizinhos);
        printf("\n");
    }
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

int main(int argc, char** argv) {
    int tam = 10;
    double raio_comunicacao = 20.0;
    
    grafo_t grafo = grafo_criar(tam);
    
    FILE* f = fopen(argv[1], "r");
    int i = 0;

    fscanf(f, "%d\t%lf\n", &tam, &raio_comunicacao);

    while(!feof(f)){
        fscanf(f, "%d\t%lf\t%lf\n", &grafo[i].id, &grafo[i].x, &grafo[i].y);
        i++;
    }

    grafo_atualizar_vizinhos(tam, raio_comunicacao, grafo);
    grafo_imprimir(tam, grafo);
    
    // Liberar memória alocada
    for (int i = 0; i < tam; i++) {
        lista_vizinhos_t* atual = grafo[i].vizinhos;
        while (atual != NULL) {
            lista_vizinhos_t* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    
    free(grafo);
    
    return 0;
}