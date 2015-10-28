
#include <stdio.h>
#include <stdlib.h>
#include "carre.h"

void initialise( char matrice[NMAX][NMAX], int taille_tab_ligne , int taille_tab_col)
{	
	int ligne=0;
	int col=0;
	// Compteur pour mettre les chiffres dans les cases
	int cpt = 1;
	// Variable qui verifie qu'on est sur une colonne/ligne impair
	int calc_l,calc_c;
	// On initialise toutes les cases a 0
	for (ligne = 0; ligne < taille_tab_ligne; ligne++)
	{
		for(col = 0; col < taille_tab_col; col++)
		{
			calc_l =ligne%2;
			calc_c = col%2;
			// On est sur une colonne et une ligne avec chiffre
			// Impair.
			if (calc_l && calc_c == 1)
			{
				matrice[ligne][col] = cpt;
				cpt ++;
			}
			else
			{
				matrice[ligne][col] = 0;
			}
		}
	}
}

int impair(int entier)
{
	int calc = 0;
	calc = entier %2;
	// 0 ==> pair
	int r = 0;
	if(calc == 1)
	{
		//Nombre impair
		r = 1;
	}
	return r;
}

void remplissage(char matrice[NMAX][NMAX],int taille_tab_ligne , int taille_tab_col)
{
	int ligne = 0;
	srand(time(NULL));
	int col=0;
	int nb_iteration = 0;
	int nb_max_iteration = ((taille_tab_ligne/2) * (taille_tab_col/2)-1);

	
	int x = rand()%taille_tab_ligne-1;
	int y = rand()%taille_tab_col-1;

	while(nb_iteration < nb_max_iteration)
	{
		x = rand() % ((taille_tab_ligne-2)) + 1;
		y = rand() % ((taille_tab_col-2)) + 1;
		

		// [X][Y] ==> correspond a un mur
		 printf(" X = %5d\n",x );
		printf(" Y = %5d\n",y );
		printf("Nombre ite : %10d \n", nb_iteration);
		printf("Nombre MAX ite : %10d \n", nb_max_iteration);

		// X==> PAIR, Y==> IMPAIR | on casse HORIZONTALEMENT
		if (impair(x) == 0 && impair(y) == 1)
		{
			casser_mur(matrice,x,(y-1),x,y,x,(y+1), &nb_iteration, taille_tab_ligne,taille_tab_col);
		}
		// Y==> PAIR, X==> IMPAIR | on casse VERTIVALEMENT
		if (impair(x) == 1 && impair(y) == 0)
		{	
			casser_mur(matrice, (x-1), y, x, y, (x+1), y, &nb_iteration, taille_tab_ligne,taille_tab_col);
		}
	}

}

int casser_mur(char matrice[NMAX][NMAX], int x_top,int y_top,int x_mur,int y_mur,int x_bot,int y_bot, int * nb_iteration,
	int taille_tab_ligne, int taille_tab_col)
{
	int ligne = 0;
	int col = 0;
	int cells_top = matrice[x_top][y_top];
	int cells_mur = matrice[x_mur][y_mur];
	int cells_bot = matrice[x_bot][y_bot];
printf("OTOTOTO \n");
	if (cells_top != cells_bot)
	{
			printf("TITI \n");

		cells_mur = cells_top;
		for (ligne = 0; ligne < taille_tab_ligne; ligne++)
		{
		for(col = 0; col < taille_tab_col; col++)
			{
				if (matrice[ligne][col] ==cells_bot)
					matrice[ligne][col]=cells_top;
			}
		}

		nb_iteration++;
	}

}

void affichage(char matrice[NMAX][NMAX], int taille_tab_ligne , int taille_tab_col)
{
	int ligne,col;
	// printf("taille  affichage	 :  %d \n\n\n", taille);
	for ( ligne = 0; ligne < taille_tab_ligne; ligne++) 		
	{
	 	for (col = 0; col < taille_tab_col; col++)
	 	{

	 		printf(" %2d ", matrice[ligne][col]);
	 	}
	 	printf("\n");
	}

}

