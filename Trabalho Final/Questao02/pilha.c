#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
   char* livro;
   struct lista* prox;
} Lista;


typedef struct pilha{
	Lista* prim;
} Pilha;

int pilha_vazia(Pilha * p){
	return (p->prim == NULL);
}

void pilha_libera(Pilha * p){
	if(pilha_vazia(p)){
		printf("PILHA VAZIA\n");
	} else {
		Lista * atual = p->prim;
		
		while(atual != NULL){
			Lista * prox = atual->prox;
			free(atual);
			atual = prox;
		}
		free(p);
		p->prim = NULL;
		printf("LIBERADO!!!\n");
	}
}

Pilha * pilha_cria(){
	Pilha * p = (Pilha *)malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

Pilha * pilha_push(Pilha *pil){
	Lista * novo = (Lista*)malloc(sizeof(Lista));
	
	char* nome = (char*) malloc(41*sizeof(char));
	printf("Digite o nome do livro: ");
	scanf(" %40[^\n]", nome);
	
	novo->livro = nome;
	novo->prox = pil->prim;
	pil->prim = novo;
	return pil;
}

char * pilha_pop(Pilha *pilha){
	char * livro = NULL;
	
	if(pilha_vazia(pilha)){
		printf("PILHA VAZIA\n");
	} else {
		Lista * aux = pilha->prim;
		livro = pilha->prim->livro;
		free(pilha);
		pilha->prim = aux->prox;
		free(aux);		
	}
	return livro;
}

void pilha_topo(Pilha * p){
	if(pilha_vazia(p)){
		printf("PILHA VAZIA\n");
		return 0;
	} else {
		printf("Livro no topo -> %s\n", p->prim->livro );
	}
}

void menu(){
	printf("1 - Inserir um elemento no topo (push);\n");
	printf("2 - Remover o elemento do topo (pop);\n");
	printf("3 - Buscar elemento do topo;\n->");
}




