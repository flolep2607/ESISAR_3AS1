#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "fonctions.h"

#define YELLOW "\033[0;33m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define WHITE "\033[0;37m"
#define NORMAL "\033[0m"
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
#define max(X, Y) (((X) >= (Y)) ? (X) : (Y))



void afficherNotes(float *tableau_notes,int taille){
	
	float note_min = minimumNote(tableau_notes, taille);
	float note_max = maximumNote(tableau_notes, taille);
	float moyenne = calculMoyenne(tableau_notes, taille);
	
	int rang13point5=rechercherValeur(tableau_notes, taille, 13.5);
	int rang10point5=rechercherValeur(tableau_notes, taille, 10.5);;
	
	float variance = calculVariance(tableau_notes, taille);
	float ecartype = calculEcartType(tableau_notes, taille);
	
	printf("Note la plus basse: %s%.2f %s\n",YELLOW,note_min,WHITE);
	printf("Note la plus élevée: %s%.2f %s\n",YELLOW,note_max,WHITE);
	printf("Moyenne des étudiants: %s%f%s\n",YELLOW,moyenne,WHITE);
	printf("Variance: %s%f%s\n",YELLOW,variance,WHITE);
	printf("Ecart-type: %s%f%s\n",YELLOW,ecartype,WHITE);
	printf("Rang dans le tableau de la valeur 13,5: %s%d%s\n",YELLOW,rang13point5,WHITE);
	printf("Rang dans le tableau de la valeur 10,5: %s%d%s\n",YELLOW,rang10point5,WHITE);
	
}

float minimumNote(float *tableau_notes,int taille){
	float note_min=20.0;
	
	for(int i=0; i<taille; i++)
		note_min = min(note_min,tableau_notes[i]);
		
	return note_min;
}

float maximumNote(float *tableau_notes,int taille){
	float note_max=0.0;
	
	for(int i=0; i<taille; i++)
		note_max = max(note_max,tableau_notes[i]);
		
	return note_max;
}

float calculMoyenne(float *tableau_notes,int taille){
	float moyenne=0;
	
	for(int i=0; i<taille; i++)
		moyenne += tableau_notes[i];
	moyenne /= taille;
	
	return moyenne;
}

float calculVariance(float *tableau_notes,int taille){
	float moyenne = calculMoyenne(tableau_notes, taille);
	float sum=0;
	
	for(int i=0; i<taille; i++)
		sum+=powf(tableau_notes[i]-moyenne, 2);
	sum/=taille;
	
	return sum;
}

float calculEcartType(float *tableau_notes,int taille){
	
	return sqrtf( calculVariance(tableau_notes, taille));
}

int rechercherValeur(float *tableau_notes,int taille, float valeurachercher){
	int index=-1;
	
	for(int i=0; i<taille; i++)
		if (tableau_notes[i] == valeurachercher) index=i;
		
	return index;
}

void sort_in_array(float *tableau_notes,int taille,int *array){
	
	for(int i=0; i<10; i++) array[i]=0;//initialise le tableau à zéro
	
	for(int i=0; i<taille; i++){// parcoure les éléments du tableau de note
		for(int j=0; j<10; j++){// parcoure les intervalles des notes 
			if(tableau_notes[i]>(18-2*j)){
				// si note appartient [20, 18-2j[
				array[j]+=1;// on ajoute une étoile dans array à l'index correspondant à l'intervalle
				break;// le break fait que la note sera dans un unique intervalle.
			}
		}
		if(tableau_notes[i]==0)array[9]+=1;
	}
	
}

void set_text_color(int a){
	switch(a%7){
	case 0: printf("\033[0;39m");
	break;
	case 1: printf("\033[0;31m");
	break;
	case 2: printf("\033[0;32m");
	break;
	case 3: printf("\033[0;33m");
	break;
	case 4: printf("\033[0;34m");
	break;
	case 5: printf("\033[0;35m");
	break;
	case 6: printf("\033[0;36m");
	break;
	case 7: printf("\033[0;37m");
	break;
	}
}

void reset_text_color(){
	printf("\033[0m");
}

void histogramme_horizontal(float *tableau_notes,int taille){
	
	int array[10];
	sort_in_array(tableau_notes, taille, array);
	
	for(int i=0; i<10; i++){
		printf("%c %2d; %2d ] : ",(i==0) ? '[' : ']', 2*i, 2*i+2);
		printf("%d->%d  ",9-i ,array[9-i]);
		for(int j =0;j<array[9-i];j++)
			printf("	*");
		printf("\n");
	}
	
	
}

void histogramme_vertical(float *tableau_notes,int taille){
	
	int array[10];
	sort_in_array(tableau_notes, taille, array);
	
	int max=0;
	for(int i=0; i<10;i++) max=max(max,array[i]);
	
	bool matrix[10][max];
	for(int i=0; i<10;i++) for(int j=0; j<max; j++) {
		if(array[i]>j)
			matrix[i][j]=true;
		else
			matrix[i][j]=false;
	}
	
	for(int j=max-1; j>=0; j--){
		for(int i=9; i>=0; i--){
			set_text_color(9-i);
			if(matrix[i][j])
				printf("    *      ");
			else
				printf("           ");
		}
		printf("\n");
	}
	reset_text_color();
	printf("--------------------------------------------------------------------------------------------------------\n");
	for(int i=0; i<10; i++){
		set_text_color(i);
		printf("%c %2d; %2d ] ",(i==0) ? '[' : ']', 2*i, 2*i+2);
	}
	printf("\n");
}



