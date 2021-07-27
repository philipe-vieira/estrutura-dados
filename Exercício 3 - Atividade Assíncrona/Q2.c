#include <stdio.h>
#include <stdlib.h>

void main(){
	int l, c;
	
	printf("Digite a quantidade de linhas das matrizes: ");
	scanf("%d", &l);
	printf("Digite a quantidade de colunas das matrizes: ");
	scanf("%d", &c);
	
	int *matrizA, *matrizB, *S, *D;
	matrizA = malloc(sizeof(int) * l * c);
    matrizB = malloc(sizeof(int) * l * c);
    S = malloc(sizeof(int) * l * c);
    D = malloc(sizeof(int) * l * c);
	
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
		printf("Digite o item %dx%d da matriz A\n", i, j);
		scanf("%d", &matrizA[i * c + j]);
		}
	}
	
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
		printf("Digite o item %dx%d da matriz B\n", i, j);
		scanf("%d", &matrizB[i * c + j]);
		}
	}
	
	
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			S[i * c + j] = matrizA[i * c + j] + matrizB[i * c + j];
			D[i * c + j] = matrizA[i * c + j] - matrizB[i * c + j];
		}
	}
	
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			printf("%i ", S[i * c + j]);
		}
	printf("\n");
	}
	
	printf("\n----------------------------\n");
	
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			printf("%i ", D[i * c + j]);
		}
		printf("\n");
	}
}
