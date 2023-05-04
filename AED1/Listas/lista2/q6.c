#include <stdio.h>

int main() {
 unsigned int dimensao, l, c;
	
<<<<<<< HEAD
 scanf("%u%*c",&dimensao); // aqui lê a dimensão
	
	// agora escreva o código para imprimir a imagem
	// olha um exemplo do que pode ser feito pra imprimir uma imagem
	// com linha 0 e a última linha acesas	
	// dai complemente o exercício
=======
 scanf("%u%*c",&dimensao);
	
>>>>>>> 47fc35f1472df88d3a7095915e5e00b146e62f29
	
 for( l=0; l < dimensao; l++) {
	for( c=0; c < dimensao; c++) {
		if((l==0) || (l == dimensao-1) || (c == 0) || (c == dimensao - 1)) {
		 printf("1");
		}
<<<<<<< HEAD
        else if(l == c || l + c == dimensao - 1){
            printf("1");
        }
=======
		else if(l == c || l + c == dimensao - 1){
			printf("1");
		}
>>>>>>> 47fc35f1472df88d3a7095915e5e00b146e62f29
		else {
		 printf("o");
		}
	}
<<<<<<< HEAD

	printf("\n"); // para mudar de linha
 }
} 
=======
	printf("\n");
 }
}
>>>>>>> 47fc35f1472df88d3a7095915e5e00b146e62f29
