#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main(){
	int op;
	char* nome = malloc(41*(sizeof(char*)));
	Fila* fila = fila_cria();
	do{
		menu();
		scanf("%i", &op);
		switch(op){
			case 1:
				fila_insere(fila);
				break;
			case 2:
				nome = fila_retira(fila);
				if (nome != NULL)
					printf("O paciente chamado foi: %s\n", nome);
				break;
			case 3:
				printf("Digite o nome do paciente para a saber a posicao: ");
				scanf(" %40[^\n]", nome);
				
				fila_busca(fila, nome);
				break;
			case 4:
				fila_atendidos(fila);
				break;
			case 5:
				// SAIR
				break;
			default:
				printf("Opcao invalida!");
				break;
		}
	} while(op != 5);
	
	return 0;
}

