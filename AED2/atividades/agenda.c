#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listase.h"

typedef struct agenda{
    t_lse* eventos;
    int tamanho;
}t_agenda;

typedef struct evento{
    char descricao[140];
    char tempo[50];
    char prioridade[10];
}t_evento;

t_elemento_lse* cria_evento(char descricao[], char tempo[], char prioridade[]){

    t_elemento_lse* a;
    t_evento* evento = malloc(sizeof(t_evento));
    strcpy(descricao, evento->descricao);
    strcpy(tempo, evento->tempo);
    strcpy(prioridade, evento->prioridade);

    a = criar_elemento_lse(evento);

    return a;
    
}

void proximo_evento(void* e){
    t_evento *ee = e;
    printf("%s\n%s\n", ee->descricao, ee->tempo);
}

t_agenda* criar_agenda(t_imprimir_lse imprime, t_comparar_lse compara){
    
    t_agenda* agenda = malloc(sizeof(t_agenda));
    agenda->tamanho = 0;
    agenda->eventos = criar_lse(imprime, compara);


    return agenda;
}

void agenda_evento(t_agenda* agenda , t_evento* evento){
    inserir_final_lse(agenda->eventos, evento);
}
/* 
void proximo_evento(t_agenda* agenda){
    t_lse* aux = agenda->eventos;

    printf("%s", evento)


} */

void imprimir_evento(void* carga){
    t_evento* evento = carga;

    printf("%s  %s  %s", evento->descricao, evento->tempo, evento->prioridade);
}

int main(){

    t_agenda* agenda;
    t_evento* evento;
    
    char descricao[40] = {"abacate"};
    char tempo[40] = {"15:25"};
    char prioridade[40] = {"alta"};

    agenda = criar_agenda(NULL,imprimir_evento);
    evento = cria_evento(descricao, tempo, prioridade);

    
    imprimir_evento(evento);
    /* agenda_evento(agenda, evento);

    imprimir_lse(agenda->eventos); */

    return 0;
}