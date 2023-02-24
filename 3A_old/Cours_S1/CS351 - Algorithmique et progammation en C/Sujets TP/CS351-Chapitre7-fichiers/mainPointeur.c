#include <stdlib.h>


int main(int argc, char * argv[]) {

	int a, b, c;
	int *p1, *p2;

	/* Initialisation des variables */
	a = 1;
	b = 2;
	c = 3;

	/* Manipulation des pointeurs */
	p1 = &a;
	p2 = &c;

	*p1 = *p2;
	(*p2)++;

	p1 = p2;
	p2 = &b;
	
	*p2 = *p1 - 2 * *p2;
	(*p2)--;
	*p1 = *p2 - c;

	a = (2 + *p2) * *p1;
	p2 = &c;

	*p2 = *p1 / *p2;
	*p1 = a + b;

	a += *p1;
	b = *p1 + *p2;

	*p1 = 2 * a;

	a = *p2;

	*p2 = *p1 - *p2;
	*p1 = 1 - c;
	*p2 += *p1 + a;
	
	p2 = p1 = &a;
	p2++;
	p1 += 2;
	c = p2 == &c;
	
	p1 = NULL;
	return 0;
}
