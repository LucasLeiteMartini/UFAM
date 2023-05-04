#include <stdio.h>

int questao04(int vet[], unsigned x){
    for(int i = 0; i < x-1; i ++){
        if(vet[i] > vet[i+1]){
            return 0;
        }
    }
    return 1;
}


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
   if(questao04(vet,tamVetor)) {
     printf("VERDADEIRO\n");
   }
   else {
     printf("FALSO\n");
   }
   
}
