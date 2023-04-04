#include <stdio.h>
#include <unistd.h>
#include "graphlib.h"
#include "pile.h"

#define max(X, Y) (((X) >= (Y)) ? (X) : (Y))
#define TAILLE_PIECE_X 40
#define TAILLE_PIECE_Y 20
#define TAILLE_PILIER 10
#define ECART_BLOC TAILLE_PIECE_X/2
#define COULEUR_CONTOUR 'n'
#define COULEUR_BLOC 'w' 

#define DARK_MODE


char other(char p1, char p2){
	if(p1=='A'){
		return (p2=='B') ? 'C':'B' ;
	}else if(p1=='B'){
		return (p2=='A') ? 'C':'A' ;
	}else{
		return (p2=='B') ? 'A':'B' ;
	}
}

/** --- HANOI PRINCIPAL --- **/
void hanoi(int k, char p1, char p2){
	if( k == 1)
		printf("move piece %d from %c to %c\n",k,p1,p2);
	else{
		char p3 = other(p1,p2);
		hanoi(k-1, p1, p3);
		printf("move piece %d from %c to %c\n",k,p1,p2);
		hanoi(k-1, p3,p2);
	}
}	

void fill_rect(int x1,int y1,int x2,int y2){
	fill_triangle(x1, y1, x2, y1, x1, y2);
	fill_triangle(x2, y2, x2, y1, x1, y2);
	//bonus
	switch (COULEUR_CONTOUR) {
		case 'w': set_white(); break;
		case 'n': set_black(); break;
		case 'b': set_blue(); break;
		case 'r': set_red(); break;
		case 'g': set_green(); break;
		case 'y': set_yellow(); break;
		default: set_black();
	}//fin du bonus
	line(x1, y1, x2, y1);
	line(x1, y1, x1, y2);
	line(x2, y2, x2, y1);
	line(x2, y2, x1, y2);
	
}


void rect_couleur(int x1,int y1,int x2,int y2,char couleur){
	switch (couleur) {
		case 'w': set_white(); break;
		case 'n': set_black(); break;
		case 'b': set_blue(); break;
		case 'r': set_red(); break;
		case 'g': set_green(); break;
		case 'y': set_yellow(); break;
		default: set_white();
	}
	fill_rect(x1, y1, x2, y2);
	set_black();
}

void bloc_couleur_du_milieu(int milieu, int y, int largeur, int hauteur, char couleur){
	int x1=milieu-largeur/2;
	int x2=milieu+largeur/2;
	int y2=y-hauteur;
	rect_couleur(x1,y,x2,y2,couleur);
}

void draw_tour_from_pile(int milieu, int k, pileInt tour){
	int base_level = (k+3)* TAILLE_PIECE_Y - (TAILLE_PIECE_Y/2);
	
	bloc_couleur_du_milieu(milieu, base_level, TAILLE_PILIER, (k+1)*TAILLE_PIECE_Y, 'r');
	
	for(int i=0; i<tour->pp; i++){
		// printf("i:%d",i);
		// printf(" hauteur:%d",base_level-i*TAILLE_PIECE_Y);
		// printf(" pile[i]:%d\n",tour->pile[i]);
		bloc_couleur_du_milieu(milieu, base_level-i*TAILLE_PIECE_Y, TAILLE_PIECE_X+tour->pile[i+1]*ECART_BLOC, TAILLE_PIECE_Y, COULEUR_BLOC);
	}
}

void draw_hanoi(int k,pileInt tour1,pileInt tour2,pileInt tour3){
	int taille_base_x= TAILLE_PIECE_X + k * ECART_BLOC;
	int pos_tour_1 = (3 + tour1->pile[0] *5) * (taille_base_x / 4);
		// printf("%d\n",pos_tour_1);
	int pos_tour_2 = (3 + tour2->pile[0] *5) * (taille_base_x / 4);
		// printf("%d\n",pos_tour_2);
	int pos_tour_3 = (3 + tour3->pile[0] *5) * (taille_base_x / 4);
		// printf("%d\n",pos_tour_3);
	
	//clear screen
	clear_screen();
	//draw tours (from pile)
	draw_tour_from_pile(pos_tour_1 , k, tour1);
	draw_tour_from_pile(pos_tour_2 , k, tour2);
	draw_tour_from_pile(pos_tour_3 , k, tour3);
	
	
}

void move_piece(pileInt from,pileInt dest){
	int tmp = depiler(from);
	empiler(dest, tmp);
}


void hanoi_graphique_aux(int k,int n,pileInt tour_from, pileInt tour_dest, pileInt tour_other){
	if( n == 1){
		move_piece( tour_from, tour_dest);
		draw_hanoi(k, tour_from, tour_dest, tour_other);
		usleep(10000);
		//cliquer();
	}else{
		hanoi_graphique_aux(k, n-1, tour_from, tour_other, tour_dest);
		move_piece( tour_from, tour_dest);
		draw_hanoi(k, tour_from, tour_dest, tour_other);
		usleep(10000);
		//cliquer();
		hanoi_graphique_aux(k, n-1, tour_other, tour_dest, tour_from);
	}
}

void hanoi_graphique(int k, char p1, char p2){
	
	
	pileInt tour1 = creerPile();
	pileInt tour2 = creerPile();
	pileInt tour3 = creerPile();
	tour1->pile[0]=0;// Pile Hack: on écrit l'index de
	tour2->pile[0]=1;// position à l'index 0 car il est inutilisé
	tour3->pile[0]=2;// ( dangereux mais pratique ! )
	printf("taille fenetre:\t%d\t%d\n",(k+3)*TAILLE_PIECE_Y ,4*(TAILLE_PIECE_X+k*TAILLE_PIECE_X/10));
	gr_inits_w(4*(TAILLE_PIECE_X+k*ECART_BLOC), (k+3)*TAILLE_PIECE_Y, "Hanoi");
	// gr_inits_w(416,100,"test");
	#ifdef DARK_MODE
		graph_inv();
	#endif
	
	pileInt to_empile;
	switch (p1) {
		case 'C': to_empile=tour3; break;
		case 'B': to_empile=tour2; break;
		default:  to_empile=tour1; break;
	}
	
	for(int i=k; i!=0; i--)
		empiler(to_empile,i);
	
	pileInt dest;
	switch (p2) {
		case 'C': dest=tour3; break;
		case 'B': dest=tour2; break;
		default:  dest=tour1; break;
	}
	
	pileInt tmp;
	switch (other(p1,p2)) {
		case 'C': tmp=tour3; break;
		case 'B': tmp=tour2; break;
		default:  tmp=tour1; break;
	}
	
	draw_hanoi(k, tour1, tour2, tour3);
	cliquer();
	
	hanoi_graphique_aux(k, k, to_empile, dest, tmp);
	cliquer();
}


