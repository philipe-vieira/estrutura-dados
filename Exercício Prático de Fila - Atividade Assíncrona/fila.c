#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista{
   char* nome_cliente;
   struct lista* prox;
} Lista;


typedef struct fila{
	Lista* ini;
	Lista* fim;
} Fila;


Fila * fila_cria (void){
	Fila * f = (Fila *) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere (Fila * f){
	char* nome = (char*) malloc(41*sizeof(char));
	printf("Digite um nome: ");
	scanf(" %40[^\n]", nome);
	
	Lista * n = (Lista *)malloc(sizeof(Lista));
	n->nome_cliente = nome;
	n->prox = NULL;
	
	if(f->fim != NULL)
		f->fim->prox = n;
	else
		f->ini = n;
	f->fim = n;
}

char* fila_retira (Fila * f){
	char * v;
	
	if (fila_vazia(f)) {
		printf("Fila Vazia.\n");
		exit(0);
	}
	
	v = f->ini->nome_cliente;
	f->ini = f->ini->prox;
	
	if(f->ini == NULL){
		f->fim = NULL;
	}
	
	return v;
}

int fila_vazia(Fila * f){
	return (f->ini == NULL);
}

void fila_libera (Fila * f){
	Lista * q = f->ini;
	
	while(q != NULL){
		Lista * prox = q->prox;
		free(q);
		q = prox;
	}
	f->ini = f->fim = NULL;
}


void lista_imprime(Fila *f){
	if(fila_vazia(f)){
		printf("FILA VAZIA\n");
		return;
	} else {
		Lista * atual = f->ini;
		int cont = 0;
		while(atual != NULL && cont < 10){
			printf("Nome %s\n", atual->nome_cliente );
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
	printf( "1 - Inserir Cliente na Fila de Atendimento\n2 - Chamar Cliente para Atendimento\n3 - Imprimir Nome dos Clientes\n4 - Liberar\n5 - Sair\n--->   ");
}

















