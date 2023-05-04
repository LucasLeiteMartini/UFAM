#include <stdio.h>


int main(){

    int vet[6],i;

    for(int i = 0; i < 6; i++){
        scanf("%d",&vet[i]);
    }


    for(i =0; i < 6; i++){

        if(vet[i] % 2 == 1) break;


    }

    if(i == 6) printf("Todos são pares");


}