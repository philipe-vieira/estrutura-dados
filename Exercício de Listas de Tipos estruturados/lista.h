typedef struct lista Lista;

Lista* lista_cria();

Lista* lista_insere(Lista* l);

void lista_imprime(Lista* l);

void lista_busca(Lista* l, char* nome);

Lista* lista_retira(Lista* l, char* nome);
