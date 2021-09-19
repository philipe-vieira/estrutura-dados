typedef struct arv Arv;

Arv* arv_criavazia();

Arv* arv_cria(Arv* e, Arv* d);

int arv_vazia(Arv* a);

Arv* arv_libera(Arv* a);

int arv_pertence(Arv* a, char *c);

void arv_imprime(Arv* a);

Arv* get_esq(Arv* a);

Arv* get_dir(Arv* a);

void set_esq(Arv* a, Arv* esq);

void set_dir(Arv* a, Arv* dir);
