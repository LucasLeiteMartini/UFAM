#include "stdio.h"
#include "stdlib.h"
#include "listase.h"


typedef struct elemento{

    int idade;
    float peso;
    float altura;

}t_elemento;


t_elemento* cria_elemento(int idade, float peso, float altura){

    t_elemento* elemento = malloc(sizeof(t_elemento));

    elemento->idade = idade;
    elemento->peso = peso;
    elemento->altura = altura;

    return elemento;

}


t_elemento* ler_elemento(){
    
    int age;
    float weight;
    float height;
    
    scanf(" %d %f %f", &age, &weight, &height);

    return cria_elemento(age,weight,height);
}

void imprime_elemento(void* elemento){
    t_elemento* elem = elemento;

    printf("%d %.1f %.1f", elem->idade, elem->peso, elem->altura);

}
