#include "test_unitaire_etape_1.h"
#include "CUnit/Basic.h"


int ** matrice;



laby_struct * creer_tab()
{
	laby_struct * labytest = NULL;
	labytest = malloc(sizeof(laby_struct));

	labytest->matrice = matrice;
	int i;
	matrice = calloc(7 , sizeof(int*));
	if (matrice == NULL)
	{
		perror("Probleme allocation dynamique");
		exit(-1);
	}
	for (i = 0; i< 7;i++)
	{
		matrice[i] = calloc(7 , sizeof(int));
	}
	
	affichage(labytest);

	return labytest;

}

void test_casser_mur()
{
	laby_struct * labytest = creer_tab();
	

	// Laby Vrai
	creer_tab_casser_mur();
	CU_ASSERT(test_function_casser_mur_horizontal(labytest) == 1);
	CU_ASSERT(test_function_casser_mur_vertical(labytest) == 1);

	// Laby Faux
	creer_tab_casser_mur_faux();
	CU_ASSERT(test_function_casser_mur_horizontal(labytest) == 0);
	CU_ASSERT(test_function_casser_mur_vertical(labytest) == 0);

	// Libere les tableaux dynamique
	free_laby(labytest);
}

int test_function_casser_mur_horizontal(laby_struct * labytest)
{
	int reussi = 1;
	
	affichage(labytest);

	// labytest = malloc(sizeof(laby_struct));
	// labytest->matrice = matrice;

	int cells_top = labytest->matrice[1][1];
	int * cells_mur = &labytest->matrice[1][2];
	int cells_bot = labytest->matrice[1][3];
	int nb_ite = 7;

	casser_mur(labytest, cells_top ,cells_mur ,cells_bot, &nb_ite);

	if(labytest->matrice[1][2] != 0)
	{
		printf("mur casser horizontalement -----> REUSSI \n");
	}
	else
	{
		printf("mur casser horizontalement -----> ECHEC \n");
		reussi = 0;
	}
	
	return reussi;


}


int test_function_casser_mur_vertical(laby_struct * labytest)
{
	int reussi = 1;


	int cells_top = labytest->matrice[1][1];
	int * cells_mur = &labytest->matrice[2][1];
	int cells_bot = labytest->matrice[3][1];
	int nb_ite = 7;

	casser_mur(labytest, cells_top ,cells_mur ,cells_bot, &nb_ite);

	if(labytest->matrice[2][1] != 0)
	{
		printf("mur casser vertialement -----> REUSSI \n");
	}
	else
	{
		printf("mur casser vertialement -----> ECHEC \n");
		reussi = 0;
	}
	return reussi ;
}

void creer_tab_casser_mur(laby_struct * labytest)
{	
	
	// Pour casser le mur horizontal
	matrice[1][1] = 1;
	matrice[1][2] = 0;
	matrice[1][3] = 2;


	// Pour casser le mur vertical
	matrice[2][1] = 0;
	matrice[3][1] = 3;
}


void creer_tab_casser_mur_faux(laby_struct * labytest)
{	
	// Pour casser le mur horizontal
	matrice[1][1] = 1;
	matrice[1][2] = 2;
	matrice[1][3] = 3;


	// Pour casser le mur vertical
	matrice[2][1] = 4;
	matrice[3][1] = 5;
}

// on veux verifier que apres cassage des murs, tout les champs ont la meme valeur partout
void laby_parfait(laby_struct * labytest)
{
	int ligne,col;
	
	int val = labytest->matrice[1][1];
	int reussi = 1;
	for (ligne = 0; ligne < labytest->size_line; ligne ++)
	{
		for (col = 0; col < labytest->size_col; col++)
		{	
			// Si le case n'est pas un mur
			if (labytest->matrice[ligne][col] != 0)
			{
				if(labytest->matrice[ligne][col] != val)
					reussi = 0;
			}
		}
	}
	if (reussi == 1)
		printf("Labyrinthe parfait -----> REUSSI \n");
	else
		printf("Labyrinthe parfait ----->  ECHEC \n");
}

