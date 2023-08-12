#include <stdio.h>
#include <string.h>

int main(){
    char hora1[30] = {"2023/06/12 15:34"};
    char hora2[30] = {"2023/06/12 15:34"};

    char hora3[30] = {"alta"};
    char hora4[30] = {"media"};



    printf("%d\n",strcmp(hora3,hora4));
}
