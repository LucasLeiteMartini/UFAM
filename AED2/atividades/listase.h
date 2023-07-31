typedef void (*t_imprimir_lse)(void*);
typedef int (*t_comparar_lse)(void* ,void*);

typedef struct lse t_lse;
void cria_lse();

void insererir_lse(t_lse *l, void* carga_util);
void* remover_lse(t_lse *l);
void* acessar_lse(t_lse *l, int pos);

void imprimir_lse(t_lse *lse);