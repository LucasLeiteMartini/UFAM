#include <stdio.h>

int main() {
 unsigned int dimensao, l, c;
	
 scanf("%u%*c",&dimensao); // aqui lê a dimensão
	
	// agora escreva o código para imprimir a imagem
	// olha um exemplo do que pode ser feito pra imprimir uma imagem
	// com linha 0 e a última linha acesas	
	// dai complemente o exercício
	
 for( l=0; l < dimensao; l++) {
	for( c=0; c < dimensao; c++) {
		if((l==0) || (l == dimensao-1) || (c == 0) || (c == dimensao - 1)) {
		 printf("1");
		}
        else if(l == c || l + c == dimensao - 1){
            printf("1");
        }
		else {
		 printf("o");
		}
	}

	printf("\n"); // para mudar de linha
 }
} 