#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "carre.c"


int main(int argc, char const *argv[])
{
	
	int taille_tab;
	// NMAX définit dans le .h
	char mat[NMAX][NMAX];

	printf("Veuillez choisir la taille du labytinhe : ");
	scanf("%d", &taille_tab);
	
		initialise(mat, taille_tab);
		affichage(mat, taille_tab);
		

		
		// remplissage(mat, taille_tab);
		// verif_ligne(mat, taille_tab);
		// verif_col(mat, taille_tab);
		// verif_diagonal(mat, taille_tab);

	return 1;
}