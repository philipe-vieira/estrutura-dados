#include <stdio.h>

 int pares(int n, int vet[n]){
 	int qnt_pares=0;
 	
 	for (int i =0; i < n; i++){
		if ((vet[i] %2) == 0){
 			qnt_pares++;
		}
	}
	
	return qnt_pares;
 }
 
 
int main(){
	int tam = 3;
	int vetor[tam];
	
	vetor[0] = 2;
	vetor[1] = 2;
	vetor[2] = 2;
	
	printf("%i", pares(tam, vetor));
	
	return 0;
}
