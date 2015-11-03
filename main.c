#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "carre.h"



int main(int argc, char const *argv[])
{
	
	laby_struct laby;
	int i;


	printf("Veuillez choisir la taille du labytinhe en X : ");
	scanf("%d", &laby.size_line);
	fflush2();
	printf("Veuillez choisir la taille du labytinhe en Y : ");
	scanf("%d", &laby.size_col);
	fflush2();

	// On reserve de la memoire pour le tableau du laby
	laby.matrice = malloc(laby.size_line * sizeof(int*));
	// On verifie si le malloc a reussi
	if (laby.matrice == NULL)
	{
		perror("Probleme allocation dynamique");
		exit(-1);
	}

	// On créer le tableau de tableau
	for (i = 0; i< laby.size_line;i++)
	{
		laby.matrice[i] = malloc(laby.size_col * sizeof(int));
	}
	
	initialise(&laby);
	affichage(&laby);
	remplissage(&laby);
	start_end(&laby);
	affichage(&laby);

	
	// remplissage(mat, taille_tab);
	// verif_ligne(mat, taille_tab);
	// verif_col(mat, taille_tab);
	// verif_diagonal(mat, taille_tab);

	return 1;
}