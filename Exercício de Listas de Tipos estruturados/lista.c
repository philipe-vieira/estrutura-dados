#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct lista{
	int mat;
	char* nome;
	float media;
	struct lista* prox;
};

Lista* lista_cria(){
	return NULL;
}

Lista* lista_insere(Lista* l){
	int mat;
	printf("Digite uma matricula: ");
	scanf("%i", &mat);
	
	
	char* nome = (char*) malloc(41*sizeof(char));
	printf("Digite um nome: ");
	scanf(" %40[^\n]", nome);
	
	float media;
	printf("Digite a media: ");
	scanf("%f", &media);

	
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->mat = mat;
	novo->nome = nome;
	novo->media = media;
	novo->prox = l;
	return novo;
}

void lista_imprime(Lista* l){
	Lista* p;
	for (p = l; p != NULL; p = p->prox){
		printf("Matricula %i; Nome %s; Media %f\n", p->mat, p->nome, p->media);
	}
}

void lista_busca(Lista* l, char* nome){
	Lista* p;
	Lista* encontrado;
	int e;
	e = 0;
	for (p = l; p != NULL; p = p->prox){
		if (strcmp(p->nome, nome) == 0){
			e = 1;
			encontrado =p;
		}
	}
	if (e == 1){
		printf("O nome %s foi encontrado\n", nome);
		printf("Matricula %i; Nome %s; Media %f\n", encontrado->mat, encontrado->nome, encontrado->media);
	}
	else
		printf("O nome nao foi encontrado\n");	
}

Lista* lista_retira(Lista* l, char* nome){
	Lista* ant = NULL;
	Lista* p = l;
	
	while (p != NULL && strcmp(p->nome, nome) != 0){
		ant = p;
		p = p->prox;	
	}
	
	// Percorreu toda a lista e n encontrou
	if (p == NULL)
		return l;
	// Encontrou na primeira posiçao da lista
	if (ant == NULL)
		l = p->prox;
	// Encontrou no meio da lista
	else
		ant->prox = p->prox;
	
	free(p);
	return l;
}

void menu(){
	system("CLS");
	printf("1 - Inserir\n");
	printf("2 - Buscar\n");
	printf("3 - Retirar\n");
	printf("4 - Imprimir\n");
	printf("5 - Sair\n");
	printf("Digite a opcao desejada: ");
}
