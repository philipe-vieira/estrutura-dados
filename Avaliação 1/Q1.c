#include <stdio.h>

int* alt_vetor(int n, int vet[n]){
	
	for (int i=0; i < n; i++){
		vet[i] = vet[i] * vet[0];
	}
	
	return vet;
}


int main (){
	int vetor[10];
	
	for (int i=0; i<10; i++){
		vetor[i] = i+2;
	}
	for(int j = 0; j < 10; j++) {
		printf("%i, ", vetor[j]);
	}
	printf("\n\n");
	
	alt_vetor(10, vetor);
	for(int j = 0; j < 10; j++) {
		printf("%i, ", vetor[j]);
	}
	
	return 0;
}
