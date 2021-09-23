#include <stdio.h>
#include <stdlib.h>
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
				pil = pilha_push(pil);
				break;
			case 2:
				removido = pilha_pop(pil);
				printf("Removido -> %s\n", removido);
				break;
			case 3:
				pilha_topo(pil);
				break;
			case 0:
				// SAIR ---
				break;					
			default:
				printf("Opcao invalida\n");
				break;
		}
		system("PAUSE");
	} while (op != 0);
	pilha_libera(pil);
}
