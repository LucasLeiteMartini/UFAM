typedef struct fila t_fila;

t_fila* criar_fila();
void enfileirar(t_fila* f, void* elem);
void* desenfileirar(t_fila* f);
int tamanho_fila(t_fila* f);
void* primeiro_fila(t_fila* f);
