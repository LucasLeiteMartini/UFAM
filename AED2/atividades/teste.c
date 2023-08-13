#include <stdio.h>
#include <string.h>

int main(){
    char hora1[30] = {"1995/04/11 15:34"};
    char hora2[30] = {"1994/06/12 15:34"};

    int dia, mes, ano, hora, minuto;

    sscanf(hora1, "%d/%d/%d %d:%d", &dia,&mes,&ano,&hora,&minuto);

    printf("%d %d %d %d %d", dia, mes, ano, hora, minuto);

}
