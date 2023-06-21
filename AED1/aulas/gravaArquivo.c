#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

typedef struct tipoTabela {
  unsigned id;
  float nota;
} tipoTabela;


/* indica quantos bytes tenho no arquivo */

int tamanhoArquivo(FILE *f) {

struct stat buf;
fstat(fileno(f), &buf);
return buf.st_size;
}



void preencheVetor(tipoTabela *v, unsigned tam) {

    for (unsigned x =0; x < tam ; x++) {
      v[x].id = rand()%100000;
      v[x].nota = rand()%1001;
      v[x].nota/=100.0;
    }
  }


 void mostraVetor(tipoTabela *v, unsigned tam) {

   for (unsigned x =0; x < tam ; x++) {
     printf("%u %.2f\n",v[x].id,v[x].nota);
   }
 }

#define TAM_VET 1000

int main() {
  tipoTabela *vet;
  FILE *fp;

  vet = (tipoTabela*) malloc (sizeof(tipoTabela)*TAM_VET);

  preencheVetor(vet,TAM_VET);
  //  mostraVetor(vet,TAM_VET);
   fp = fopen("arquivoNotas","w"); // CRIA o ARQUIVO
   fwrite(vet,sizeof(tipoTabela),TAM_VET,fp);
   printf("gerei um arquivo com %d bytes\n",tamanhoArquivo(fp));
   printf("O tamanho dos  registros é %lu\n", sizeof(tipoTabela));
   
}
