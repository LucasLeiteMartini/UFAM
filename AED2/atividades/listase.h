
typedef void (*t_imprimir_lse)(void*);
typedef int (*t_comparar_lse)(void*, void*);

typedef struct lse t_lse;
typedef struct elem_lse t_elemento_lse;

t_lse* criar_lse(t_imprimir_lse imprimir, t_comparar_lse comparar);
t_elemento_lse* criar_elemento_lse(void* carga_util);

void inserir_lse(t_lse* lse, void* carga_util);
void inserir_final_lse(t_lse* lse, void* carga_util);

void* remover_lse(t_lse* lse);
void* acessar_lse(t_lse* lse, int pos);

void imprimir_lse(t_lse *lse);
