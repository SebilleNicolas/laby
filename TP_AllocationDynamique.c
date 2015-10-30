#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>



int main(int argc, char const *argv[])
{
	void affiche_vecteur(int * vecteur, int dimension)
	{

		int cpt;
		for (cpt=0 ; cpt < vecteur; cpt++)
		{
			printf("%d \n", vecteur[cpt]);
		}
	}

	void affiche_matrice(int ** matrice ,int ligne, int colonnes)
	{
		int cpt_l,cpt_c;
		int dim = ligne*colonnes;
		for(cpt_l=0;cpt_l<ligne;cpt_l++)
		{
			affiche_vecteur(matrice[cpt],dim);

		}
		
	}
	return 0;
}