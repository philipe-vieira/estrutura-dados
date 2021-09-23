typedef struct lista Lista;

typedef struct pilha Pilha;

int pilha_vazia(Pilha * p);

void pilha_libera(Pilha * p);

Pilha * pilha_cria(void);

Pilha * pilha_push(Pilha *pil);

char * pilha_pop(Pilha *pilha);

void pilha_topo(Pilha * p);

void menu(void);

