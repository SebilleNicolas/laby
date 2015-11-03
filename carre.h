#include <stdio.h>
#include <stdlib.h>
#define NMAX 300


typedef struct 
{
	int size_line;
	int size_col;
	int ** matrice;
	char nom[];
}laby_struct;

/**
 * @brief Initialise le tableau en mettant la valeur de toutes les cases du  labyrinthe ayant 
 * une ligne et une colonne impair a la valeur d'un compteur allant de 1 a +++
 * Les autres cases auront la valeur 0 (espace)
 * @param Pointeur Structure du labyrinthe
 * @return rien
 */
void initialise( laby_struct * laby);



/**
 * @brief se place sur une case du labyrinthe aleatoirement. 
 * si la case est un mur :
 *		si la ligne est PAIR && la colonne est IMPAIR : (CASSER VERTICALEMENT)
 * 			On compare si la valeur de la case au dessus du mur et en dessous sont différente :
 *				On casse le mur ==> val_mur = val case_au_dessus
 *				On remplace toute les cases qui ont la valeur de la case de dessous par la valeur du mur
 * 		si la colonne est PAIR && la ligne est IMPAIR : (CASSER HORIZONTALEMENT)
 * 			On compare si la valeur de la case a gauche du mur et a droite sont différente :
 *				On casse le mur ==> val_mur = val case_a_gauche
 *				On remplace toute les cases qui ont la valeur de la case de droite par la valeur du mur
 * @param Pointeur Structure du labyrinthe
 * @return rien
 */
void remplissage(laby_struct * laby);



/**
 * @brief on regarde toutes les cases du labyrinthe 
 * si la case = 0 ==> on affiche un # (car c'est un mur)
 * si la case = un nombre ==> on affiche un espace
 * @param Pointeur Structure du labyrinthe
 * @return rien
 */
void affichage(laby_struct * laby);

/**
 * @brief Vide le buffer
 * @return rien
 */
void fflush2();

/**
 * @brief Casse l'entrée et la sortie du labyrinthe
 * @param Pointeur Structure du labyrinthe
 * @return rien
 */
void start_end(laby_struct * laby);
void casser_mur(laby_struct * laby, int  cells_top ,int * cells_mur ,int  cells_bot, int * nb_iteration);

/**
 * @brief Verifie si un nombre est pair/Impair
 * @param entier
 * @return 0 ==> pair | 1 ==> impair
 */
int impair(int entier);


/**
 * @brief Libere les tableaux dynamique de la mémoire
 * @param Pointeur Structure du labyrinthe
 */
void free_laby(laby_struct * laby);