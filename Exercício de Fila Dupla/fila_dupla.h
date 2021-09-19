typedef struct lista2 Lista2;
typedef struct fila2 Fila2;

Fila2 * fila2_cria (void);

void fila2_insere_ini (Fila2 * f);
void fila2_insere_fim (Fila2 * f);

char* fila2_retira_ini (Fila2 * f);
char* fila2_retira_fim (Fila2 * f);

int fila2_vazia(Fila2 * f);

void fila2_libera (Fila2 * f);

void fila2_imprime_ini_fim (Fila2 *f);
void fila2_imprime_fim_ini (Fila2 *f);

void menu();
