#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listase.h"

typedef struct agenda{
    t_lse* eventos;
    int tamanho;
}t_agenda;

typedef struct evento{
    char descricao[141];
    char tempo[17];
    char prioridade[11];
}t_evento;

t_evento* cria_evento(char descricao[], char tempo[], char prioridade[]){

    t_evento* evento = malloc(sizeof(t_evento));
    strncpy(evento->descricao,descricao,strlen(descricao));
    strncpy(evento->tempo,tempo,strlen(tempo));
    strncpy(evento->prioridade,prioridade,strlen(prioridade));

    return evento;
    
}

t_agenda* criar_agenda(t_imprimir_lse imprime, t_comparar_lse compara){
    
    t_agenda* agenda = malloc(sizeof(t_agenda));
    agenda->tamanho = 0;
    agenda->eventos = criar_lse(imprime, compara);


    return agenda;
}

void agendar_evento(t_agenda* agenda , t_evento* evento){
    inserir_posicao(agenda->eventos, evento);
    agenda->tamanho++;
}

int quantificar_evento(t_agenda* agenda){
    return agenda->tamanho;
}

void proximo_evento(t_agenda* agenda){
    imprime_elem(agenda->eventos);
}

void alterar_evento(t_agenda* agenda, t_evento* chave, t_evento* novo_evento){
    t_evento* e2 = acessar_com_comparacao(agenda->eventos, chave);
    strcpy(e2->tempo, novo_evento->tempo);
    strcpy(e2->descricao, novo_evento->descricao);
    strcpy(e2->prioridade, novo_evento->prioridade);
}

void* cancelar_evento(t_agenda* agenda, t_evento *chave){
    t_evento* aux = remove_elem(agenda->eventos, chave);
    agenda->tamanho--;
    return aux;
}

void imprimir_evento(void* carga){
    t_evento* evento = carga;

    if (evento)
        printf("%s %s %s\n",  evento->tempo,evento->descricao, evento->prioridade);
}
void concluir_evento(t_agenda* agenda){
    remover_inicio_lse(agenda->eventos);
    agenda->tamanho--;
}

t_evento* ler_evento() {
    char tempo[17];
    char descricao[141];
    char prioridade[11];

    int dia, mes, ano, hora, minuto;

    scanf(" %d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &minuto);
    scanf(" %s", descricao);
    scanf(" %s",prioridade);

    snprintf(tempo, sizeof(tempo), "%02d/%02d/%04d %02d:%02d", dia, mes, ano, hora, minuto);

    return cria_evento(descricao, tempo, prioridade);
}



t_evento* ler_chave() {
    char tempo[17];
    int dia, mes, ano, hora, minuto;

    scanf(" %d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &minuto);
    snprintf(tempo, sizeof(tempo), "%02d/%02d/%04d %02d:%02d", dia, mes, ano, hora, minuto);

    return cria_evento("", tempo, "");
}


int compara_eventos(void* e1, void* e2) {
    t_evento* ee1 = e1;
    t_evento* ee2 = e2;
    int prior1, prior2;
    int dia1, dia2, mes1, mes2, ano1, ano2, hora1, hora2, minuto1, minuto2;

    sscanf(ee1->tempo, " %d/%d/%d %d:%d", &dia1, &mes1, &ano1, &hora1, &minuto1);
    sscanf(ee2->tempo, " %d/%d/%d %d:%d", &dia2, &mes2, &ano2, &hora2, &minuto2);

    if (ano1 != ano2) {
        return ano1 - ano2;
    } else if (mes1 != mes2) {
        return mes1 - mes2;
    } else if (dia1 != dia2) {
        return dia1 - dia2;
    } else if (hora1 != hora2) {
        return hora1 - hora2;
    } else if (minuto1 != minuto2) {
        return minuto1 - minuto2;
    } else {
        return 0;
    }
}