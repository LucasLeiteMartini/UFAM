#include <stdio.h>
#include <string.h>

int questao05(char t[], char p[]) {
    int tamanho_t = strlen(t);
    int tamanho_p = strlen(p);
    int i, j;
    
    for (i = 0; i <= tamanho_t - tamanho_p; i++) {
        for (j = 0; j < tamanho_p; j++) {
            if (t[i+j] != p[j])
                break;
        }
        if (j == tamanho_p)
            return 1;
    }
    
    return 0;
}

int main() {

    char texto[2000]; // texto onde vamos buscar a string de consulta
    char padrao[100]; // string de consulta
    unsigned tamVetor;
    unsigned x;

    scanf("%[^#]%*c",texto);
    scanf("%[^#]%*c",padrao);
    if(questao05(texto,padrao)) {
    printf("VERDADEIRO\n");
  }
    else {
    printf("FALSO\n");
  }


}