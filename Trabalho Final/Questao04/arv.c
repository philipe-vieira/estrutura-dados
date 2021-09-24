#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"

typedef struct arvvar{
	char * pasta;
	struct arvvar *prim;
	struct arvvar *prox;
} Arvvar;

void menu(){
	printf("0) SAIR;\n");
	printf("1) Criar uma pasta raiz;\n");
	printf("2) Inserir uma sub-pasta;\n");
	printf("3) Imprimir a estrutura de pastas;\n->");
}

int arvv_vazia(Arvvar* a){
	return a == NULL;
}

void arvv_libera(Arvvar* a){
	Arvvar * filho = a->prim;
	
	while(filho != NULL){
		Arvvar * aux = filho->prox;
		arvv_libera(filho);
		filho=aux;
	}
	free(a);
}

Arvvar* arvv_criaraiz(){
	char* nome = (char*) malloc(41*sizeof(char));
	printf("Digite o nome da pasta: ");
	scanf(" %40[^\n]", nome);
	
	Arvvar* a = (Arvvar*) malloc(sizeof(Arvvar));
	a->pasta = nome;
	a->prim = NULL;
	a->prox = NULL;
	
	return a;
}

void arvv_insere(Arvvar* a){	
	Arvvar* subarv = (Arvvar*) malloc(sizeof(Arvvar));	
	
	subarv = arvv_criaraiz();
	
	subarv->prox = a->prim;
	
	a->prim = subarv;

}

Arvvar * arvv_busca(Arvvar* a, char *pasta){
	Arvvar * filho;
	if (!arvv_vazia(a)){
		if(strcmp(pasta, a->pasta) == 0){
			return a;
		} else {
			for(filho= a->prim; filho != NULL; filho=filho->prox){
				if(arvv_busca(filho, pasta) != NULL){
					return filho;
				}
			}
		}
	}
	return NULL;
}

void arvv_imprime(Arvvar* a){
	Arvvar * p;
	printf("<");
	if (!arvv_vazia(a)){
		printf("%s ", a->pasta);
		
		for(p= a->prim; p != NULL; p=p->prox){
			arvv_imprime(p);
		}
	}
	printf(">");
}













