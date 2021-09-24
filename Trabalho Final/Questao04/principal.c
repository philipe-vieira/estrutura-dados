#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

int main(){
	Arvvar * arvv = NULL;
	Arvvar * busca = NULL;
	char* nome = (char*) malloc(41*sizeof(char));
	int op;
	
	do{
		menu();
		scanf("%d", &op);
		switch (op){
			case 1:
				arvv = arvv_criaraiz();
				break;
			case 2:	
				printf("Digite o nome da pasta em que deseja inserir a sub-pasta: ");
				scanf(" %40[^\n]", nome);
				
				busca = arvv_busca(arvv, nome);
				
				if(busca != NULL){
					arvv_insere(busca);
					arvv_imprime(busca);
				} else {
					printf("Pasta nao encontrada!");
				}
				
				printf("\n\n");
				busca = NULL;
				break;
			case 3:
				arvv_imprime(arvv);
				printf("\n\n");
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
	
	arvv_libera(arvv);
	return 0;
}
