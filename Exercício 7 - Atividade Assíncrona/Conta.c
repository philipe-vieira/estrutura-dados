#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int numero;
	float saldo;
} Conta;

void inicializa (int qnt, Conta* conta[qnt]) {
	for(int i=0; i < qnt; i++){
		conta[i] = NULL;
	}
}

Conta* alocaConta(){
	Conta* conta = malloc(1* sizeof(Conta));
	int num;
	
	printf("Digite o numero da conta => ");
	scanf("%d", &num);
	conta->numero = num;
	conta->saldo = 0;
	
	return conta;
}

void insereConta(int qnt, Conta* conta[qnt]){
	for(int i=0; i < qnt; i++){
		if(conta[i] == NULL){
			conta[i] = (Conta *) malloc(1* sizeof(Conta));
			conta[i] = alocaConta();
			printf("Conta inserida com sucesso!!!\n");
			i = qnt;
			//printf("%d", conta[i]->numero);
		}
	}
}

void deposito(int qnt, Conta* conta[qnt]){
	int numeroConta;
	float valor;
	
	printf("digite o numero da conta:");
	scanf("%d", &numeroConta);
	printf("digite o valor do deposito:");
	scanf("%f", &valor);
	
	for(int i=0; i < qnt; i++){
		printf("%d\n", conta[i]->numero );
		if(conta[i]->numero == numeroConta){
			conta[i]->saldo += valor;
			printf("Deposito realizado!!!\n\n");
			i = qnt;
		} else if (i == (qnt-1)){
			printf("Conta nao encontrada!!!\n\n");
		}
	}
}

void saque(int qnt, Conta* conta[qnt]){
	int numeroConta;
	float valor;
	
	printf("digite o numero da conta:");
	scanf("%d", &numeroConta);
	printf("digite o valor do saque:");
	scanf("%f", &valor);
	
	for(int i=0; i < qnt; i++){
		if(conta[i]->numero == numeroConta){
			conta[i]->saldo -= valor;
			printf("Saque realizado!!!\n\n");
			i = qnt;
		} else if (i == (qnt-1)){
			printf("Conta nao encontrada!!!\n\n");
		}
	}
}

void imprime(int qnt, Conta* conta[qnt]){
	printf("-------------------------------------\n");
	for(int i=0; i < qnt; i++){
		if(conta[i] != NULL){
			printf("Conta: %i; Saldo: %.2f\n", conta[i]->numero, conta[i]->saldo);
		}
	}
	printf("-------------------------------------\n");
}

void menu(){
	printf("1 - Criar Contas; \n2 - Depositar; \n3 - Sacar; \n4 - Imprimir; \n5 - Sair;\n\n");
}

int main(){
	int qnt, resp;
	printf("Digite a quantidade de contas p/ manipular => ");
	scanf("%d", &qnt);
	
	Conta* contas[qnt];
	inicializa(qnt, contas);
	do{
		menu();
		scanf("%d", &resp);
		
		switch(resp){
			case 1:
				insereConta(qnt, contas);
				break;
			case 2:
				deposito(qnt, contas);
				break;
			case 3:
				saque(qnt, contas);
				break;
			case 4:
				imprime(qnt, contas);
				break;
			default:
				break;
		}
		printf("\n\n\n\n\n");
		system("pause");
		system("cls||clear");
		//system("clear");
	} while (resp != 5);
	imprime(qnt, contas);
	
	free(contas);
	free(qnt);
	free(resp);
	return 0;
}

