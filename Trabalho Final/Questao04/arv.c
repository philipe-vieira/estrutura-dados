#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"

struct arv{
	char * pasta;
	struct arv *esq;
	struct arv *dir;
};

void menu(){
	printf("1) Criar uma pasta raiz;\n");
	printf("2) Inserir uma sub-pasta;\n");
	printf("3) Remover uma subpasta;\n");
	printf("4) Imprimir a estrutura de pastas;\n->");
}

int arv_vazia(Arv* a){
	return a == NULL;
}

Arv* arv_libera(Arv* a){
	if (!arv_vazia(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);	
	}
	return NULL;
}

Arv* arv_criaraiz(){
	char* nome = (char*) malloc(41*sizeof(char));
	printf("Digite o nome da pasta raiz: ");
	scanf(" %40[^\n]", nome);
	
	Arv* a = (Arv*) malloc(sizeof(Arv));
	a->pasta = nome;
	a->esq = NULL;
	a->dir = NULL;
	
	return a;
}

Arv* arv_insere(Arv* a, int lado){
	
	if(lado == 1 || lado == 2 ){
		char* nome = (char*) malloc(41*sizeof(char));
		printf("Digite o nome da pasta: ");
		scanf(" %40[^\n]", nome);
		
		Arv* novo = (Arv*) malloc(sizeof(Arv));
		novo->pasta = nome;
		novo->esq = NULL;
		novo->dir = NULL;
		
		if(lado == 1){
			a->esq = novo;
		} else if (lado == 2){
			a->dir = novo;
		} 	
	}else {
		printf("Lado errado\n");
	}
	
}

Arv * arv_busca(Arv* a, char *c){
	if (!arv_vazia(a)){
		if(strcmp(c, a->pasta) == 0){
			return a;
		} else if (arv_busca(a->esq, c) != NULL){
			return a->esq;
		} else if (arv_busca(a->dir, c) != NULL){
			return a->dir;
		}
	}
	return NULL;
}

void arv_imprime(Arv* a){
	printf("<");
	if (!arv_vazia(a)){
		printf("%s ", a->pasta);
		arv_imprime(a->esq);
		arv_imprime(a->dir);
	}
	printf(">");
}













