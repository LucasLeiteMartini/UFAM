#include <stdio.h>
#include <string.h>

int main(){
    char hora1[60] = {"1995/04/11 15:34 rodrigo_santos_abacatada_firme_potente alta"};
    char hora2[30] = {"1994/06/12 15:34"};
    char descricao[141];
    char prior[11];

    int dia, mes, ano, hora, minuto;

    sscanf(hora1, "%d/%d/%d %d:%d %[^\n] %s", &dia,&mes,&ano,&hora,&minuto, descricao, prior);

    printf("%02d/%02d/%d %d:%d %s %s\n", dia, mes, ano, hora, minuto, descricao, prior);

}

[]->[]->[]->[]