#include <stdio.h>
#include <stdlib.h>

typedef struct tipoFuncionario{
    char nome[40];
    float salario;
    unsigned id;
}tipoFuncionario;

typedef struct tipoListaFuncionarios{
    tipoFuncionario *dados;
    unsigned capacidade;
    unsigned tamanho;
}tipoListaFuncionarios;

void criaListaFuncionarios(tipoListaFuncionarios *l){
    l->capacidade=2;
    l->dados = (tipoFuncionario*) malloc(sizeof(tipoFuncionario)*l->capacidade);

    l->tamanho=0;
}

void insereNoFinalListaFuncionarios(tipoListaFuncionarios *l, tipoFuncionario f){
    if(l->tamanho >= l->capacidade){ //se cabe no vetor
        l->capacidade = l->capacidade *2;
        l->dados = (tipoFuncionario*) realloc(l->dados, sizeof(tipoFuncionario)* l->capacidade);
    }
    l->dados[l->tamanho]=f;
    l->tamanho++;
}

void insereNoInicioListaFuncionarios(tipoListaFuncionarios *l, tipoFuncionario f){
    if(l->tamanho >= l->capacidade){ // se cabe no vetor
    l->capacidade = l->capacidade*2;
    l->dados = (tipoFuncionario*) realloc(l->dados, sizeof(tipoFuncionario)* l->capacidade);
    }
    for(int x = l->tamanho; x>=1; x--){
        l->dados[x] = l->dados[x-1];
    }
    l->dados[0]=f;
    l->tamanho++;
}

void mostraListaFuncionarios(tipoListaFuncionarios *l){
    if(l->tamanho){
        for(int x = 0; x < l->tamanho; x++){
          printf("---------------------\n");
          printf("%s\n",l->dados[x].nome);
          printf("%.2f\n",l->dados[x].salario);
          printf("%u\n",l->dados[x].id);
        }
    }
    else{
        printf("Lista vazia\n");
    }
}

void lerDadosFuncionario(tipoFuncionario *f){
    printf("Entre com um nome: ");
    scanf("%[^\n]%*c", f->nome);
    printf("Entre com o salario: ");
    scanf("%f%*c", &f->salario);
    printf("Entre com o id: ");
    scanf("%u%*c", f->id);
}

int main(){
    tipoListaFuncionarios l1, l2;
    tipoFuncionario tmp;

    criaListaFuncionarios(&l1);
    criaListaFuncionarios(&l2);

    for(int x = 0; x < 3; x++){
        lerDadosFuncionario(&tmp);
        insereNoFinalListaFuncionarios(&l1, tmp);
    }
    printf("lista l1:\n");
    mostraListaFuncionarios(&l1);
    printf("lista l2:\n");
    mostraListaFuncionarios(&l2);
}