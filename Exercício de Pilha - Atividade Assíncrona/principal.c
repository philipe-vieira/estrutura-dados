#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){
	Pilha * pil = pilha_cria();
	int op;
	char * removido;
	do{
		menu();
		scanf("%d", &op);
		switch (op){
			case 1:
				pil = pilha_push2(pil);
				break;
			case 2:
				removido = pilha_pop(pil);
				printf("Removido -> %s\n", removido);
				break;
			case 3:
				lista_imprime(pil);
				break;
			case 4:
				pilha_libera(pil);
				break;
			case 5:
				// SAIR ---
				break;					
			default:
				printf("Opcao invalida\n");
				break;
		}
		system("PAUSE");
	} while (op != 5);
}
