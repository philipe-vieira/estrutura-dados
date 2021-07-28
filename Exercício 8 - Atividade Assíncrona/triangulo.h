
typedef struct {
	float a, b, c;
} Triangulo;


Triangulo * tri_cria();

void tri_libera(Triangulo* tri);

void tri_acessa(Triangulo* tri, float* la, float* lb, float* lc);

int tri_valido(Triangulo* tri);

char* tri_tipo(Triangulo* tri);
