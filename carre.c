
#include <stdio.h>
#include <stdlib.h>
#include "carre.h"

void initialise( char matrice[NMAX][NMAX], int taille)
{	
	// printf("taille initialisation : %d \n", taille);
	int ligne=0;
	int col=0;
	// On initialise toutes les cases a 0
	for (ligne = 0; ligne < taille; ligne++)
	{
		for(col = 0; col < taille; col++)
		{
			matrice[ligne][col] = '#';
		}
	}
}



void remplissage(char matrice[NMAX][NMAX],int taille){
	
	for (ligne = 0; ligne < taille; ligne++)
	{
		for(col = 0; col < taille; col++)
		{
			if()
			{
				
			}
		}
	}
}



void affichage(char matrice[NMAX][NMAX], int taille){
	int ligne,col;
	printf("taille  affichage	 :  %d \n\n\n", taille);
	for ( ligne = 0; ligne < taille; ligne++) 		
	{
	 	for (col = 0; col < taille; col++)
	 	{
	 		printf(" %c ", matrice[ligne][col]);
	 	}
	 	printf("\n");
	}

}


void verif_ligne(char matrice[NMAX][NMAX], int taille)
{	
	printf(" \n\n >>>>>>>>>> VERIFICATION LIGNE <<<<<<<<<<\n");
	int ligne,col=0;
	int nb_total=0;
	int nb_comparaison=0;
	// Recupere l'addition des valeurs sur la 1ere colonne
	for ( ligne = 0; ligne < taille; ligne++)
	{
		nb_total = nb_total + matrice[ligne][col];
	}
	// Somme des valeurs de la colonne 0 avec les ligne 1,2,3
	printf("Nb_total  pour ligne  >>>>>>>>>> %d <<<<<<<<<< \n", nb_total);
	for (ligne = 0; ligne < taille; ligne++)
	{
		for(col = 0; col < taille; col++)
		{
			nb_comparaison = nb_comparaison + matrice[ligne][col];
		}
		// On verifie si la comparaison est égale a la somme calculer précédemment
		if( nb_comparaison == nb_total)
		{
			printf("La ligne %d ==> OK \n",ligne);
			nb_comparaison = 0;
		}
		else
		{
			printf("Probleme sur la ligne >>>>>>>>>> ERREUR <<<<<<<<<< \n");
			printf("nb_comparaison >>>>>>>>>> %d <<<<<<<<<< \n\n\n", nb_comparaison);
			exit;
		}
	}
	printf("\n\n\n");
}




void verif_col(char matrice[NMAX][NMAX], int taille)
{
	printf(" >>>>>>>>>> VERIFICATION COLONNES <<<<<<<<<<\n");
	int ligne = 0,col=0;
	int nb_total_col=0;
	int nb_comparaison_col=0;
	// Recupere l'addition des valeurs sur la 1ere ligne
	for ( col = 0; col < taille; col++)
	{
		// nb_total_col = nb_total_col + matrice[ligne][col];
		nb_total_col += matrice[ligne][col];
	}
	// Somme des valeurs de la ligne 0 avec les colonnes 1,2,3
	printf("Nb_total pour colonne >>>>>>>>>> %d <<<<<<<<<< \n", nb_total_col);

	for (col = 0; col < taille; col++)
	{
		for(ligne = 0; ligne < taille; ligne++)
		{
			nb_comparaison_col = nb_comparaison_col + matrice[ligne][col];
		}
		// On verifie si la comparaison est égale a la somme calculer précédemment
		if( nb_comparaison_col == nb_total_col)
		{
			printf("La colonne %d ==> OK \n",col);
			nb_comparaison_col = 0;
		}
		else
		{
			printf("Probleme sur la colonne >>>>>>>>>> ERREUR <<<<<<<<<< \n");
			printf("nb_comparaison >>>>>>>>>> %d <<<<<<<<<< \n\n\n", nb_comparaison_col);
			exit;
		}
	}
	printf("\n\n\n");
}

void verif_diagonal(char matrice[NMAX][NMAX], int taille)
{
	printf(" >>>>>>>>>> VERIFICATION DIANGONALE <<<<<<<<<<\n");
	int ligne_col=0;
	int nb_total=0;
	int nb_comparaison=0;
	// Recupere l'addition des valeurs sur la 1ere ligne
	for ( ligne_col = 0; ligne_col < taille; ligne_col++)
	{
		nb_total += matrice[ligne_col][ligne_col];
	}

	for (ligne_col = 0; ligne_col < taille; ligne_col++)
	{
		nb_comparaison += matrice[ligne_col][ligne_col];
		
	}
	if( nb_comparaison == nb_total)
		{
			printf("La diagonal ==> OK \n");
			nb_comparaison = 0;
		}
		else
		{
			printf(" Probleme sur la colonne/ligne >>>>>>>>>> ERREUR <<<<<<<<<< \n");
			printf(" nb_comparaison >>>>>>>>>> %d <<<<<<<<<< \n\n\n", nb_comparaison);
			exit;
		}
	printf("\n\n\n");
}