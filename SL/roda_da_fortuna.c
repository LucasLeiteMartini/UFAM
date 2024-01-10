#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*ALUNOS: LUCAS LEITE MARTINI, KAIKE RIBAS DA SILVA MACIEL
MATRÍCULAS: 22252570,  22250538
*/

char* soma_binaria(char* num1, char* num2) {
    // Obtem o tamanho dos números.
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // Checa se o tamanho do num1 é menor que 4 bits, se for, realiza o ajuste.
    if (len1 < 4) {
        char* temp = malloc(5);
        sprintf(temp, "%s%.*s", len1 > 0 && num1[0] == '-' ? "-" : "", 4 - len1, "0000");
        strcat(temp, num1 + (num1[0] == '-'));
        num1 = temp;
    }

    // Checa se o tamanho do num2 é menor que 4 bits, se for, realiza o ajuste.
    if (len2 < 4) {
        char* temp = malloc(5);
        sprintf(temp, "%s%.*s", len2 > 0 && num2[0] == '-' ? "-" : "", 4 - len2, "0000");
        strcat(temp, num2 + (num2[0] == '-'));
        num2 = temp;
    }

    // Aloca espaço para armazenamento do resultado (4 bits + 1 caracter nulo).
    char* resultado = malloc(5);
    int carry = 0;

    // Itera pelos bits da direita para a esquerda
    for (int i = strlen(num1) - 1; i >= 0; i--) {
        // Soma os bits do menos significativo ao mais significativo.
        int soma = (num1[i] - '0') + (num2[i] - '0') + carry;
        resultado[strlen(num1) - 1 - i] = (soma % 2) + '0';  // Adiciona o bit da soma ao resultado
        carry = soma / 2;  // Calcula o carry para a próxima coluna
    }

    // Checa para ver se o valor necessita de truncamento.
    if (carry) {
        resultado[0] = '0';
    }

    return resultado;
}

char* dec_to_base(int num, int base) {
    char* base_num = malloc(5);  // Alocando espaço para 4 bits + 1 para o caractere nulo
    int index = 0;

    while (num > 0) {
        int dig = num % base;
        if (dig < 10) {
            base_num[index++] = dig + '0';
        } else {
            base_num[index++] = dig - 10 + 'A';  // Calcula a letra correspondente ao dígito
        }
        num /= base;
    }

    // Preenche com zeros à esquerda se necessário
    while (index < 4) {
        base_num[index++] = '0';
    }

    base_num[index] = '\0';  // Adiciona o caractere nulo no final da string

    // Inverte a string
    for (int i = 0, j = index - 1; i < j; i++, j--) {
        char temp = base_num[i];
        base_num[i] = base_num[j];
        base_num[j] = temp;
    }

    return base_num;
}

void roda_da_fortuna(char* sua_sorte_binario, int* tentativa) {
    // Um loop que funciona enquanto as tentativas forem menores que 3, ou se o jogador desejar continuar
    printf("========================================================================================================================================\n");
    char continua;
    printf("Desejas continuar meu caro jogador? ");
    scanf(" %c", &continua);  // Usa scanf para obter entrada do usuário

    int play = 1;  // 1 indica verdadeiro
    while (play) {
        if (continua == 'c' && *tentativa < 3) {
            char* novo_valor_binario = soma_binaria(sua_sorte_binario, dec_to_base(rand() % 16, 2));
            printf("Seu novo valor é: %s\n", novo_valor_binario);
            free(novo_valor_binario);  // Libera a memória alocada dinamicamente

            printf("Desejas continuar meu caro jogador? ");
            scanf(" %c", &continua);

            printf("\n========================================================================================================================================\n");
            (*tentativa)++;
        } else {
            play = 0;  // 0 indica falso
        }
    }

    // Checa se o bit de sinal é positivo ou não
    if (sua_sorte_binario[0] == '0') {
        printf("Você chegou ao fim jogador, e seu valor final foi **%s** o que resulta em... FORTUNA!!!!\n", sua_sorte_binario);
    } else {
        printf("Você chegou ao fim jogador, e seu valor final foi **%s** o que resulta em... INFORTÚNIO HAHAHAHA!!!\n", sua_sorte_binario);
    }
}

int main() {

    srand(time(NULL));

    char* sua_sorte = dec_to_base((rand()%16), 2);

    printf("Olá jogador! Esta é a Roda da Fortuna, um jogo em que você pode testar sua sorte... Mas qual será o seu resultado? FORTUNA OU INFORTÚNIO???\n");
    printf("Aqui segue algumas regras do jogo:\n");
    printf("[1] Você começa com um valor aleatório e faz a sua primeira jogada, sendo ela obrigatória.\n");
    printf("[2] Após sua primeira jogada obrigatória, você tem direito a mais 3 tentativas podendo decidir entre c de continue, ou p de parar\n");

    printf("========================================================================================================================================");
    printf("\nSeu valor inicial é: %s.", sua_sorte);
    printf("\n========================================================================================================================================\n");

    char* fortuna_infortunio = soma_binaria(sua_sorte,dec_to_base((rand()%16),2));

    printf("Após sua jogada obrigatória, seu novo valor é: %s\n", fortuna_infortunio);
    printf("A partir de agora você possui mais três tentativas.\n");
    int tentativa = 1;

    roda_da_fortuna(fortuna_infortunio, &tentativa);

    free(sua_sorte);

    return 0;
}
