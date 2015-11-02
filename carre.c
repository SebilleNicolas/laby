
#include <stdio.h>
#include <stdlib.h>
#include "carre.h"

void initialise( laby_struct * laby)
{	
	int ligne=0;
	int col=0;
	// Compteur pour mettre les chiffres dans les cases
	int cpt = 1;
	// Variable qui verifie qu'on est sur une colonne/ligne impair
	for (ligne = 0; ligne < laby->size_line; ligne++)
	{
		for(col = 0; col < laby->size_col; col++)
		{
			// SI On est sur une colonne et une ligne avec chiffre
			// Impair : on met la valeur de cpt dans la case.
			if (impair(ligne) && impair(col) == 1)
			{
				laby->matrice[ligne][col] = cpt;
				cpt ++;
			}
			//Sinon on met un 0 (espace)
			else
			{
				laby->matrice[ligne][col] =0;
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

void remplissage(laby_struct * laby)
{
	int cells_top;
	int cells_right;
	int * cells_mur;
	int cells_left;
	int cells_bot;
	srand(time(NULL));
	int nb_iteration = 0;

	int nb_max_iteration = ((laby->size_line/2) * (laby->size_col/2)-1);

	int cpt_mur_casser = 0;
	int ligne = rand()%laby->size_line-1;
	int col = rand()%laby->size_col-1;

	
	while(nb_iteration < nb_max_iteration)
	{	
		// Prend des valeurs de ligne et colonne compris entre 1 et longueur_tableau -1 (uniquement dans le carré jouable)
		ligne = rand() % ((laby->size_line-2)) + 1;
		col = rand() % ((laby->size_col-2)) + 1;
		
		// ligne ==> PAIR, colonne ==> IMPAIR | on casse HORIZONTALEMENT
		if (impair(ligne) == 1 && impair(col) == 0)
		{	
			cells_right = laby->matrice[ligne][col-1];
			cells_mur = &laby->matrice[ligne][col];
			cells_left = laby->matrice[ligne][col+1];
			
			// SI la valeur avant et apres le mur sont différentes (si =, alors il existe deja un chemin)
			if (cells_right != cells_left)
			{	
				casser_mur(laby,cells_right,cells_mur,cells_left, &nb_iteration);
			}
		}

		// colonne ==> PAIR, ligne ==> IMPAIR | on casse VERTICALEMENT
		else if (impair(ligne) == 0 && impair(col) == 1)
		{	
			cells_top = laby->matrice[ligne-1][col];
			cells_mur = &laby->matrice[ligne][col];
			cells_bot = laby->matrice[ligne+1][col];

			// SI la valeur avant et apres le mur sont différentes (si =, alors il existe deja un chemin)
			if (cells_top != cells_bot)
			{
				casser_mur(laby,cells_top,cells_mur,cells_bot, &nb_iteration);
			}
		}
	}

	printf("NOMBRE MUR CASSER : %d \n\n\n\n\n", nb_iteration);
}


void affichage(laby_struct * laby)
{
	int ligne,col;
	for ( ligne = 0; ligne < laby->size_line; ligne++) 		
	{
	 	for (col = 0; col < laby->size_col; col++)
	 	{
	 		if (laby->matrice[ligne][col] == 0)
	 		{
	 			printf("#");
	 		}
	 		else if (laby->matrice[ligne][col] == -1)
	 		{
	 			printf("o");
	 		}
	 		else
	 		{
	 			printf(" ");

	 		}
	 	}
	 	printf("\n");
	}
	printf("\n");
	printf("\n");

}

// void avancer(laby_struct * laby)
// {

// }


void casser_mur(laby_struct * laby, int cells_top ,int * cells_mur ,int cells_bot, int * nb_iteration)
{
	int ligne = 0;
	int col = 0;
	int toto;
	
	//On casse le mur
	(*cells_mur) = cells_top;
	// On remplace les valeurs des anciennes cellules par la nouvelle 
	for (ligne = 0; ligne < laby->size_line; ligne++)
	{
	for(col = 0; col < laby->size_col; col++)
		{
			if (laby->matrice[ligne][col] ==cells_bot)
			{
				laby->matrice[ligne][col]=cells_top;
			}
		}
	}


	(*nb_iteration)++;
}


void fflush2()
{
	int c;
	do{
		c = getchar();
	}while (c !='\n' && c != EOF);
}

void start_end(laby_struct * laby)
{
	laby->matrice[1][0] = -1;
	laby->matrice[laby->size_line-2][laby->size_col-1] = -2;
}