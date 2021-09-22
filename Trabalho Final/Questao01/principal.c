#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
	int op;
	Lista* list = lst_cria();
	Lista* buscado = lst_cria();
	char* nome = (char*) malloc(41*sizeof(char));
	do{
		menu();
		scanf("%i", &op);
		switch(op){
			case 1:
				list = lst_insere(list);
				break;
			case 2:
				printf("Digite o elemento a ser removido: ");
				scanf(" %40[^\n]", nome);
				
				list = lst_retira(list, nome);
				break;
			case 3:
				printf("Digite o elemento a ser buscado: ");
				scanf(" %40[^\n]", nome);
				
				buscado = lst_busca(list, nome);
				break;
			case 4:
				lst_imprime(list);
				break;
			case 0:
				// SAIR
				break;
			default:
				printf("Opcao invalida!");
				break;
		}
	} while(op != 0);
	
	return 0;
}
