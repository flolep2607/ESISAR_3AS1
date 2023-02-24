#include "module_tri_fichiers.h"


int main(){
	
	int T[10];
	int taille_tableau;
	taille_tableau = lireDonnees("test.txt",T);
	
	afficherTableau(T, taille_tableau);
	triABulles(T, taille_tableau);
	afficherTableau(T, taille_tableau);
	
	enregistrerDonnees("test_trie.txt", T, taille_tableau);
	
	return 0;
}