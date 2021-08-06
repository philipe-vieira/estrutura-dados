#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
	Lista* l = NULL;
	Lista* b;
	char nome[40];
	int info;
	do{
		l = lista_insere(l);
		
		printf("CONTINUAR? 0-NAO // 1-SIM ");
		scanf("%d", &info);	
	} while (info != 0);
	
	lista_imprime(l);
	
	printf("Digite o elemento para buscar: ");
	scanf("%s", nome);
	
	b = lista_busca(l, nome);
	if (b == NULL)
		printf("\nElemento nao encontrado\n");
	else
		printf("\n%s\n", b->nome);

	printf("Digite o elemento para excluir: ");
	scanf("%s", nome);
	l = lista_retira(l, nome);
	lista_imprime(l);
	
	
	return 0;
}



