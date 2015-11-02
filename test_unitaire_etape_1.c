
#include <stdio.h>
#include <stdlib.h>
#include "carre.h"
int ** matrice;
//
void test_function_casser_mur_impair()
{
	laby_struct * labytest = NULL;

	labytest = malloc(sizeof(laby_struct));
	creer_tab();
	labytest->matrice = matrice;


	// int tab_test[5][5] = {	{0,	0,	0,	0,	0},
							// {0,	1,	0,	2,	0},
							// {0,	0,	0,	0,	0},	
							// {0,	3,	0,	4,	0},
							// {0,	0,	0,	0,	0}	};

	// labytest->matrice = tab_test;

int cells_top = labytest->matrice[1][1];
int * cells_mur = &labytest->matrice[1][2];
int cells_bot = labytest->matrice[1][3];
int nb_ite = 5;

casser_mur(labytest, cells_top ,cells_mur ,cells_bot, &nb_ite);

}

void creer_tab()
{	
	int ligne,col;
	matrice = calloc(5 , sizeof(int*));
	if (matrice == NULL)
	{
		perror("Probleme allocation dynamique");
		exit(-1);
	}
	int i;
	for (i = 0; i< 5;i++)
	{
		matrice[i] = calloc(5 , sizeof(int));
	}
	matrice[1][1] = 1;
	matrice[1][2] = 0;
	matrice[1][3] = 2;

}

// 0	0	0	0	0
// 0	1	0	2	0
// 0	0	0	0	0	
// 0	3	0	4	0
// 0	0	0	0	0	
// void casser_mur(laby_struct * laby, int cells_top ,int * cells_mur ,int cells_bot, int * nb_iteration)


// cordonnée mur : [1][2]
// avant = 1 1
// apres 1 3

