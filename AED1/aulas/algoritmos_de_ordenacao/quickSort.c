#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define limiarInsercao 50

/* Função para ordenar um vetor de float por inserção (insertion sort) */

void ordenarPorInsercao(float v[], unsigned tamanhoDoVetor) {
  int i,j;
  float pivot; // pivot sempre do tipo dos elementos do vetor
  
  for(i = 1; i < tamanhoDoVetor; i++) { 
    pivot = v[i];
    j= i -1;
    while((j>=0) && ( v[j]>pivot) ) {
      v[j+1] = v[j];
      j--;
    }
    v[j+1]= pivot;
  }
}


/* o quicksort visto em sala de aula, mas feito para ordenar um vetor de floats ao inves de vetor de inteiros

Notem que removi um if em relação ao código feito em sala. Diferença não é importante.

Versão abaixo é a mais simples
 */

void quickSortR(float v[], int inicio, int fim) {
  int i,j;
  float pivot;  // do mesmo tipo da minha chave de ordenacao (ou dos elem. de v)
  float tmp; // do mesmo tipo dos elementos do vetor
    pivot =  v[(inicio+fim)/2];
    i= inicio;
    j = fim;
    while(i <=j) {
      while(v[i] < pivot) { i++;}  // avanca enquanto está do lado certo
      while(v[j] > pivot) { j--;} // recua enquanto está do lado certo
      if(i <=j ) {
	tmp  = v[i];
	v[i] = v[j];
	v[j] = tmp;
	i++;
	j--;
      } 
    }
    if(inicio < j) { quickSortR(v,inicio,j);} // o if aqui a mais evita chamadas desnecessárias se comparado com o de sala de aula
    if(i < fim)   { quickSortR(v,i, fim); }
}


void quickSort(float v[], unsigned tamanhoDoVetor) {
  if(tamanhoDoVetor > 0) {
    quickSortR(v,0,tamanhoDoVetor-1);
  }
}


/* Versão 2
 usa a constante limiarInsercao (setada acima como 60) para o 
 quickSortR2 passar a ordenar apenas pedaços maiores que 60.
 O vetor fica parcialmente ordenado e a ordenação termina com a chamada para a
ordenação por inserção
  implementa também a otimização proposta por Robert Sedgewick que mencionei hoje
 */

void quickSortR2(float v[], int inicio, int fim) {
  int i,j;
  float pivot;  // do mesmo tipo da minha chave de ordenacao (ou dos elem. de v)
  float tmp; // do mesmo tipo dos elementos do vetor
  int meio;
  while(fim -inicio > limiarInsercao) {
    meio = (inicio+fim)/2;
    pivot =  v[meio];
    i= inicio;
    j = fim;
    while(i <=j) {    // WHILE NO LUGAR DO IF QUE NORMALMENTE APARECERIA AQUI
      while(v[i] < pivot) { i++;}  // avanca enquanto está do lado certo
      while(v[j] > pivot) { j--;} // recua enquanto está do lado certo
      if(i <=j ) {
	tmp  = v[i];
	v[i] = v[j];
	v[j] = tmp;
	i++;
	j--;
      } 
    }
    if(j < meio)  {  // DECIDE QUE LADO VAI TER CHAMADA RECURSIVA E QUE LADO VAI SER TRATADO NESTA MESMA CHAMADA
      quickSortR2(v,inicio,j); // Lado esquerdo é tratado com chamada recursiva
      inicio = i;  // Lado direito é tratado sem chamar recursivamente
    }
    else {
      quickSortR2(v,i, fim); // Lado direito é tratado com chamada recursiva
      fim = j;   // Lado direito é tratado sem chamar recursivamente
    }
  }
}


/* usa a versão 2 e ordena por inserção para completar o trabalho
   experimentem pra ver como fica mais rápido */

void quickSort2(float v[], unsigned tamanhoDoVetor) {
  quickSortR2(v,0,tamanhoDoVetor-1);
  ordenarPorInsercao(v,tamanhoDoVetor);

}


/* A título de curiosidade, uma chamada para o qsort da linguagem C
  Há detalhes de linguagem C que não discuto em sala e coisas que ainda não ensinei, por isso não precisa se preocupar em entender.
  Pode procurar mais sobre o assunto na internet */



 int comp(const void *i, const void *j) {
   return *(float*)i - *(float*)j;
  }

void quickSortOficial(float v[], unsigned tamanhoDoVetor) {
   qsort(v, tamanhoDoVetor, sizeof(float),comp);
  //         int (*compar)(const void *, const void *));
}





void quickSortR3(float v[], int inicio, int fim) {
  int i,j;
  float pivot;  // do mesmo tipo da minha chave de ordenacao (ou dos elem. de v)
  float tmp; // do mesmo tipo dos elementos do vetor
  
    pivot =  v[(inicio+fim)/2];
    i= inicio;
    j = fim;
    while(i <=j) {
      while(v[i] < pivot) { i++;}  // avanca enquanto está do lado certo
      while(v[j] > pivot) { j--;} // recua enquanto está do lado certo
      if(i <=j ) {
	tmp  = v[i];
	v[i] = v[j];
	v[j] = tmp;
	i++;
	j--;
      }
    }
    if( (j - inicio) > limiarInsercao) { quickSortR3(v,inicio,j);}
    if( (fim - i) > limiarInsercao) { quickSortR3(v,i, fim);}
    // }
}


