#include <stdio.h>

int buscaBinaria(int v[], int tam, int chave) {
  int meio, inicio = 0;
  int fim = tam-1;
  while(inicio <= fim) {
    meio = (inicio+fim)/2;
    if(chave < v[meio])       { fim = meio -1;    }
    else if (chave > v[meio]) {  inicio = meio+1; }
    else {      return 1;    }
  }
  return 0;
}


void mostrarVetor(int v[], int tam) {
  int x;

  printf("(");
  for(x = 0; x < tam ; x++) {
    printf("%d,",v[x]);
  }
  printf(")\n");
}


/* Funcao para ler valores para um vetor
   recebe como parametros um vetor v e seu tamanho (tam)
 */

void lerVetor(int v[], int tam) {
  int x;
  for(x = 0; x < tam ; x++) {
    printf("Entre com o valor da posicao [%d] : ",x);
    scanf("%d%*c",&v[x]);
  }
}


/* ordenacao por selecao 

*/

void selecao( int v[], int n) {
  int i,j;
  int posMenor;
  int tmp;
  int tamMenos1 = n -1;

  for(i = 0; i < tamMenos1 ; i++) {
    posMenor= i;
     for(j = i+1; j < n ; j++) {
       if(v[j] < v[posMenor]) {
	 posMenor = j;
       }
     }
     tmp = v[i];
     v[i] = v[posMenor];
     v[posMenor] = tmp;
  }
}


double fat(unsigned n) {

  if(n > 1) {
    return n*fat(n-1);
  }
  return 1.0;
}



int main() {
  int vet[8];
  int segundo[1000];
  int chave;

  lerVetor(vet,8);
  mostrarVetor(vet,8);
  selecao(vet,8);
  mostrarVetor(vet,8);

  while(1) {
    printf("Entre com uma chave de busca: ");
    scanf("%d%*c",&chave);
    if(buscaBinaria(vet,8,chave)) {
      printf("A chave ocorre no vetor!\n");
    }
    else {
      printf("A chave NÃO ocorre no vetor!\n");
    }
  }


}
