#include <stdio.h>

<<<<<<< HEAD
=======

>>>>>>> 47fc35f1472df88d3a7095915e5e00b146e62f29
void questao03(int vet[], int x){
    int temp;
    for(int i = 0; i < x/2; i++){
        temp = vet[x - i - 1];
        vet[x - i - 1] = vet[i];
        vet[i] = temp;
    }
}

<<<<<<< HEAD
=======

>>>>>>> 47fc35f1472df88d3a7095915e5e00b146e62f29
void mostraVetor(int vet[], unsigned n) {
  unsigned x;

  for(x = 0; x< n; x++) {
    printf("%d ",vet[x]);
  }
  printf("\n");
}

int main() {
   unsigned tamVetor;
   unsigned x;

   scanf("%u%*c",&tamVetor);
   int vet[tamVetor];

   for(x = 0; x< tamVetor; x++) {
     scanf("%d%*c",&vet[x]);
   } 
   questao03(vet,tamVetor);
   mostraVetor(vet,tamVetor);
}
