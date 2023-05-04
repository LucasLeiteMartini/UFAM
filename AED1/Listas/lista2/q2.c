#include <stdio.h>

void questao02(int vet[], unsigned x){
    for(int i = 0; i < x; i++){
        if(vet[i] <= 0) vet[i] = -2;
        else if(vet[i] >= 1 && vet[i] <= 5) vet[i] = -1;
        else vet[i] = 0;
    }
}

<<<<<<< HEAD
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
   questao02(vet,tamVetor);
   mostraVetor(vet,tamVetor);
}
=======

void mostraVetor(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main(){
    unsigned tamVetor;
    unsigned x;

    scanf("%u%*c", &tamVetor);
    int vet[tamVetor];

    for(x = 0; x < tamVetor; x++){
        scanf("%d%*c", &vet[x]);
    }
    questao02(vet,tamVetor);
    mostraVetor(vet,tamVetor);
}
>>>>>>> 47fc35f1472df88d3a7095915e5e00b146e62f29
