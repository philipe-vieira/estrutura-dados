#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int matricula;
	char nome[80];
	float nota1, nota2, frequencia;
} Aluno;

char* avalia(Aluno al){
	char* status = (char*) malloc(10*sizeof(char));
	
	float media = (al.nota1 + al.nota2)/2;
	
	if(media >= 7.0 && al.frequencia >=75.0)
		strcpy(status, "APROVADO");
	else
		strcpy(status, "REPROVADO");
	
	return status;
}

int main(){
	Aluno jo;
	
	jo.matricula = 12;
	jo.frequencia = 50;
	strcpy(jo.nome, "Joao");
	//jo.nome = "Joao";
	jo.nota1 = 7.5;
	jo.nota2 = 8.2;
	
	printf("Status -> %s", avalia(jo));
	
	return 0;
}
