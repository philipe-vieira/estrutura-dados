typedef struct paciente Paciente;

typedef struct fila Fila;


Fila * fila_cria (void);

void fila_libera (Fila * f);

void fila_insere (Fila * f);

char* fila_retira (Fila * f);

int fila_vazia(Fila * f);

void lista_imprime(Fila *f);

void menu();

int fila_tamanho(Fila * f);

void fila_busca(Fila * fila, char* paciente);

void fila_atendidos(Fila * f);


