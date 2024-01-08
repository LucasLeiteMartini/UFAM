#include "stdio.h"

void troca(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}


int main(){
    int a = 10, b = 15;

    printf("%d %d\n", a, b);
    troca(&a,&b);
    printf("%d %d\n", a, b);


}