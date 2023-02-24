#define NBMAX 100

typedef struct {
	float coeff ;/* coefficient du terme */
	int degre ; /* degré du terme */
} Terme ;

typedef Terme Polynome[NBMAX];

void addPolynomes(Polynome p1, Polynome p2, Polynome res);
void printPolynome(Polynome p);
