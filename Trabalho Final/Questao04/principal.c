#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

int main(){
	Arv * arv = NULL;
	Arv * busca = NULL;
	int op;
	int lado;
	char* nome = (char*) malloc(41*sizeof(char));
	
	do{
		menu();
		scanf("%d", &op);
		switch (op){
			case 1:
				arv = arv_criaraiz();
				break;
			case 2:	
				printf("Digite o nome da pasta em que deseja inserir a sub-pasta: ");
				scanf(" %40[^\n]", nome);
				
				busca = arv_busca(arv, nome);
				
				if(busca != NULL){
					printf("Em qual lado deseja inserir a sub-pasta? 1-Esquerdo // 2-direito\n->");
					scanf("%i", &lado);
					arv_insere(busca, lado);
					arv_imprime(busca);
				} else {
					printf("Pasta nao encontrada!");
				}
				printf("\n\n");
				busca = NULL;
				break;
			case 3:
				printf("Digite o nome da pasta/sub-pasta que deseja remover: ");
				scanf(" %40[^\n]", nome);
				
				busca = arv_busca(arv, nome);
				
				if(busca != NULL){
					busca = arv_libera(busca);
					printf("Pasta Removida!\n");
				} else {
					printf("Pasta nao encontrada!\n\n");
				}
				
				busca = NULL;
				break;
			case 4:
				arv_imprime(arv);
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
	
	arv_libera(arv);
	return 0;
}
