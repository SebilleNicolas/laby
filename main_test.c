#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <CUnit/CUnit.h>      
#include <CUnit/Automated.h>  		
#include <CUnit/Basic.h>      
#include <CUnit/Console.h>    
#include "test_unitaire_etape_1.h"



int main(int argc, char const *argv[])
{
	// un tableau pour les suites de tests 
	CU_pSuite pSuite[4];

	// initialise le registre
	CU_initialize_registry();

	// ajoute la suite au registre
	pSuite[0] = CU_add_suite("Verification taille de chaine " , NULL,NULL);

	// ajoute les tests a la suite
	CU_ADD_TEST(pSuite[0], test_casser_mur);
	//Verifier vrai ET faux

	// execute les tests
	CU_basic_run_tests();

	CU_cleanup_registry();
	return CU_get_error();
}