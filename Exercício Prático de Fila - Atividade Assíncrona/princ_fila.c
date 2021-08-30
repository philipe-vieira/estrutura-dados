#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main(){
	Fila * f = fila_cria();
	int op;
	char * removido;
	do{
		menu();
		scanf("%d", &op);
		switch (op){
			case 1:
				fila_insere(f);
				break;
			case 2:
				removido = fila_retira(f);
				printf("Removido -> %s\n", removido);
				break;
			case 3:
				lista_imprime(f);
				break;
			case 4:
				fila_libera(f);
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
