#include <stdio.h>
#include "fonctions.h"

#define NB_NOTES 5

int main() {
	
	float tableau_notes[20];
	tableau_notes[0]=12.0;
	tableau_notes[1]=13.5;
	tableau_notes[2]=8.5;
	tableau_notes[3]=14.7;
	tableau_notes[4]=6.0;
	
	afficherNotes(tableau_notes, NB_NOTES);
	
	
	tableau_notes[0]=0;
	tableau_notes[1]=13.5;
	tableau_notes[2]=8.5;
	tableau_notes[3]=13.7;
	tableau_notes[4]=20;
	tableau_notes[5]=12.0;
	tableau_notes[6]=8.5;
	tableau_notes[7]=17;
	tableau_notes[8]=11;
	tableau_notes[9]=10;
	tableau_notes[10]=9.5;
	tableau_notes[11]=4;
	tableau_notes[12]=14;
	tableau_notes[13]=13.5;
	tableau_notes[14]=12;
	tableau_notes[15]=1;
	tableau_notes[16]=15;
	tableau_notes[17]=10.5;
	tableau_notes[18]=7.5;
	tableau_notes[19]=9.5;
	
	histogramme_horizontal(tableau_notes, 20);
	
	histogramme_vertical(tableau_notes, 20);
	
	return 0;
}