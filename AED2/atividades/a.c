#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoEvento{
    char data[11];
    char hora[6];
    char descricao[141];
    int prioridade;
}tipoEvento;

typedef struct tipoNo{
    tipoEvento evento;
    struct tipoNo *prox;
}tipoNo;

typedef struct tipoAgenda{
    tipoNo *prim;
}tipoAgenda;

void criaAgenda(tipoAgenda *l){
    l->prim = NULL;
}

void adicionaEvento(tipoAgenda *l, tipoEvento evento){
    tipoNo *aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));

    aux->evento = evento;
    aux->prox = l->prim;
    l->prim = aux;

}

void mostraEventos(tipoAgenda *l){
    tipoNo *aux;

    aux = l->prim;
}

int main(){

    char resposta;
    int flag = 1;
    tipoEvento evento;
    tipoAgenda agenda;

    // Início da interface

    printf("Olá usuário! Sua Agenda de Eventos está vazia, gostaria de adicionar eventos futuros?\n");
    scanf("%c \n", &resposta);

    if(resposta == 's'){
        criaAgenda(&agenda);
        while(flag){
        printf("Perfeito, preencha os dados a seguir sobre o seu evento: ");
        printf("A data no formato xx/xx/xxxx: ");
        scanf("%[^\n]%*c", evento.data);
        printf("A hora no formato xx:xx: ");
        scanf("%[\n]%*c", evento.hora);
        printf("E por fim, uma breve descrição do evento: ");
        scanf("%[^\n]%*c", evento.descricao);
        adicionaEvento(&agenda, evento);
        printf("Evento adicionado com sucesso! Gostaria de adicionar outros?");
        scanf("%c%*c", &resposta);
        if(resposta == 'n'){
            flag = 0;
        }
        }
    }

    return 0;
}