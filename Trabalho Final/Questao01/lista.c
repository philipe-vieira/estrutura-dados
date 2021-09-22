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

Lista* lst_insere(Lista* l){
	char* nome = (char*) malloc(41*sizeof(char));
	printf("Digite um nome: ");
	scanf(" %40[^\n]", nome);
				
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = nome;
	novo->prox = NULL;
	
	Lista* ant = NULL;
	Lista* p = l;

	while(p != NULL){
		ant = p;
		p = p->prox;
	}
	
	if (ant == NULL){ // não encontrou
		l = novo;
	} else {
		ant->prox = novo;
	}
	
	return l;
}

void lst_imprime(Lista* l){
	Lista* p;
	for (p = l; p != NULL; p = p->prox){
		if(p->prox != NULL){
			printf("%s\t || prox -> %s \n", p->info, p->prox->info );
		} else {
			printf("%s\t || p-> NULL", p->info);
		}
	}
	printf("\n");
}

Lista* lst_busca(Lista* l, char* v){
	Lista* p;
	for (p = l; p != NULL; p = p->prox){
		if (strcmp(p->info, v) == 0){
			printf("Elemento %s foi encontrado!\n", p->info);
			return p;
		}
	}
	printf("Elemento nao foi encontrado!\n");
	return NULL;
}

Lista* lst_retira(Lista* l, char* v){
	Lista* ant = NULL;
	Lista* p = l;
	while (p != NULL && strcmp(p->info, v) != 0){
		ant = p;
		p = p->prox;
	}
	
	if (p == NULL)
		return l;
	
	if (ant == NULL)
		l = p->prox;
	else
		ant->prox = p->prox;
	
	free(p);
	return l;
}

void menu(){
	printf("1- Inserir um novo nome na lista;\n");
	printf("2- Remover um elemento da lista;\n");
	printf("3- Pesquisar um elemento da lista;\n");
	printf("4- Imprimir o conteudo da lista;\n->");
}


