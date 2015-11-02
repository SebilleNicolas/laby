#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "carre.h"
#include "test_unitaire_etape_1.h"



int main(int argc, char const *argv[])
{
	
	laby_struct laby;


	printf("Veuillez choisir la taille du labytinhe en X : ");
	scanf("%d", &laby.size_line);
	fflush2();
	printf("Veuillez choisir la taille du labytinhe en Y : ");
	scanf("%d", &laby.size_col);
	fflush2();

	laby.matrice = malloc(laby.size_line * sizeof(int*));
	if (laby.matrice == NULL)
	{
		perror("Probleme allocation dynamique");
		exit(-1);
	}
	int i;
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