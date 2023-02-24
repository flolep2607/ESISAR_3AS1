

//typedef struct mem_bloc mem_bloc;
struct mem_bloc {
	unsigned int base;
	uint8_t bloc[16];
	struct mem_bloc * suivant;
};

struct mem_bloc* Memoire = (struct mem_bloc*) malloc(sizeof(struct mem_bloc));
Memoire->base = 0;
Memoire->suivant = NULL;

int inst2hex(char * name, char * arg1, char * arg2, char * arg3);
void compile_segment(char *nomfichier);