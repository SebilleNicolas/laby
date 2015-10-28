#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "carre.c"


int main(int argc, char const *argv[])
{
	
	int taille_tab_ligne;
	int taille_tab_col;
	// NMAX définit dans le .h
	char mat[NMAX][NMAX];

	printf("Veuillez choisir la taille du labytinhe en X : ");
	scanf("%d", &taille_tab_ligne);
	printf("Veuillez choisir la taille du labytinhe en Y : ");
	scanf("%d", &taille_tab_col);
	
		initialise(mat, taille_tab_ligne , taille_tab_col);
		affichage(mat, taille_tab_ligne , taille_tab_col);
		remplissage(mat,taille_tab_ligne , taille_tab_col);
		affichage(mat, taille_tab_ligne , taille_tab_col);

		
		// remplissage(mat, taille_tab);
		// verif_ligne(mat, taille_tab);
		// verif_col(mat, taille_tab);
		// verif_diagonal(mat, taille_tab);

	return 1;
}