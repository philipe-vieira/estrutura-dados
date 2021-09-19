#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista2{
   char* nome_cliente;
   struct lista* ant;
   struct lista* prox;
} Lista2;


typedef struct fila2{
	Lista2* ini;
	Lista2* fim;
} Fila2;

// INICIO FUNCOES AUXILIARES
static Lista2* insere2_ini (Lista2 * inicial, char* valor){
	Lista2* novo = (Lista2 *)malloc(sizeof(Lista2));
	novo->nome_cliente = valor;
	novo->prox = inicial;
	novo->ant = NULL;
	
	if(inicial != NULL){
		inicial->ant = novo;
	}
	return novo;
}

static Lista2* insere2_fim (Lista2 * fim, char* valor){
	Lista2* novo = (Lista2 *)malloc(sizeof(Lista2));
	novo->nome_cliente = valor;
	novo->prox = NULL;
	novo->ant = fim;
	
	if(fim != NULL){
		fim->prox = novo;
	}
	return novo;
}

static Lista2* retira2_ini (Lista2 * ini){
	Lista2* p = ini->prox;
	if (p != NULL)
		p->ant = NULL;
	free(ini);
	return p;
}

static Lista2* retira2_fim (Lista2 * fim){
	Lista2* p = fim->ant;
	if (p != NULL)
		p->prox = NULL;
	free(fim);
	return p;
}
// FIM FUNCOES AUXILIARES


Fila2 * fila2_cria (void){
	Fila2 * f = (Fila2 *) malloc(sizeof(Fila2));
	f->ini = f->fim = NULL;
	return f;
}

void fila2_insere_ini (Fila2 * f){
	char* nome = (char*) malloc(41*sizeof(char));
	printf("Digite um nome: ");
	scanf(" %40[^\n]", nome);
	
	f->ini = insere2_ini(f->ini, nome);
		
	if(f->fim == NULL)
		f->fim = f->ini;
}
void fila2_insere_fim (Fila2 * f){
	char* nome = (char*) malloc(41*sizeof(char));
	printf("Digite um nome: ");
	scanf(" %40[^\n]", nome);
	
	f->fim = insere2_fim(f->fim, nome);
		
	if(f->ini == NULL)
		f->ini = f->fim;
}


char* fila2_retira_ini (Fila2 * f){
	char * v;
	if (fila2_vazia(f)) {
		printf("Fila Vazia.\n");
		exit(0);
	}
	v = f->ini->nome_cliente;
	f->ini = retira2_ini(f->ini);
	
	if(f->ini == NULL){
		f->fim = NULL;
	}
	return v;
}
char* fila2_retira_fim (Fila2 * f){
	char * v;
	if (fila2_vazia(f)) {
		printf("Fila Vazia.\n");
		exit(0);
	}
	v = f->fim->nome_cliente;
	f->fim = retira2_fim(f->fim);
	
	if(f->fim == NULL){
		f->ini = NULL;
	}
	return v;
}

int fila2_vazia(Fila2 * f){
	return (f->ini == NULL);
}

void fila2_libera (Fila2 * f){
	Lista2 * q = f->ini;
	
	while(q != NULL){
		Lista2 * prox = q->prox;
		free(q);
		q = prox;
	}
	f->ini = f->fim = NULL;
}


void fila2_imprime_ini_fim(Fila2 *f){
	if(fila2_vazia(f)){
		printf("FILA VAZIA\n");
		return;
	} else {
		Lista2 * atual = f->ini;
		int cont = 0;
		while(atual != NULL && cont < 10){
			printf("%d - Nome %s\n", cont+1, atual->nome_cliente );
			atual = atual->prox;
			cont++;
		}
		if(cont >= 10){
			printf("[...]\n");
		}
		free(atual);
	}
}
void fila2_imprime_fim_ini(Fila2 *f){
	if(fila2_vazia(f)){
		printf("FILA VAZIA\n");
		return;
	} else {
		Lista2 * atual = f->fim;
		int cont = 0;
		while(atual != NULL && cont < 10){
			printf("%d - Nome %s\n", cont+1, atual->nome_cliente );
			atual = atual->ant;
			cont++;
		}
		if(cont >= 10){
			printf("[...]\n");
		}
		free(atual);
	}
}


void menu(){
	printf( "1 - Inserir Cliente no Início da Fila de Atendimento\n");
	printf("2 - Inserir Cliente no Final da Fila de Atendimento\n");
	printf("3 - Chamar Cliente do Início da Fila para Atendimento\n");
	printf("4 - Chamar Cliente do Final da Fila para Atendimento\n");
	printf("5 - Imprimir Nome dos Clientes do Início ao Fim da Fila de Atendimento\n");
	printf("6 - Imprimir Nome dos Clientes do Fim ao Inicio da Fila de Atendimento\n");
	printf("7 - Sair\n");
	printf("---> ");
}

















