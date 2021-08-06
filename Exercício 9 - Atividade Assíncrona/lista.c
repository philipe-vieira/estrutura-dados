#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Lista * lista_cria(){
	Lista * list = malloc(sizeof(Lista)) ;
	char nome[41];
	int quant;
	
	printf("Digite o nome-> ");
	scanf(" %40[^\n]", nome);
	
	quant = strlen(nome);
	
	list->nome = (char*) malloc((quant + 1)*sizeof(char));
	strcpy(list->nome, nome);
	
	return list;
}

Lista * lista_insere(Lista * l){
	Lista * novo = lista_cria();
	
	novo->prox = l;
	
	return novo;
}

Lista * lista_busca(Lista * l, char * nome){
	for(Lista * p = l; p != NULL; p = p->prox){
		if (strcmp(nome, p->nome) == 0){
			return p;
		}
	}
	return NULL;
}

Lista * lista_retira(Lista * l, char * nome){
	Lista *p, *q;
	p = l;
	q = l->prox;
	if(*q->nome == *nome){
		printf("passou");
	}
	while (q != NULL && *q->nome != *nome) {
		p = q;
		q = q->prox;
	}
	
	if (q == NULL)
		return l;
	
	if (q != NULL) {
	  p->prox = q->prox;
	  free (q);
	}
	return p;
}

void lista_imprime(Lista* l){
	Lista* p;
	for (p = l; p != NULL; p = p->prox){
		printf("%s\t", p->nome);
	}
	printf("\n\n");
}
