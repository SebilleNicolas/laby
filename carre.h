#define NMAX 30

/**
 * @brief Initialise la matrice en mettant toutes les cases a 0
 * et la case en dessous de la case du millieu a 1.
 * @param matrice une matrice avec NMAX en valeur.
 * @param taille Taille de la matrice.
 * @return rien
 */
void initialise( char matrice[NMAX][NMAX], int taille);



/**
 * @brief Remplit toutes les cases avec les chiffres correspondant. 
 * Si la case est déjà prise, la fonction va décaler les chiffres vers une autre case.
 * @param matrice une matrice avec NMAX en valeur.
 * @param taille Taille de la matrice.
 * @return rien
 */
void remplissage(char matrice[NMAX][NMAX],int taille);



/**
 * @brief Affiche les matrice ligne par ligne.
 * @param matrice une matrice avec NMAX en valeur.
 * @param taille Taille de la matrice.
 * @return rien
 */
void affichage(char matrice[NMAX][NMAX], int taille);



/**
 * @brief Additionne les valeurs ligne par ligne et compare les résultat
 * @param matrice une matrice avec NMAX en valeur.
 * @param taille Taille de la matrice.
 * @return OK si la somme des valeurs de la ligne correspond avec la somme des autres lignes.
 * @return erreur, valeur de la ligne : Dans le cas ou la somme des valeurs des lignes sont différentes
 */
void verif_ligne(char matrice[NMAX][NMAX], int taille);


/**
 * @brief Additionne les valeurs colonne par colonne et compare les résultat
 * @param matrice une matrice avec NMAX en valeur.
 * @param taille Taille de la matrice.
 * @return OK si la somme des valeurs de la colonne correspond avec la somme des autres colonnes.
 * @return erreur, valeur de la colonne : Dans le cas ou la somme des valeurs des colonnes sont différentes
 */
void verif_col(char matrice[NMAX][NMAX], int taille);



void verif_diagonal(char matrice[NMAX][NMAX], int taille);