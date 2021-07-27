#include <stdio.h>

int main(){
	int leitura, contador = 0;
	int maior = 0, menor = 99999, soma = 0;
	do{
		printf("\nDigite o numero a ser lido -> ");
		scanf("%i", &leitura);
		if(leitura == 0){
			break;
		}
		
		if(leitura > 0){
			contador++;
			
			if (leitura > maior){
				maior = leitura;
			}
			if (leitura < menor){
				menor = leitura;
			}
			soma += leitura;
		}
		printf("%i", contador);
	}while(contador < 50);
	
	int op;
	do{
		printf("--- MENU ---\n");
		printf("1 - Maximo\n");
		printf("2 - Minimo\n");
		printf("3 - Media\n");
		printf("4 - Sair\n");
		scanf("%d", &op);
		switch (op){
			case 1:
				printf("Maximo = %d\n", maior);
				break;
			case 2:
				printf("Minimo = %d\n", menor);
				break;
			case 3:
				printf("Media = %i\n", soma/contador);
				break;
			case 4:
				break;
			default:
				printf("Opcao invalida\n");
		}
	}while (op != 4);
	
	return 0;
}
