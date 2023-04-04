#include <stdio.h>
#include "graphlib.h"
#include "fonction.h"


void fill_carre(int x1,int y1,int Taille){
	int x2=x1+Taille;
	int y3=y1-Taille;
	fill_triangle(x1, y1, x2, y1, x1, y3);
	fill_triangle(x2, y3, x2, y1, x1, y3);
	
	line(x1, y1, x2, y1);
	line(x1, y1, x1, y3);
	line(x2, y3, x2, y1);
	line(x2, y3, x1, y3);
	
	// printf("x2:%d y2:%d\n",x2,y3);
}

void DessinerUnTriangleDeSierpinski(int n,int x,int y,int Taille){
	// printf("x:%d y:%d\n",x,y);
	if(n==0) fill_carre(x,y,Taille);
	else{
		int demitaille=Taille/2;
		DessinerUnTriangleDeSierpinski(n-1,x+demitaille,y,demitaille);
		DessinerUnTriangleDeSierpinski(n-1,x,y-demitaille,demitaille);
		DessinerUnTriangleDeSierpinski(n-1,x,y,demitaille);
	}
}