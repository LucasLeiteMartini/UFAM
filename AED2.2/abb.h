typedef void(*t_imprimir_abb)(void*);
typedef int(*t_comparar_abb)(void*, void*);
typedef struct abb t_abb;
t_abb* criar_abb(t_imprimir_abb impressora, t_comparar_abb comparar);
void inserir_abb(t_abb *abb, void* info);
void mostrar_abb(t_abb *abb);
int altura_abb(t_abb *abb);
int vazia_abb(t_abb* ab);
int tamanho_abb(t_abb* ab);