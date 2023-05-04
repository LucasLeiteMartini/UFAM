#include <stdio.h>


<<<<<<< HEAD
=======

>>>>>>> 47fc35f1472df88d3a7095915e5e00b146e62f29
long int questao01(long int n){
    long soma = 1;
    for(int i = n; i >= 1; i--){
        soma = soma * (2*i);
    }
    
    return soma;
}


<<<<<<< HEAD
int main() {
   long int valor;

   scanf("%ld%*c",&valor);
   printf("%ld\n", questao01(valor));

=======
int main(){
    long int valor;

    scanf("%d", &valor);
    printf("%ld", questao01(valor));
>>>>>>> 47fc35f1472df88d3a7095915e5e00b146e62f29
}