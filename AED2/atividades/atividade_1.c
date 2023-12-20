#include "stdio.h"
#include "stdlib.h"
#include "raw_func.h"
#include "listase.h"

int main(){

    int a;

    t_lse* lse = criar_lse(imprime_elemento, NULL);
    t_elemento* elemento = NULL;

    scanf("%d", &a);

    while(a != 0){
        switch(a){
            case 1: 
            elemento = ler_elemento();
            inserir_final_lse(lse, elemento);
            break;
            case 2:
                t_elemento* elem = remove_inicio_lse(lse);
                imprime_elemento(elem);printf("\n");
                break;
            case 3:
                printf("%d\n", tamanho_lse(lse));
                break;
            default:
                break;
        }
        scanf("%d", &a);
    }

    return 0;
}