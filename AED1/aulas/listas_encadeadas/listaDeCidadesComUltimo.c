#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
SELECT cited, queries FROM `jusbrasil-155317.search_ranking.citation_tags_low_frequency_v2` LIMIT 1000
*/


typedef struct tipoCidade {
  char nome[40];
  float pib;
  unsigned populacao;
} tipoCidade;

typedef struct tipoNo {
  // aqui alguma informação que queremos guardar
  tipoCidade dado;
  // aqui um ponteiro para outras variáveis do mesmo tipo
  struct tipoNo *prox;

} tipoNo;

typedef struct tipoLista {
  tipoNo *prim;
  tipoNo *ult;
} tipoLista;

/* cria uma lista encadeada vazia
   para chamar a função você deve passar o endereco de uma variavel do tipo lista.... */

void criaLista(tipoLista *l) {
  l->prim = NULL;
  l->ult = NULL;
}



tipoCidade removeUltimo(tipoLista *pl) {
  tipoNo *aux,*tmp;
  tipoCidade c;
  aux = pl->prim;
  if(aux->prox == NULL) { // Se só tem 1 elemento (ele é o último)
    pl-> prim = NULL; // lista fica vazia prim e ult com null!
    pl->ult = NULL;  
    c = aux->dado;
    free(aux); // libera a memória
  }
  else {
    while(aux->prox->prox) { // anda até o penúltimo. Note que tem pelo menos 2
      aux = aux->prox;       // se chegou aqui! Por isso funciona
    }
    tmp = aux->prox;   // aux aponta pro penultimo e tmp pro ultimo
    aux->prox = NULL;  // desconecta último da lista
    pl->ult = aux;     // penultimo vira o novo ultimo
    c = tmp->dado;     
    free(tmp); // libera memória 
  }
  return c;
}


/* essa aqui busca pela chave (nomeCidade) e se encontrar devolve os dados na variavel apontada por pc.
   Fiz ela retornar int, mas poderia também fazer pc=null quando não achar e retornar void */

int removeElemento(tipoLista *pl, char nomeCidade[], tipoCidade *pc) {

  tipoNo *aux, *tmp;


  aux = pl->prim;
// coloquei depois da aula pra fazer nossa função funcionar pra listas vazias
  if(aux == NULL) { 
    return 0;
  }

  if(strcmp(aux->dado.nome,nomeCidade)==0) { // se chave é o primeiro
    *pc = aux->dado; // variavel apontada pelo pc (*pc) recebe o dado
    pl->prim = aux->prox;   // o segundo passa a ser o novo primeiro
    if(pl->prim == NULL) pl->ult = NULL;  // se só tinha 1, prim e ult ficam com null
    free(aux);
    
  }
  else {
    // aqui se não era o primeiro que eu queria apagar
    // coloquei o if abaixo depois da aula
    // na hora de comentar vi que faltou testar o caso de ter só 1 elemento na lista
    
    if(aux->prox == NULL) {
      return 0;
    }
    // se chegou aqui, tem pelo menos 2 elementos
    // e vou caminhar até o anterior ao que quero apagar
    while(strcmp(aux->prox->dado.nome,nomeCidade) !=0)   {
      aux = aux->prox;
      // se o próximo é null, então (aux->prox->dado) era o último
      // e verifiquei todos. Quer dizer que chave não tá na lista
      if(aux->prox == NULL) {
	return 0; // nao achou, retorna zero!
      }
    }
    // Se chegou aqui, chave está na lista e o seguinte ao aux é o que quero apagar
    tmp = aux->prox; // tmp aponta pro item que quero apagar
    aux->prox = tmp->prox; // desconecta tmp da lista
    *pc = tmp->dado;   // variavel apontada por pc (*pc) recebe o dado
    if(pl->ult == tmp) { // se tmp apontava pro último, atualiza o novo último 
      pl->ult = aux;
    } 
    free(tmp); // libera a memória

  }
  // se chegou aqui, é pq encontrou. retorna 1
  return 1;
}


tipoCidade removePrimeiro(tipoLista *pl) {
  tipoNo *aux;
  tipoCidade c;
  aux = pl->prim;
  c = aux->dado;
  pl->prim = aux->prox;
  if(pl->prim == NULL) pl->ult = NULL; // se prim virou null, ult vira null tb
  free(aux);
  return c;
}

tipoNo * temElemento(tipoLista *pl) {

  return pl->prim;
}

// lembrar que insere no inicio. Só muda o ult quando a lista era vazia antes da insercao

void inserirElementoNaLista( tipoLista *l, tipoCidade valor) {
  tipoNo *aux;

  aux = (tipoNo*) malloc(sizeof(tipoNo));
  aux->dado = valor;
  aux->prox = l->prim;
  if(l->prim == NULL) {
    l->ult = aux;   // se lista era vazia, o novo item é tb o último da lista
  }
  l->prim = aux;

}


/* inserir no fim da lista não era fácil sem ter o ponteiro para o último
 por isso ter o ponteiro pro último pode ser uma boa ideia se quero inserir no final (como numa fila)
 */

void inserirUltElementoNaLista( tipoLista *l, tipoCidade valor) {
  tipoNo *aux;

  aux = (tipoNo*) malloc(sizeof(tipoNo));
  aux->dado = valor;
  aux ->prox = NULL;
  if(l->prim == NULL) {
    l->prim = aux;  // to inserindo no final. Se prim era null, o novo elemento é primeiro e ultimo
  }
  else {
  l->ult->prox = aux;
  }
  l->ult = aux;

}



void mostrarLista(tipoLista *l) {
  tipoNo *aux;

  aux = l->prim;
  printf("******INICIO DA LISTA*****\n");
  while(aux) {
    printf("%s\n", aux->dado.nome);
    printf("%.2f\n", aux->dado.pib);
    printf("%u\n", aux->dado.populacao);
    aux = aux->prox;
  }
  printf("***** FIM DA LISTA *****\n");
}



int buscaNaLista(tipoLista *l, char chave[]) {
  tipoNo *aux;

  aux = l->prim;

  while(aux) {
    if(strcmp(aux->dado.nome,chave)==0) return 1;
    aux = aux->prox;
  }
  return 0;
}





int pibMaior(tipoLista *l, float valorReferencia) {
  tipoNo *aux;
  unsigned cont = 0;
  aux = l->prim;

  while(aux) {
    if(aux->dado.pib > valorReferencia) cont++;
    aux = aux->prox;
  }
  return cont;
}


void lerCidade(tipoCidade *pc) {

  scanf("%[^\n]%*c",pc->nome);
  scanf("%f%*c",&pc->pib);
  scanf("%u%*c",&pc->populacao);
}

int main() {
  tipoLista l1,l2;
  tipoLista tmp;
  tipoCidade c;

  tmp = l1;
  l1 = l2;
  l2 = tmp;
  criaLista(&l1);
  criaLista(&l2);
  for(int x=0; x< 3; x++){
    lerCidade(&c);
    inserirElementoNaLista(&l1, c);
  }

  mostrarLista(&l1);

  for(int x = 0; x < 3; x++) {
    removePrimeiro(&l1);
    mostrarLista(&l1);
  }
}
