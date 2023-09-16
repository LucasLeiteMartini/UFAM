#include "listase.h"

typedef struct agenda t_agenda;
typedef struct evento t_evento;

t_evento* cria_evento(char descricao[], char tempo[], char prioridade[]);
t_agenda* criar_agenda(t_imprimir_lse imprime, t_comparar_lse compara);

void agendar_evento(t_agenda* agenda , t_evento* evento);
int quantificar_evento(t_agenda* agenda);
void proximo_evento(t_agenda* agenda);
void alterar_evento(t_agenda* agenda, t_evento* chave, t_evento* novo_evento);
void* cancelar_evento(t_agenda* agenda, t_evento* chave);
void concluir_evento(t_agenda* agenda);
void imprimir_evento(void* carga);
int compara_eventos(void* e1, void* e2);
void* ler_evento();
void* ler_chave();