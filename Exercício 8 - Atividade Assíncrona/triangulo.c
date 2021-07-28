#include <stdlib.h>
#include "triangulo.h"

Triangulo * tri_cria(){
	Triangulo * tri = malloc(sizeof(Triangulo));
	
	printf("Lado a -> ");
	scanf("%f", &tri->a);
	printf("Lado b -> ");
	scanf("%f", &tri->b);
	printf("Lado c -> ");
	scanf("%f", &tri->c);
	//tri->a = a;
	//tri->b = b;
	//tri->c = c;
	
	return tri;
}

void tri_libera(Triangulo* tri){
	free(tri);
}

void tri_acessa(Triangulo* tri, float* la, float* lb, float* lc){
	*la = tri->a;
	*lb = tri->b;
	*lc = tri->c;
}

/*
void tri_acessa(Triangulo* t, float* a, float* b, float* c){
	*a = t->a;
	*b = t->b;
	*c = t->c;
}
*/

int tri_valido(Triangulo* tri){
	if((tri->a+tri->b) <= tri->c || (tri->a+tri->c) <= tri->b || (tri->b+tri->c) <= tri->a)
		return 0;
	else
		return 1;
		
}

char* tri_tipo(Triangulo* tri){
	char* tipo = (char*) malloc(10*sizeof(char));
	
	if(tri_valido(tri) == 0){
		tipo = "Invalido";
		return tipo;
	}
	
	if(tri->a == tri->b && tri->b == tri->c){
		tipo = "Equilatero";
		//printf("Triangulo %s", tipo);
	} else if (tri->a != tri->b && tri->b != tri->c && tri->c != tri->a){
		tipo = "Escaleno";
		//printf("Triangulo %s", tipo);
	} else {
		tipo = "Isosceles";
		//printf("Triangulo %s", tipo);
	}
	
	return tipo;
}

