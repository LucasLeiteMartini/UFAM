#include "stdio.h"
#include "diciodinamico.h"
#include"listase.h"
#include "vetordinamico.h"
#include "string.h"

typedef struct palavras
{
    char nome [47];
    int conversao;
}t_palavras;

typedef struct pagina
{
    int repeticao;
    double tf;
    int pag;
    int total_palavras;
}t_paginas;


typedef struct cabecalho{
    t_palavras* palavras;
    double tf, idf, tf_idf;
    int quantidade;
    t_lse* paginas;
    struct cabecalho* prox;
}t_cabecalho;

typedef struct geral{
    t_dd* dd;
    int qtdPag;
    int qtdPalavras;

}t_geral;

int gerachave (char* nome){
    int conv = 0;
        int tam = strlen(nome);
        for(int i=0; i<tam; i++){
            conv = conv + (int)nome[i];
        }
        return conv;
}

t_palavras* cria_palavras(char *nome){
    t_palavras *novo = malloc(sizeof(t_palavras));
    strcpy(novo->nome, nome);

    int conv = gerachave(*nome);
    novo->conversao = conv;

    return novo;
}

t_paginas* cria_pagina(int pag){
    t_paginas* nova = malloc(sizeof(t_paginas));
    nova->pag = pag;
    nova->repeticao = 1;
    nova->tf = 0;
    nova->total_palavras = 0;

    return nova;
}


t_cabecalho* cria_cabecalho(char* palavra){
    t_cabecalho* novo = malloc(sizeof(t_cabecalho));
    t_palavras* palavra_novo = cria_palavras(*palavra);
    novo->palavras = palavra_novo;
    novo->tf = novo->idf = novo->tf_idf = 0;
    novo->quantidade = 1;
    novo->paginas = criar_lse(NULL, NULL);
    novo->prox = NULL;

    return novo;
}

t_geral* cria_geral(){
    t_geral* geral = malloc(sizeof(t_geral));

    t_dd* dicio = criar_dd(100, 100);
    geral->dd = dicio;
    geral->qtdPag = 0;
    geral->qtdPalavras = 0;

    return geral;
}

void inserir_pagina(t_paginas* pag, t_lse* lse){
    inserir_final_lse(lse, (void*) pag);
}

t_paginas* ultima_pagina(t_lse* lse){
    t_paginas* pagina = ultimo(lse);
    if(pagina){
        return pagina->pag;
    }
    else {return -1;}
}

double tf(int qnt_ocorrencias, int qnt_palavras)
{
    return (double)qnt_ocorrencias / (double)qnt_palavras;
}

double idf(int qnt_paginas, int qnt_paginas_ocorrem)
{
    return log((double)qnt_paginas / (double)(qnt_paginas_ocorrem + 1));
}

double tf_idf(double tf, double idf)
{
    return tf * idf;

}

void leituraPalavras(t_geral *geral, FILE *arquivo)
{
    FILE *aux = fopen("Auxiliares/palavras_e_chaves.txt", "w");

    char frase[255];
    char *palavra = NULL;
    t_dd* dicio = geral->dd;
    t_vd* todas_palavras = criar_vd();
    
    while (fgets(frase, sizeof(frase), arquivo) != NULL)
    {
        palavra = strtok(frase, " ");

        int total_de_palavras_pg = 0;
        t_vd* dicio_pag = criar_vd();
        while (palavra != NULL)
        {
            palavra[strcspn(palavra, "\r\n")] = 0;

            if (strcmp(palavra, "PA") != 0)
            {
                int chave;
                chave = gerachave(palavra);
                geral->qtdPalavras ++;
                total_de_palavras_pg ++;

                if (buscar_DD(dicio, chave) == NULL)
                {
                    t_cabecalho* cabecalho = cria_cabecalho(palavra);
                    inserir_vd(todas_palavras, cabecalho);
                    t_paginas* pagina = cria_pagina(geral->qtdPag); 
                    inserir_vd(dicio_pag, pagina);
                    inserir_pagina(pagina, cabecalho->paginas); 
                    inserir_dd(dicio, chave, cabecalho);


                }
                else
                {
                    t_cabecalho *cabecalho = consultar_dd(dicio, chave);
                    if(strcmp(cabecalho->palavras, palavra) == 0){
                        cabecalho->quantidade++;
                        int pag_atual = geral->qtdPag;
                        t_paginas* ultima = ultima_pagina(cabecalho->paginas);
                        if(pag_atual != ultima->pag){
                            t_paginas* nova = cria_pagina(pag_atual);
                            inserir_pagina(nova, cabecalho->paginas);
                        }
                        else{
                            ultima->repeticao ++;
                        }
                    }

                    else{
                        while((strcmp(cabecalho->palavras, palavra) != 0) || (cabecalho->prox != NULL)){
                            cabecalho = cabecalho->prox;
                        }
                        if(strcmp(cabecalho->palavras, palavra) == 0){
                            cabecalho->quantidade++;
                            int pag_atual = geral->qtdPag;
                            t_paginas* ultima = ultima_pagina(cabecalho->paginas);
                            if(pag_atual != ultima->pag){
                                t_paginas* nova = cria_pagina(pag_atual);
                                inserir_pagina(nova, cabecalho->paginas);
                            }
                            else{
                                ultima->repeticao ++;
                            }
                        }
                        else{
                            t_cabecalho* novo = cria_cabecalho(palavra);
                            inserir_vd(todas_palavras, cabecalho);
                            cabecalho->prox = novo;
                            t_paginas* pagina = cria_pagina(geral->qtdPag);
                            inserir_vd(dicio_pag, pagina);
                            inserir_pagina(novo->paginas, pagina);

                        }
                    }
                }
                fprintf(aux, "%s %d\n", palavra, chave); // guarda as chaves num arquivo auxiliar
            }
            else if (strcmp(palavra, "pa") == 0)
            {
                int tamanho = 0; tamanho = ocupacao_vd(dicio_pag);
                t_paginas* palavras_na_pagina;
                
                for(int i = 0; i<tamanho; i++){
                    palavras_na_pagina = acessar_vd(dicio_pag, i);
                    palavras_na_pagina->total_palavras = total_de_palavras_pg;
                    double repeticao, total;
                    repeticao = palavras_na_pagina->repeticao; 
                    total = palavras_na_pagina->total_palavras;
                    palavras_na_pagina->tf = repeticao/total;
                }
                total_de_palavras_pg = 0;
                free(dicio_pag);

                dicio_pag = criar_vd();
                geral->qtdPag ++;
            }
            palavra = strtok(NULL, " ");
        }
    }
    int tam = 0;
    tam = ocupacao_vd(todas_palavras);
    t_cabecalho* cabecalho;
    for(int i=0; i<tam; i++){
        cabecalho = acessar_vd(todas_palavras, i);
        cabecalho->tf = tf(cabecalho->quantidade, geral->qtdPalavras);
        cabecalho->idf = idf(geral->qtdPag, cabecalho->paginas);
        cabecalho->tf_idf = tf_idf(cabecalho->tf, cabecalho->idf);
    }

}

