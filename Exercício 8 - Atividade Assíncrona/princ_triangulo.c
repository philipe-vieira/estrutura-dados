#include <stdio.h>
#include <stdlib.h>
#include "triangulo.h"

int main(){
	Triangulo* t = tri_cria();
	float la; float lb; float lc;
	
	printf("Tipo de triangulo -> %s\n\n", tri_tipo(t));
	
	tri_acessa(t, &la, &lb, &lc);
	
	printf("Lado a %.2f\n", la);
	printf("Lado b %.2f\n", lb);
	printf("Lado c %.2f\n", lc);
	
	tri_libera(t);
	
	
	printf("\nTipo de triangulo -> %s\n\n", tri_tipo(t));
	
	return 0;
}


