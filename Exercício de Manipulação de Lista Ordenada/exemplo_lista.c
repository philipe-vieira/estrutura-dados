#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
	char* info;
	struct lista* prox;
};

typedef struct lista Lista;

Lista* lst_cria(){
	return NULL;
}

Lista* lst_insere(Lista* l, char* i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	
	Lista* ant = l;
	Lista* p = l;
	
	if (p) do {
		ant = p;
		p = p->prox;
	}while (p != l && p != NULL);
	
	if (ant == NULL){
		l = novo;
	} else {
		ant->prox = novo;
	}
	
	return l;
}

void lst_imprime(Lista* l){
	Lista* p = l;
	
	if (p) do {
		printf("%s\t", p->info);
		p = p->prox;
	}while (p != l && p != NULL);
}

Lista* lst_busca(Lista* l, char* v){
	Lista* p = l;
	if (p) do {
		if (strcmp(p->info, v) == 0)
			return p;
		p = p->prox;
	}while (p != l && p != NULL);
	
	return NULL;
}

Lista* lst_retira(Lista* l, char* v){
	Lista* ant = NULL;
	Lista* p = l;
	
	if (p) do {
		ant = p;
		p = p->prox;
	}while (p != l && p != NULL && strcmp(p->info, v) != 0);

	if (p == NULL || p == l)
		return l;
	
	if (ant == NULL)
		l = p->prox;
	else
		ant->prox = p->prox;
	
	free(p);
	return l;
}

int main(){
	Lista* l = lst_cria();
	Lista* b;
	char* info;
	char buscar[81], inserir;
	
	do{
		printf("Digite o elemento da lista: ");
		info = (char*) malloc(81*sizeof(char));
		scanf(" %80[^\n]", info);
		l = lst_insere(l, info);
		printf("Inserir mais um item?");
		scanf(" %c", &inserir);

	
	} while (inserir == 's');
	
	lst_imprime(l);
	
	printf("\nDigite o elemento para buscar: ");
	scanf(" %80[^\n]", buscar);
	b = lst_busca(l, &buscar);
	if (b == NULL)
		printf("\nElemento nao encontrado\n");
	else
		printf("\n%s\n", b->info);

	printf("Digite o elemento para excluir: ");
	scanf(" %80[^\n]", buscar);
	l = lst_retira(l, &buscar);
	lst_imprime(l);
	return 0;
}


