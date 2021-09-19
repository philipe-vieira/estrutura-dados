#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

struct arv{
	char * info;
	struct arv *esq;
	struct arv *dir;
};

Arv* arv_criavazia(){
	return NULL;
}

Arv* arv_cria(Arv* e, Arv* d){
	char* nome = (char*) malloc(41*sizeof(char));
	printf("Digite um nome: ");
	scanf(" %40[^\n]", nome);
	
	Arv* a = (Arv*) malloc(sizeof(Arv));
	a->info = nome;
	a->esq = e;
	a->dir = d;
	return a;
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

int arv_pertence(Arv* a, char *c){
	if (arv_vazia(a))
		return 0;
	else
		return  strcmp(c, a->info) == 0 || arv_pertence(a->esq, c) || arv_pertence(a->dir, c);
}

void arv_imprime(Arv* a){
	if (!arv_vazia(a)){
		printf("<%s ", a->info);
		arv_imprime(a->esq);
		arv_imprime(a->dir);
		printf(">");
	}
}

Arv* get_esq(Arv* a){
	return a->esq;
}

Arv* get_dir(Arv* a){
	return a->dir;
}

void set_esq(Arv* a, Arv* esq){
	a->esq = esq;
}

void set_dir(Arv* a, Arv* dir){
	a->dir = dir;
}

