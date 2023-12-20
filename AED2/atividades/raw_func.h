typedef struct elemento t_elemento;

t_elemento* cria_elemento(int idade, float peso, float altura);
t_elemento* ler_elemento();
void imprime_elemento(void* elemento);