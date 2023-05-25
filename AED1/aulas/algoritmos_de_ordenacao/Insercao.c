#include<stdio.h>

void insercao(float v[], int tam){
    int i,j;
    float pivot;
    for(j=1; j < tam;j++){
        pivot = v[j];
        i = j-1;
        while((i >= 0) && (pivot < v[i])){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = pivot;
    }
}