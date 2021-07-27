#include <stdio.h>

 int negativos(int n, float vet[n]){
 	int qnt_negativos=0;
 	
 	for (int i =0; i < n; i++){
		if (vet[i] < 0){
 			qnt_negativos++;
		}
	}
	
	return qnt_negativos;
 }
 
 
int main(){
	int tam = 2;
	float vetor[2];
	
	vetor[0] = -5.6;
	vetor[1] = -2.0;
	
	printf("%i", negativos(tam, vetor));
	
	return 0;
}
