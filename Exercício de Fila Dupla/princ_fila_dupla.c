#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_dupla.h"

int main(){
	Fila2 * f = fila2_cria();
	int op;
	char * removido;
	do{
		menu();
		scanf("%d", &op);
		switch (op){
			case 1:
				fila2_insere_ini(f);
				break;
			case 2:
				fila2_insere_fim(f);
				break;
			case 3:
				removido = fila2_retira_ini(f);
				printf("Removido do inicio -> %s\n", removido);
				break;
			case 4:
				removido = fila2_retira_fim(f);
				printf("Removido do fim -> %s\n", removido);
				break;
			case 5:
				fila2_imprime_ini_fim(f);;
				break;
			case 6:
				fila2_imprime_fim_ini(f);;
				break;
			case 7:
				// SAIR ---
				break;					
			default:
				printf("Opcao invalida\n");
				break;
		}
		system("PAUSE");
	} while (op != 7);
	
	fila2_libera(f);
	
	return 0;
}
