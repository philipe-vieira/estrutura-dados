typedef struct lista Lista;
typedef struct fila Fila;

Fila * fila_cria (void);

void fila_insere (Fila * f);

char* fila_retira (Fila * f);

int fila_vazia(Fila * f);

void fila_libera (Fila * f);

void lista_imprime(Fila *f);

void menu();
