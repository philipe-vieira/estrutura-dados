#include <stdio.h>

void main(){
	int **matriz, soma=0;
	
	matriz = (int**) malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)	matriz[i] = (int*) malloc(4 * sizeof(int));
	
	for(int l = 0; l < 4; l++){
		printf("Digite a linha %i (Ex.: 1 2 3 4)\n", l);
		scanf("%i %i %i %i", &matriz[l][0], &matriz[l][1], &matriz[l][2], &matriz[l][3]);
	}
	
	
	for(int l = 0; l < 4; l++){
		for(int c = 0; c < 4; c++){
			if( (c+l) == 4){
				soma += matriz[l][c];
			}
		}
	}
	
	printf("%d", soma);
}
