#include <stdio.h>
#include <stdlib.h>   

void intercala( int v[],int inicio, int meio, int fim, int vaux[]) {
  unsigned i=inicio,j=meio+1,k=inicio;
  while((i <= meio) && (j <= fim) ) {
    if(v[i] < v[j]) { vaux[k] = v[i];  i++;    }
    else            { vaux[k] = v[j];  j++;    }
    k++;
  }
  while(i <= meio) {  vaux[k] = v[i];    i++; k++;  }
  while(j <= fim)  {  vaux[k] = v[j];    j++; k++; }
  // DEVOLVE A INTERCALACAO PARA O VETOR ORIGINAL
  for(i = inicio; i <= fim ; i++) {
    v[i] = vaux[i];
  }
}



void mergeSortR(int v[], int inicio, int fim, int vaux[]) {
  int meio;
  if(inicio < fim) {
    meio = (inicio+fim)/2;
    mergeSortR(v,inicio,meio, vaux);
    mergeSortR(v,meio+1,fim, vaux);
    intercala(v, inicio, meio, fim, vaux);
  }


}

void mergeSort(int v[], int tam) {
  int * vaux;
  vaux = (int*) malloc (sizeof(int) * tam);
  mergeSortR(v, 0, tam -1 , vaux);


  free(vaux);
}






int main() {
  int v[10]={100,8,6,2,7,9,1,4,8,9};

  mergeSort(v,10);

  for(int x = 0; x < 10; x++) {
    printf("%d ",v[x]);
  }
  printf("\n");

  /*  int x = 5;
  int z= 9;
  int *p = &x;
  int **p2 = &p;

  **p2 = *p + **p2;
  p = &v[1];
  p[0] = 7;
  p++;
  *p = 8;
  **p2 = 0;
    // qual o valor das variaveis x,y e v ?

    */

}



