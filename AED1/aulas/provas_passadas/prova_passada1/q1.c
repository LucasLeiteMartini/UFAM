#include <stdio.h>
#include <string.h>

typedef struct tipoArvore{
	char familia[80];
	char especie[80];
	char nomeCientifico[80];
	float diametro;
}tipoArvore;

 void lerDados(tipoArvore vet[], int tam){
 	for(int i = 0; i < tam; i++){
 	scanf("%s", vet[i].familia);
 	scanf("%s", vet[i].especie);
 	scanf("%s", vet[i].nomeCientifico);
 	scanf("%f", &vet[i].diametro);
 	}
 }

float questao01(tipoArvore vet[], int tam, char chave[]){
	int  i;
	float media = 0.0, cont = 0.0;
	for(i = 0;i < tam; i++){
		if(strcmp(vet[i].familia,chave) == 0){
			media += vet[i].diametro;
			cont++;
			// printf("%f %f\n", media, cont);
		}
	}
	
	if(cont != 0) media = media/cont;

	return media;
}

int main(){
	
	int tam;
	char chave[80];

	scanf("%d",&tam);
	// printf("%d\n",tam);
	scanf("%s", chave);
	// printf("%s\n", chave);
	tipoArvore vet[tam];


	lerDados(vet,tam);	
	printf("%.2f\n",questao01(vet,tam,chave));

}