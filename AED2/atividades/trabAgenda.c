#include <stdio.h>
#include "stdlib.h"
#include "agenda.h"

int main(){
    t_agenda* agenda = criar_agenda(imprimir_evento, compara_eventos);
    t_evento* evento = NULL;
    t_evento* chave = NULL;
    t_evento* novo_evento = NULL;
    t_evento* tmp = NULL;
    int operacao;

    scanf("%d",&operacao);
    
    while(operacao>0){
        switch(operacao){
            case 1:
                evento = ler_evento();
                agendar_evento(agenda, evento);
                break;
            case 2:
                printf("%d\n",quantificar_evento(agenda));
                break;
            case 3:
                proximo_evento(agenda);
                break;
            case 4:
                chave = ler_chave();
                novo_evento = ler_evento();
                alterar_evento(agenda, chave, novo_evento);
                break;
            case 5:
                chave = ler_chave();
                tmp = cancelar_evento(agenda, chave);
                printf("\n");
                imprimir_evento(tmp);   
                break;
            case 6:
                concluir_evento(agenda);
                break;
        }
        scanf("%d", &operacao);
    }
}