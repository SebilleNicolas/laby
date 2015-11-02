all: main.o carre.o test_unitaire_etape_1.o
	gcc main.o carre.o test_unitaire_etape_1.o -o laby
 

main.o: main.c carre.c test_unitaire_etape_1.h
	gcc -c main.c -o main.o

 

carre.o: carre.c
	gcc -c carre.c -o carre.o



test_unitaire_etape_1.o: test_unitaire_etape_1.c
	gcc -c test_unitaire_etape_1.c -o test_unitaire_etape_1.o


# suppression des fichiers temporaires
clean:
	rm -rf *.o

