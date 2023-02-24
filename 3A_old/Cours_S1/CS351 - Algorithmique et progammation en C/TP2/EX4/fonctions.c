#include <stdio.h>
#include "graphlib/graphlib.h"
#include "fonctions.h"

/* Pour dessinner un carré il suffit de tracer 
les quatres côtés à l'aide de la fonctions line()
(les calculs des coordonnées sont triviaux). */
void dessineCarre(int posx, int posy, int taille) {
	line(posx, posy,        posx-(taille/2), posy-(taille/2));
	line(posx, posy,        posx+(taille/2), posy-(taille/2));
	line(posx, posy-taille, posx-(taille/2), posy-(taille/2));
	line(posx, posy-taille, posx+(taille/2), posy-(taille/2));
}

/**Bonus: l'intérêt de cette fonction est d'être plus efficace que
la précédente en utilisant des variables au lieu de refaire
inutilement les mêmes calculs. */
void dessineCarre_less_op(int posx, int posy, int taille) {
	int demitaille = taille/2;
	int Ymilieu = posy-demitaille;
	line(posx, posy,        posx-demitaille, Ymilieu);
	line(posx, posy,        posx+demitaille, Ymilieu);
	line(posx, posy-taille, posx-demitaille, Ymilieu);
	line(posx, posy-taille, posx+demitaille, Ymilieu);
}

/**Bonus: Même interêt que la fonction précédente mais plus poussé. */
void dessineCarre_even_less_op(int posx, int posy, int taille) {
	int demitaille = taille/2;
	int Ymilieu = posy-demitaille;
	int Xmin = posx-demitaille;
	int Xmax = posx+demitaille;
	int Ymax = posy-taille;
	line(posx, posy, Xmin, Ymilieu);
	line(posx, posy, Xmax, Ymilieu);
	line(posx, Ymax, Xmin, Ymilieu);
	line(posx, Ymax, Xmax, Ymilieu);
}


/* Cette fonction est uniquement utiliser dans la fonction
dessineMosaique, elle permet de changer de couleur entre
carrés pour ressembler à la figure4. */
void swapcolor(int *color){// 0=>blue , else=>red
	if (*color == 0){
		set_blue();
		*color = 1;
	}else{
		set_red();
		*color = 0;
	}
}


/* Pour dessinner une mosaique il suffit d'itérer tous les carrés
en longueur et en largeur. On pensera à changer la couleur du pinceau
entre chaque carré. Il faut aussi faire attention au cas particulier où
le nombre de carré est paire en largeur, dans ce cas là la couleur 
du carré suivant doit être identique à celle du précédent.
*/
void dessineMosaique(int taille, int posx, int posy, int largeur, int hauteur){
	posx+=taille/2;//on rajoute tout de suite une demitaille pour atteindre la position du 1er carré
	int color = 0;
	int EOL_swap= (largeur%2)^1; //si la largeur est paire, on swap en fin de ligne. (l'expression est égale à 1 si %2 = 0)
	for(int i=0; i<hauteur; i++){
		for(int j=0; j<largeur; j++){
			swapcolor(&color);
			dessineCarre( posx+(j*taille), posy-(i*taille), taille); 
		}
		if (EOL_swap)swapcolor(&color);
	}
}

/**Bonus: Cette fonctions reprends le concept de la précédente mais préfère 
des additions successive plutôt qu'une multiplication à chaque itération.*/
void dessineMosaique_less_op(int taille, int posx, int posy, int largeur, int hauteur){
	posx+=taille/2;
	int color = 0;
	int EOL_swap= (largeur%2)^1;
	for(int i=0; i<hauteur; i++){
		for(int j=0; j<largeur; j++){
			swapcolor(&color);
			dessineCarre_less_op( posx, posy, taille); 
			posx+=taille;
		}
		if (EOL_swap)swapcolor(&color);
		posy-=taille;
		posx-=taille*(largeur);
	}
	
}


/* Pour tracer une mosaique à la position du clic de souris,
il suffit de récupérer les coordonnées du clic puis d'appeller
la fonction dessineMosaique() précédement définie avec les valeurs récupérée.
*/
void dessineMosaiqueAvecSouris(int taille, int largeur, int hauteur){
	int posx,posy;
	cliquer_xy(&posx, &posy);//référencement par addresse, pour la modification des variables
	dessineMosaique(taille, posx, posy, largeur, hauteur);
}

