#define NMAX 300


typedef struct 
{
	int size_line;
	int size_col;
	int ** matrice;
	char nom[];
}laby_struct;

/**
 * @brief Initialise la matrice en mettant toutes les cases a 0
 * et la case en dessous de la case du millieu a 1.
 * @param matrice une matrice avec NMAX en valeur.
 * @param taille Taille de la matrice.
 * @return rien
 */
void initialise( laby_struct * laby);



/**
 * @brief Remplit toutes les cases avec les chiffres correspondant. 
 * Si la case est déjà prise, la fonction va décaler les chiffres vers une autre case.
 * @param matrice une matrice avec NMAX en valeur.
 * @param taille Taille de la matrice.
 * @return rien
 */
void remplissage(laby_struct * laby);



/**
 * @brief Affiche les matrice ligne par ligne.
 * @param matrice une matrice avec NMAX en valeur.
 * @param taille Taille de la matrice.
 * @return rien
 */
void affichage(laby_struct * laby);




/**
 * @brief Verifie si un nombre est pair/Impair
 * @param entier
 * @return 0 ==> pair | 1 ==> impair
 */
int impair(int entier);