#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
   char* nome;
   struct lista* prox;
} Lista;


typedef struct pilha{
	Lista* prim;
} Pilha;

Pilha * pilha_cria(){
	Pilha * p = (Pilha *)malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

Pilha * pilha_push(Pilha *piula, char *nome){
	Lista * novo = (Lista*)malloc(sizeof(Lista));
	novo->nome = nome;
	novo->prox = piula->prim;
	piula->prim = novo;
	return piula;
}

Pilha * pilha_push2(Pilha *piula){
	Lista * novo = (Lista*)malloc(sizeof(Lista));
	
	char* nome = (char*) malloc(41*sizeof(char));
	printf("Digite um nome: ");
	scanf(" %40[^\n]", nome);
	
	novo->nome = nome;
	novo->prox = piula->prim;
	piula->prim = novo;
	return piula;
}

char * pilha_pop(Pilha *pilha){
	char * nome = NULL;
	
	if(pilha_vazia(pilha)){
		printf("PILHA VAZIA\n");
		
	} else {
		// guarda o de cima
		Lista * aux = pilha->prim;
		// guarda o nome
		nome = pilha->prim->nome;
		// Tira o de cima
		free(pilha);
		pilha->prim = aux->prox;
		free(aux);
		
	}
	return nome;
}

int pilha_vazia(Pilha * p){
	return (p->prim == NULL);
}

void pilha_libera(Pilha * p){
	if(pilha_vazia(p)){
		printf("PILHA VAZIA\n");
	} else {
		Lista * atual = p->prim;
		
		while(atual != NULL){
			Lista * prox = atual->prox;
			free(atual);
			atual = prox;
		}
		free(p);
		p->prim = NULL;
		printf("LIBERADO!!!\n");
	}
	
}

void lista_imprime(Pilha * p){
	if(pilha_vazia(p)){
		printf("PILHA VAZIA\n");
		return 0;
	} else {
		Lista * atual = p->prim;
	
		while(atual != NULL){
			printf("Nome %s\n", atual->nome );
			atual = atual->prox;
		}
		free(atual);
	}
}

void menu(){
	printf("1 - Empilhar (push)\n2 - Desempilhar (pop)\n3 - Imprimir\n4 - Liberar\n5 - Sair\n--->   ");
}




















