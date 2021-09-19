#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

int main(){
	Arv* a = arv_cria(
		        arv_cria(
					arv_criavazia(),
					arv_cria( arv_criavazia(), arv_criavazia())
				),
				arv_cria(
					arv_cria( arv_criavazia(), arv_criavazia()),
					arv_cria( arv_criavazia(), arv_criavazia())
				)
			);
	arv_imprime(a);
	
	printf("\n\n");
	char* nome = (char*) malloc(41*sizeof(char));
	printf("Digite o nome do elemento procurado: ");
	scanf(" %40[^\n]", nome);
	
	if (arv_pertence(a, nome) == 0)
		printf("Elemento nao encontado\n");
	else
		printf("Elemento encontrado\n\n");
		
	set_dir(a, arv_libera(get_dir(a)));
	
	arv_imprime(a);
	return 0;
}
