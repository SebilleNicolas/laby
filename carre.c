
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
	int calc_l,calc_c;
	// On initialise toutes les cases a 0
	for (ligne = 0; ligne < laby->size_line; ligne++)
	{
		for(col = 0; col < laby->size_col; col++)
		{
			calc_l =ligne%2;
			calc_c = col%2;
			// On est sur une colonne et une ligne avec chiffre
			// Impair.
			if (calc_l && calc_c == 1)
			{
				laby->matrice[ligne][col] = cpt;
				cpt ++;
			}
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
	int cells_mur;
	int cells_left;
	int cells_bot;
	srand(time(NULL));
	int nb_iteration = 0;

	int nb_max_iteration = ((laby->size_line/2) * (laby->size_col/2)-1);

	int cpt_mur_casser = 0;
	int ligne = rand()%laby->size_line-1;
	int col = rand()%laby->size_col-1;

		//VERIFIER VAL NB ITERATION
	
	while(nb_iteration < nb_max_iteration)
	{

		ligne = rand() % ((laby->size_line-2)) + 1;
		col = rand() % ((laby->size_col-2)) + 1;
		

		// [X][Y] ==> correspond a un mur
		
		// printf("Nombre ite : %10d \n", nb_iteration);
		// printf("Nombre MAX ite : %10d \n", nb_max_iteration);

		// X==> PAIR, Y==> IMPAIR | on casse HORIZONTALEMENT
		if (impair(ligne) == 0 && impair(col) == 1)
		{	
			// printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			// printf("VERTIVALEMENT !!!! \n");
			// casser_mur(matrice, (ligne-1), col, ligne, col, (ligne+1), col, &nb_iteration, taille_tab_ligne,taille_tab_col);
			cells_right = laby->matrice[ligne-1][col];
			cells_mur = laby->matrice[ligne][col];
			cells_left = laby->matrice[ligne+1][col];
			// printf("CELL right : %15d \n",cells_right );
			// printf("CELL MUR : %15d \n",cells_mur );
			// printf("CELL left : %15d \n\n\n",cells_left );

			if (cells_left != cells_right)
			{
				// Casse mur
				laby->matrice[ligne][col] = cells_left;

				// Fusionne les cellules
				for (ligne = 0; ligne < laby->size_line; ligne++)
				{
				for(col = 0; col < laby->size_col; col++)
					{
						if (laby->matrice[ligne][col] ==cells_right)
						{
							laby->matrice[ligne][col]=cells_left;
						}
							
					}
				}
				nb_iteration++;
			}

		}
		// Y==> PAIR, X==> IMPAIR | on casse VERTIVALEMENT
		if (impair(ligne) == 1 && impair(col) == 0)
		{	
			// // printf("\n\n\n\n");
			// // printf(" ligne = %5d\n",ligne );
			// // printf(" col = %5d\n",col );
			// // printf("HORIZONTALEMENT !!!! \n");
			// cells_top = laby->matrice[ligne][col-1];
			// cells_mur = laby->matrice[ligne][col];
			// cells_bot = laby->matrice[ligne][col+1];
			// // printf("CELL TOP : %15d \n",cells_top );
			// // printf("CELL MUR : %15d \n",cells_mur );
			// // printf("CELL BOT : %15d \n\n",cells_bot );

			// if (cells_top != cells_bot)
			// {
			// 	// Casse le mur
			// 	laby->matrice[ligne][col] = cells_top;
			// 	// Fusionne les cellules 
			// 	for (ligne = 0; ligne < laby->size_line; ligne++)
			// 	{
			// 	for(col = 0; col < laby->size_col; col++)
			// 		{
			// 			if (laby->matrice[ligne][col] ==cells_bot)
			// 			{
			// 				laby->matrice[ligne][col]=cells_top;
			// 			}
							
			// 		}
			// 	}

			// 	nb_iteration++;
			// }

			casser_mur(laby,ligne,(col-1),ligne,col,ligne,(col+1), &nb_iteration);
		}
	}

	// for (ligne = 0; ligne < laby->size_line; ligne++)
	// 			{
	// 			for(col = 0; col < laby->size_col; col++)
	// 				{
	// 					if (laby->matrice[ligne][col] != 35)
	// 						laby->matrice[ligne][col]= ' ';
	// 				}
	// 			}
printf("NOMBRE MUR CASSER : %d \n\n\n\n\n", nb_iteration);
// 	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
// 			printf(" cells_mur = %d \n",cells_mur );
// 			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


void affichage(laby_struct * laby)
{
	int ligne,col;
	// printf("taille  affichage	 :  %d \n\n\n", taille);
	for ( ligne = 0; ligne < laby->size_line; ligne++) 		
	{
	 	for (col = 0; col < laby->size_col; col++)
	 	{
	 		if (laby->matrice[ligne][col] == 0)
	 		{
	 			printf(" # ");
	 		}
	 		else
	 		{
	 			printf("   ");

	 		}
	 	}
	 	printf("\n");
	}

}

// int put_start_end(char * matrice)
// {
	
// }





















int casser_mur(laby_struct * laby, int ligne_top,int col_top,int ligne_mur,int col_mur,int ligne_bot,int col_bot, int * nb_iteration)
{
	int ligne = 0;
	int col = 0;

	
	int cells_top = laby->matrice[ligne_top][col_top];
	int cells_mur = laby->matrice[ligne_mur][col_mur];
	int cells_bot = laby->matrice[ligne_bot][col_bot];

	if (cells_top != cells_bot)
	{

		cells_mur = cells_top;
		for (ligne = 0; ligne < laby->size_line; ligne++)
		{
		for(col = 0; col < laby->size_col; col++)
			{
				if (laby->matrice[ligne][col] ==cells_bot)
					laby->matrice[ligne][col]=cells_top;
			}
		}

		*nb_iteration++;

	}

}
