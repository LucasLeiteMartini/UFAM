#include <stdio.h>



long int questao01(long int n){
    long soma = 1;
    for(int i = n; i >= 1; i--){
        soma = soma * (2*i);
    }
    
    return soma;
}


int main(){
    long int valor;

    scanf("%d", &valor);
    printf("%ld", questao01(valor));
}