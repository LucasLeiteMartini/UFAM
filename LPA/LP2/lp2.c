#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ERRO_POUCOS_ARGUMENTOS 5
#define ERRO_ARQUIVO_OPEN 7

typedef struct pessoa_t{

    char nome[51];
    long long int cpf;
    int idade;

}pessoa_t;

int hash_tam = 5;

typedef struct lista_pessoas_t{
    pessoa_t* pessoa;
    struct lista_pessoas_t* prox;
}lista_pessoas_t;

typedef lista_pessoas_t** tabela_hash_t;

pessoa_t* criar_pessoa(char nome[], long long int cpf, int idade){
    pessoa_t* nova = malloc(sizeof(pessoa_t));

    strcpy(nova->nome, nome);
    nova->cpf = cpf;    
    nova->idade = idade;

    return nova;
}

void imprimir_pessoa(pessoa_t* pessoa){
    printf("%s\t%lld\t%d\n", pessoa->nome, pessoa->cpf, pessoa->idade);
}

void lista_pessoas_listar(lista_pessoas_t* lista){
    lista_pessoas_t* cam = lista;

    while(!cam->prox){
        imprimir_pessoa(cam->pessoa);
        cam = cam->prox;
    }

}

bool lista_pessoas_adicionar(pessoa_t* pessoa, lista_pessoas_t** lista){
    lista_pessoas_t* novo_no = malloc(sizeof(lista_pessoas_t));
    if (novo_no == NULL) {
        return false;
    }
    novo_no->pessoa = pessoa;
    novo_no->prox = *lista;
    *lista = novo_no;
    return true;
}

void tabela_hash_pessoas_listar(tabela_hash_t tabela_hash){
    for(int i = 0; i < hash_tam; i++){
        lista_pessoas_listar(tabela_hash[i]);
    }
}

tabela_hash_t tabela_hash_pessoas_criar(){
    tabela_hash_t tabela = malloc(hash_tam*sizeof(lista_pessoas_t*));
    for(int i = 0; i < hash_tam; i++){
        tabela[i] = NULL;
    }
    return tabela;
}

int tabela_hash_pessoas_funcao(pessoa_t *pessoa){
    return pessoa->cpf % hash_tam;
}

bool tabela_hash_pessoas_adicionar(pessoa_t* pessoa, tabela_hash_t tabela){
    int indice = tabela_hash_pessoas_funcao(pessoa);

    bool f = lista_pessoas_adicionar(pessoa, &tabela[indice]);
    
    if(!f) return false;
    
    return true;
}

int main(int argc, char** argv){
    
    // if(argc < 3){
    //     return ERRO_POUCOS_ARGUMENTOS;
    // }

    // hash_tam = sscanf(argv[1], "%d", &hash_tam);

    FILE* arquivo = fopen("arquivo_entrada.txt", "r");

    if(!arquivo){
        return ERRO_ARQUIVO_OPEN;
    }

    char nome[51];
    long long int cpf;
    int idade;

    pessoa_t* pessoa;
    tabela_hash_t tabela = tabela_hash_pessoas_criar();

    while(!feof(arquivo)){
        fscanf(arquivo, "%50[^\t]\t%lld\t%d\n", nome, &cpf, &idade);
        pessoa = criar_pessoa(nome, cpf, idade);
        tabela_hash_pessoas_adicionar(pessoa, tabela);
    }
    
    tabela_hash_pessoas_listar(tabela);

    return 0;
}