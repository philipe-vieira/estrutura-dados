typedef struct arv Arv;

void menu(void);

int arv_vazia(Arv* a);

Arv* arv_libera(Arv* a);

Arv* arv_criaraiz();

Arv* arv_insere(Arv* a, int lado);

Arv * arv_busca(Arv* a, char *c);

void arv_imprime(Arv* a);


