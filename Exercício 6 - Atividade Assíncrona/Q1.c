#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* alocanome(char *nome){
	int quant = strlen(nome);
	char* n = (char*) malloc((quant + 1)*sizeof(char));
	strcpy(n, nome);
	return n;
}

char* lenome(){
	char nome[41];
	printf("Digite o nome do aluno: ");
	scanf(" %40[^\n]", nome);
	return alocanome(nome);
}

float* alocanota(float *nota){
	int quant = sizeof(nota);
	float* n = (float*) malloc((quant + 1)*sizeof(float));
	n= nota;
	return n;
}

float* lenota(){
	float nota;
	printf("Digite o nota do aluno: ");
	scanf(" %f", &nota);
	return alocanota(&nota);
}

void imprimeaprovados(int q, char *nome[50], float nota[50]){
	for(int i = 0; i<q; i++){
		
		if(nota[i] >= 7.0)
			printf("APROVADO => aluno %s; nota %.2f\n", nome[i], nota[i]);
	}
}


int main(){
	int q;
	char *nome[50];
	float nota[50];
	
	printf("Digite a qnt de alunos: ");
	scanf("%i", &q);
	
	for(int i = 0; i < q; i++){
		nome[i]= lenome();
		
		nota[i] = *lenota();
	}
		
	
	imprimeaprovados(q, nome, nota);
	
	return 0;
}
