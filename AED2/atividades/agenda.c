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

t_evento* cria_evento(char descricao[], char tempo[], char prioridade[]){

    t_evento* evento = malloc(sizeof(t_evento));
    strcpy(evento->descricao,descricao);
    strcpy(evento->tempo,tempo);
    strcpy(evento->prioridade,prioridade);

    return evento;
    
}

t_agenda* criar_agenda(t_imprimir_lse imprime, t_comparar_lse compara){
    
    t_agenda* agenda = malloc(sizeof(t_agenda));
    agenda->tamanho = 0;
    agenda->eventos = criar_lse(imprime, compara);


    return agenda;
}

void agendar_evento(t_agenda* agenda , t_evento* evento){
    inserir_conteudo_lse(agenda->eventos, evento);
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

    printf("%s  %s  %s\n", evento->descricao, evento->tempo, evento->prioridade);
}
void concluir_evento(t_agenda* agenda){
    remover_lse(agenda->eventos);
    agenda->tamanho--;
}

int compara_eventos(void* e1, void* e2){
    t_evento* ee1 = e1;
    t_evento* ee2 = e2;
    int dia1, dia2, mes1, mes2, ano1, ano2, hora1, hora2, minuto1, minuto2;

    sscanf(ee1->tempo, "%d/%d/%d %d:%d", &dia1, &mes1, &ano1, &hora1, &minuto1);
    sscanf(ee2->tempo, "%d/%d/%d %d:%d", &dia2, &mes2, &ano2, &hora2, &minuto2);
    
    if(ano1 < ano2){
        return -1;
    }else{
        return 1;
    }

    if(mes1 < mes2){
        return -1;
    }else{
        return 1;
    }

    if(dia1 < dia2){
        return -1;
    }else{
        return 1;
    }

    if(hora1 < hora2){
        return -1;
    }else{
        return 1;
    }

    if(minuto1 < minuto2){
        return -1;
    }else{
        return 1;
    }

    if(ee1->prioridade == "alta" && ee2->prioridade != "alta"){
        return -1;
    }else if(ee2->prioridade == "alta" && ee1->prioridade != "alta"){
        return 1;
    }else if(ee1->prioridade == "media" && ee2->prioridade != "media"){
        return -1;
    }else if(ee2->prioridade == "media" && ee1->prioridade != "media"){
        return 1;
    }

    return 0;

}

int main(){

    t_agenda* agenda;
    t_evento* evento;
    t_evento* evento2;
    t_evento* chave;
    t_evento* novo_evento;
    t_evento* teste;

    char descricao[40] = {"abacate"};
    char tempo[40] = {"12/06/2001 15:46"};
    char prioridade[40] = {"alta"};

    char descricao2[40] = {"rodrigo"};
    char tempo2[40] = {"12/06/2001 15:45"};
    char prioridade2[40] = {"baixa"};

    char descricao3[40] = {"jacinto leite norego"};
    char tempo3[40] = {"12/06/1995 15:45"};
    char prioridade3[40] = {"alta"};


    agenda = criar_agenda(imprimir_evento, compara_eventos);

    evento = cria_evento(descricao, tempo, prioridade);   
    chave = cria_evento(descricao, tempo, prioridade);
    evento2 = cria_evento(descricao2, tempo2, prioridade2);
    novo_evento = cria_evento(descricao3, tempo3, prioridade3);


    agendar_evento(agenda, evento);
    agendar_evento(agenda,evento2);

    imprimir_lse(agenda->eventos);

    remove_elem(agenda->eventos, chave);

    printf("\n\n");

    imprimir_lse(agenda->eventos);

/*     printf("%d\n", quantificar_evento(agenda));

    printf("\nProximo evento\n");
    proximo_evento(agenda);

    printf("\nEvento cancelado\n");

    teste = cancelar_evento(agenda, chave);
    imprimir_evento(teste);

    printf("\nSua agenda atual\n");
    imprimir_lse(agenda->eventos);

    alterar_evento(agenda, chave, novo_evento);
    printf("\nEvento alterado\n");
    imprimir_lse(agenda->eventos);


    concluir_evento(agenda);
    printf("\neventos atuais\n");
    imprimir_lse(agenda->eventos); */

    return 0;
}