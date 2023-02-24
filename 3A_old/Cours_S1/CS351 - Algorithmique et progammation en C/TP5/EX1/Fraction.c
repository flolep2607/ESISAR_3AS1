#include <stdio.h>
#include "Fraction.h"
#include "libmath.h"

void printFraction(Fraction f){
	printf("(%d/%d)",f.num,f.den);
}

void traiterSigne(Fraction *f){
	if(f->den < 0){
		f->den*=-1;
		f->num*=-1;
	}
}

void devenirIrreductible(Fraction *f){
	int a=pgcd(f->num, f->den);
	f->num/=a;
	f->den/=a;
}

void inverserFraction(Fraction *f){
	int tmp = f->num;
	f->num = f->den;
	f->den = tmp;
}

void addFraction(Fraction f1, Fraction f2) {
	Fraction res;
	traiterSigne(&f1);
	traiterSigne(&f2);
	
	res.den = ppcm(f1.den, f2.den);
	res.num = f1.num * quotient(res.den, valeurAbsolue(f1.den)) + f2.num * quotient(res.den, valeurAbsolue(f2.den));
	
	devenirIrreductible(&res);
	
	printFraction(res);
}

void subFraction(Fraction f1, Fraction f2){
	f2.num*=-1;
	addFraction(f1, f2);
}

void mulFraction(Fraction f1, Fraction f2){
	Fraction res;
	traiterSigne(&f1);
	traiterSigne(&f2);
	
	res.den = f1.den * f2.den;
	res.num = f1.num * f2.num;
	
	//devenirIrreductible(&res);
	devenirIrreductible(&res);
	
	printFraction(res);
}

void divFraction(Fraction f1, Fraction f2) {
	inverserFraction(&f2);
	mulFraction(f1, f2);
}

