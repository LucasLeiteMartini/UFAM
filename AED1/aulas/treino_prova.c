#include<stdio.h>


// FACA AQUI A FUNCAO CONCAVA


int concava(float vet[], int tam){

    for(int i = 1; i < tam/2; i ++){
        if((vet[i-1]) < vet[i]){
            return 0;
        }
    }

    for(int i = tam - 1; i > tam/2; i--){
        if((vet[i-1]) > vet[i]){
            return 0;
        }
    }
    return 1;
}


// FIM DA FINCAO CONCAVA



int main() {
    unsigned tamVetor;
    unsigned x;
    
    scanf("%u%*c",&tamVetor);
    
    float vet[tamVetor];
    
    for(x = 0; x< tamVetor; x++) {
        scanf("%f%*c",&vet[x]);
    }
    
    if(concava(vet,tamVetor)) {
        printf("1\n");
    }else{
        printf("0\n");
    }

}