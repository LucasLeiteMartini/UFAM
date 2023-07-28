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

void criaAgenda(tipoAgenda *agenda){
    agenda->prim = NULL;
}

void adicionaEvento(tipoAgenda *agenda, tipoEvento evento){
    tipoNo *aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));

    aux->evento = evento;
    aux->prox = agenda->prim;
    agenda->prim = aux;

}

void mostraEventos(tipoAgenda *agenda){
    tipoNo *aux;

    if(!agenda->prim){
        printf("Sua Agenda de Eventos está vazia!");
    }else{
        aux = agenda->prim;
        printf("Seus Eventos:\n\n");

        while(aux){
            printf("Dia: %s\n", aux->evento.data);
            printf("Hora: %s\n", aux->evento.hora);
            printf("Descricao: %s\n", aux->evento.descricao);
            printf("Prioridade: %d\n", aux->evento.prioridade);
            printf("\n");
            aux = aux->prox;
        }
        printf("Fim da sua Agenda de Eventos!\n");
    }


    aux = agenda->prim;
}


void removeEvento(tipoAgenda *agenda, tipoEvento chave){
    tipoNo *aux, *tmp;
    
    if(strcmp(agenda->prim->evento.data,chave.data) == 0){
        if(strcmp(agenda->prim->evento.hora,chave.hora) == 0){
            tmp = agenda->prim;
            agenda->prim = tmp->prox;
            free(tmp);
        }
    }
}

int main(){

    tipoAgenda agenda;
    criaAgenda(&agenda);
    mostraEventos(&agenda);

    tipoEvento e1 = {"15/06/2004","15:15","abacate",2};
    tipoEvento e2 = {"17/08/1902","12:12","x-bacon",2};
    tipoEvento e3 = {"19/03/2007","10:10","beterraba",2};
    tipoEvento e4 = {"24/12/2012","m22:22","morango",2};
    tipoEvento e5 = {"01/01/2001","01:01","jujuba",2};

    adicionaEvento(&agenda, e1);
    adicionaEvento(&agenda, e2);
    adicionaEvento(&agenda, e3);
    adicionaEvento(&agenda, e4);
    adicionaEvento(&agenda, e5);

    mostraEventos(&agenda);

    return 0;
}