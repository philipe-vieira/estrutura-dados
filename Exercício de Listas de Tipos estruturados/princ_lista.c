#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
	int op;
	Lista* l;
	char busca[41];
	l = lista_cria();
	do{
		menu();
		scanf("%d", &op);
		switch (op){
			case 1:
				l = lista_insere(l);
				break;
			case 2:
				printf("Digite um nome para buscar na lista: ");
				scanf(" %40[^\n]", busca);
				lista_busca(l, busca);
				break;
			case 3:
				printf("Digite um nome para retirar da lista: ");
				scanf(" %40[^\n]", busca);
				l = lista_retira(l, busca);
				break;
			case 4:
				lista_imprime(l);
				break;
			case 5:
				break;				
			default:
				printf("Opcao invalida\n");
				break;
		}
		system("PAUSE");
	} while (op != 5);

}