void quickSort3(float v[], unsigned tamanhoDoVetor) {
  if(tamanhoDoVetor > limiarInsercao) {
    quickSortR3(v,0,tamanhoDoVetor-1);
  }
  ordenarPorInsercao(v,tamanhoDoVetor);
}




/* Função para ordenar um vetor de float por selecao (selection sort) */

void ordenarPorSelecao(float vetor[], unsigned tamanhoVetor) {
  unsigned penultimo = tamanhoVetor-1;
  float tmp;
  unsigned i, cont;
  unsigned posMenor;

  for(i=0; i < penultimo; i++) {
    posMenor = i;
    for(cont = i+1; cont < tamanhoVetor; cont++) {
      if(vetor[cont] < vetor[posMenor]) {
	posMenor = cont;
      }
    }
    tmp = vetor[i];  // trocar primeira posicao com posicao do menor
    vetor[i]=vetor[posMenor];
    vetor[posMenor] = tmp;
  }
}




/* Faça uma função que receba como parâmetro um vetor de números reais e uma chave de busca. A função deve retornar verdadeiro (qualquer valor dirente de zero) caso a chave não ocorra no vetor e falso (zero) em caso contrário */

int buscarSequencial(float vetor[], unsigned tamanhoVetor, float chave) {
  unsigned cont;
    for(cont = 0; cont < tamanhoVetor; cont++) {
      if(vetor[cont] == chave) {
	return 1;
      }
    }
    return 0;
}

/* Busca rápida em um vetor ordenado usando o algoritmo de busca binária */

int buscarBinaria(float vetor[], unsigned tamanhoVetor, float chave) {
  unsigned cont;
  int inicio,fim, meio;
  inicio = 0;
  fim=tamanhoVetor-1;
  while( inicio <= fim ) {
    meio = (inicio+ fim) /2;
    if(chave > vetor[meio]) {
      inicio = meio+1;
    }
    else {
      if(chave < vetor[meio]) {
	fim = meio-1;
      }
      else {
	return 1;
      }
    }
  }
    return 0;
}




/* Função que retorna a média dos valores de um vetor passado
   como parâmetro  */

void mostrar(float vetor[], unsigned tamanhoVetor) {
  unsigned cont;

  if(tamanhoVetor == 0) {
    printf("[]\n");
    return;
  }
  printf("[");
  for(cont = 0; cont < tamanhoVetor-1; cont++) {
    printf("%.2f; ",vetor[cont]);
  }
  printf("%.2f]\n",vetor[tamanhoVetor-1]);
}


void preencheVetorAleatoriamente(float vet[], unsigned tamanhoVetor) {
  unsigned cont;
  srand( 100 );
  for(cont = 0; cont < tamanhoVetor; cont++) {
    vet[cont] = rand();
  }
}



/* busca cada elemento do vetor vet1 no vetor vet2. Assume que vet2 está ordenado */

int contemMesmosElementos(float vet1[], float vet2[], int n) {
  int x;
  for(x = 0; x < n; x++) {
    if( buscarBinaria(vet2, n, vet1[x]) == 0) {
      return 0; // Elemento não encontrado
  }
  }
  return 1;
}

void copiaVetor(float destino[], float origem[], int n) {
  int x;
  for(x = 0; x < n ; x++) {
    destino[x] = origem[x];
  }
  
}


/* Faça um programa para testar algoritmos de ordenação:
   1 - Crie dois vetores grandes, preencha um deles aleatoriamente e copie seu conteudo
   2 - Ordene um dos vetores com algum ordenador
   3 - Verifique se a ordenação funcionou (se está ordenado e se possui os todos os elementos do vetor original
*/

#define  tamVet   100000000

int main() {
  float *vetorGrande1;// ignore por enquanto. Em breve explicarei do que se trata
   float *vetorGrande2; // ignore por enquanto. Em breve explicarei do que se trata
  //  static float vetorAux[tamVet];
  
   vetorGrande1 = (float*) malloc(tamVet * sizeof(float));// ignore por enquanto. Em breve explicarei do que se trata
   vetorGrande2 = (float*) malloc(tamVet * sizeof(float));// ignore por enquanto. Em breve explicarei do que se trata

  preencheVetorAleatoriamente(vetorGrande1,tamVet);
  copiaVetor(vetorGrande2,vetorGrande1,tamVet);  // Faça a copiaVetor 
  printf("inicio da ordenacao\n");
  quickSort2(vetorGrande1,tamVet);
  printf("Fim da ordenacao\n");

  free(vetorGrande1);
  free(vetorGrande2);
  return 0;
}
