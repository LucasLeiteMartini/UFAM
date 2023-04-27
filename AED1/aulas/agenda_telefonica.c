#include <stdio.h>
#include <string.h>
#define _TAM_VET 10


typedef struct contato
{
    char nome[50];
    char telefone[20];
}contato;


void leitorDados(struct contato vetContatos[], unsigned tam){
    for(int i = 0; i < tam; i++){
        printf("Entre com um nome para a posição [%d]: ", i);
        scanf("%[^\n]%*c", vetContatos[i].nome);
        printf("Digite o número do contato: ");
        scanf("%[^\n]%*c", vetContatos[i].telefone);
    }

}

void mostraDados(struct contato vetContatos[], unsigned tam){

    for(int i = 0; i < tam; i++){
        printf("[%u]: (%s, %s)\n", i, vetContatos[i].nome, vetContatos[i].telefone);
    }
}

void insertionSort(struct contato vetContatos[], unsigned tam){
    int i,j;
    struct contato pivot;
    for(j=1; j < tam;j++){
        pivot = vetContatos[j];
        i = j-1;
        while((i >= 0) && (strcmp(pivot.nome,vetContatos[i].nome) < 0)){
            vetContatos[i+1] = vetContatos[i];
            i--;
        }
        vetContatos[i+1] = pivot;
    }
}

int buscaBinaria(contato vet[], int tam, char chave[]) {
  int meio, inicio = 0, pos = 0;
  int fim = tam-1;
  while(inicio <= fim) {
    meio = (inicio+fim)/2;
    if(strcmp(chave,vet[meio].nome) < 0){
        fim = meio -1;
        pos++;
    }
    else if (strcmp(chave,vet[meio].nome) > 0){
        inicio = meio+1;
        pos++;
    }
    else {      return pos;    }
  }
  return 0;
}


int main(){

    unsigned tam;
    scanf("%u%*c", &tam);
    char chave[40];
    scanf("%[^\n]%*c",chave);
    struct contato vetContatos[tam];


    leitorDados(vetContatos, tam);
    insertionSort(vetContatos, tam);

    mostraDados(vetContatos, tam);

    if(buscaBinaria(vetContatos,tam,chave)){
        printf("%s está na lista de contatos! Seu contato é: %s\n", chave, vetContatos[buscaBinaria(vetContatos,tam,chave)].telefone);
    }else{
        printf("%s não está na lista de contatos\n",chave);
    }


    return 0;
}