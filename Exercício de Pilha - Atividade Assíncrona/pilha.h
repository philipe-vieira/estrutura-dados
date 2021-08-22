typedef struct lista Lista;
typedef struct pilha Pilha;

Pilha * pilha_cria();
Pilha * pilha_push(Pilha *piula, char *nome);
Pilha * pilha_push2(Pilha *piula);

char * pilha_pop(Pilha *pilha);

int pilha_vazia(Pilha * p);
void pilha_libera(Pilha * p);
void lista_imprime(Pilha * p);
void menu();
