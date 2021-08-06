#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* alt_char(char* cadeia ){
	int quant = strlen(cadeia);
	char* n = (char*) malloc((quant + 1)*sizeof(char));
		
	for(int i = 0; i < quant; i++){
		if(cadeia[i] >= 97 && cadeia[i] <= 122){
			cadeia[i] = cadeia[i] - 32;
		}
	}
	
	strcpy(n, cadeia);
	
	lreturn n;
}

int main(){
	char nome[41];
	printf("Digite o nome do aluno: ");
	scanf(" %40[^\n]", nome);
	
	printf("%s\n\n", nome);
	//alt_char(&nome);
	
	printf("%s", alt_char(&nome));
}
