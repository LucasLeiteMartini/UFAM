typedef void (*t_imprimir_lse)(void*);
typedef int (*t_comparar_lse)(void*, void*);

typedef struct lse t_lse;
typedef struct elem_se t_elemento_lse;

t_lse* criar_lse(t_imprimir_lse imprimir, t_comparar_lse comparar);
t_elemento_lse* criar_elemento_lse(void* carga_util);
void inserir_lse(t_lse* lse, void* carga_util);
void inserir_final_lse(t_lse* lse, void* carga_util);
void inserir_conteudo_lse(t_lse* lse, void* carga_util);
void inserir_posicao(t_lse* lse, void* carga);


void* remover_lse(t_lse* lse);
void* remove_elem(t_lse* lse, void* chave);
void* acessar_lse(t_lse* lse, int pos);
void* acessar_com_comparacao(t_lse* lse, void* carga);

void imprimir_lse(t_lse *lse);
void imprime_elem(t_lse* lse);