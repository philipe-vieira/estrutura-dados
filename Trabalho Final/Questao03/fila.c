#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"


typedef struct paciente{
    char* nome;
    char* cpf;
    char* plano;
    struct paciente* prox;
} Paciente;

typedef struct fila{
	int atendidos;
	Paciente* ini;
	Paciente* fim;
} Fila;


Fila * fila_cria (void){
	Fila * f = (Fila *) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	f->atendidos = 0;
	return f;
}

void fila_libera (Fila * f){
	Paciente * q = f->ini;
	
	while(q != NULL){
		Paciente * prox = q->prox;
		free(q);
		q = prox;
	}
	free(f);
}

void fila_insere (Fila * f){
	int ordem;
	char* nome = (char*) malloc(41*sizeof(char));
	printf("Digite o nome do paciente: ");
	scanf(" %40[^\n]", nome);
	
	char* cpf = (char*) malloc(41*sizeof(char));
	printf("Digite o cpf do paciente: ");
	scanf(" %40[^\n]", cpf);
	
	char* plano = (char*) malloc(41*sizeof(char));
	printf("Digite o plano do paciente: ");
	scanf(" %40[^\n]", plano);
	
	Paciente * novo = (Paciente *)malloc(sizeof(Paciente));
	novo->nome = nome;
	novo->cpf = cpf;
	novo->plano = plano;
	novo->prox = NULL;
	
	if(f->fim != NULL){
		f->fim->prox = novo;
		ordem = fila_tamanho(f);
	}else{
		f->ini = novo;
		ordem = 1;
	}
	f->fim = novo;
	printf("Paciente e o %i da fila.\n", ordem);
}

char* fila_retira (Fila * f){
	char * nome_paciente;
	
	if (fila_vazia(f)) {
		printf("Fila Vazia.\n");
		return NULL;
	}
	nome_paciente = f->ini->nome;
	f->ini = f->ini->prox;
	f->atendidos++;
	
	if(f->ini == NULL){
		f->fim = NULL;
	}
	return nome_paciente;
}

int fila_vazia(Fila * f){
	return (f->ini == NULL);
}

void lista_imprime(Fila *f){
	if(fila_vazia(f)){
		printf("FILA VAZIA\n");
		return;
	} else {
		Paciente * atual = f->ini;
		int cont = 0;
		while(atual != NULL && cont < 10){
			printf("Nome %s\n", atual->nome);
			atual = atual->prox;
			cont++;
		}
		if(cont >= 10){
			printf("[...]\n");
		}
		free(atual);
	}
}

void menu(){
	printf( "1. Incluir paciente\n");
	printf( "2. Realizar chamada\n");
	printf( "3. Consultar a posicao atual de um paciente\n");
	printf( "4. Listar a quantidade de pacientes atendidos\n");
	printf( "5. Sair\n->");
}

int fila_tamanho(Fila * f){
	Paciente * atual = f->ini;
	int tam = 0;
	while(atual != NULL){
		atual = atual->prox;
		tam++;
	}
	return tam;
}

void fila_busca(Fila * fila, char* paciente){
	Paciente* p;
	int posicao = 1;
	for (p = fila->ini; p != NULL; p = p->prox){
		if (strcmp( p->nome, paciente) == 0){
			printf("Paciente %s esta na posicao %i!\n", p->nome, posicao);
			return;
		}
		posicao++;
	}
	printf("Elemento nao foi encontrado!\n");
}

void fila_atendidos(Fila * f){
	printf("%i pacientes atendidos...\n", f->atendidos);
}













