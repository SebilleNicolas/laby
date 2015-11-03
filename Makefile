all: main.o carre.o 
	gcc main.o carre.o -o laby

all_test: main_test.o carre.o test_unitaire_etape_1.o
	gcc main_test.o carre.o test_unitaire_etape_1.o -o laby_test -lcunit


main.o: main.c carre.c 
	gcc -c main.c -o main.o

carre.o: carre.c
	gcc -c carre.c -o carre.o


test_unitaire_etape_1.o: test_unitaire_etape_1.c
	gcc -c test_unitaire_etape_1.c -o test_unitaire_etape_1.o -lcunit

# suppression des fichiers temporaires
clean:
	rm -rf *.o
