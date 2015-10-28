#define NMAX 30

/**
 * @brief Initialise la matrice en mettant toutes les cases a 0
 * et la case en dessous de la case du millieu a 1.
 * @param matrice une matrice avec NMAX en valeur.
 * @param taille Taille de la matrice.
 * @return rien
 */
void initialise( char matrice[NMAX][NMAX], int taille_tab_x , int taille_tab_y);



/**
 * @brief Remplit toutes les cases avec les chiffres correspondant. 
 * Si la case est déjà prise, la fonction va décaler les chiffres vers une autre case.
 * @param matrice une matrice avec NMAX en valeur.
 * @param taille Taille de la matrice.
 * @return rien
 */
void remplissage(char matrice[NMAX][NMAX],int taille_tab_x , int taille_tab_y);



/**
 * @brief Affiche les matrice ligne par ligne.
 * @param matrice une matrice avec NMAX en valeur.
 * @param taille Taille de la matrice.
 * @return rien
 */
void affichage(char matrice[NMAX][NMAX], int taille_tab_x , int taille_tab_y);




/**
 * @brief Verifie si un nombre est pair/Impair
 * @param entier
 * @return 0 ==> pair | 1 ==> impair
 */
int impair(int entier);