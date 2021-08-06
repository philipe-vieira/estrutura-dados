/*typedef struct lista s{
   char* nome;
   struct lista* prox;
} Lista;*/

struct lista{
	char * nome;
	struct lista* prox;
};

typedef struct lista Lista;

Lista * lista_cria();

Lista * lista_insere(Lista * l);

Lista * lista_busca(Lista * l, char * nome);

Lista * lista_retira(Lista * l, char * nome);

void lista_imprime(Lista* l);
