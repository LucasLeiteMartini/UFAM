#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool busca_interpolacao_limitada(int chave, int *vetor, int inicio, int fim, int max_comparacoes) {
    int posicao;
    while (inicio <= fim && max_comparacoes > 0) {
        double interpolacao = (double)(chave - vetor[inicio]) / (vetor[fim] - vetor[inicio]);
        posicao = inicio + (int)(interpolacao * (fim - inicio));
        if (posicao < inicio || posicao > fim) {
            return false;
        }
        if (vetor[posicao] == chave) {
            return true;
        }
        if (vetor[posicao] < chave) {
            inicio = posicao + 1;
        } else {
            fim = posicao - 1;
        }
        max_comparacoes--;
    }
    return false;
}



bool busca_intervalo(int chave, int *vetor, int inicio, int fim) {
    int tamanho_intervalo = fim - inicio + 1;
    int max_comparacoes = 2 * log(tamanho_intervalo);
    return busca_interpolacao_limitada(chave, vetor, inicio, fim, max_comparacoes);
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11 , 13, 15};
    int inicio = 2;
    int fim = 4;
    int chave = 9;
    bool encontrou = busca_intervalo(chave, vetor, inicio, fim);
    printf("%s\n", encontrou ? "Encontrou a chave" : "Nao encontrou a chave");
    return 0;
}
