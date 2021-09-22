typedef struct lista Lista;

Lista* lst_cria();

Lista* lst_insere(Lista* l);

void lst_imprime(Lista* l);

Lista* lst_busca(Lista* l, char* v);

Lista* lst_retira(Lista* l, char* v);

void menu();
