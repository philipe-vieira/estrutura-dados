#include <stdio.h>

int* inverte(int n, int  vet[n]){
 	int* aux = malloc(2);
 	
 	for (int i = 0; i < n; i++){
		aux[n-i-1] = vet[i];
	}
	
	return aux;
 }
 
 
int main(){
	int tam = 3;
	int vetor[tam];
	
	vetor[0] = 1;
	vetor[1] = 2;
	vetor[2] = 4;
	
	for(int j = 0; j < tam; j++) {
		printf("%i, ", inverte(tam, vetor)[j]);
	}
	
	return 0;
}
