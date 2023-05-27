### 
## Makefile skeleton
## INFO0947: Projet 2
## 
### 

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes
LD=gcc
LDFLAGS=

## Tests files
EXEC_TEST_T=test_array
MODULES_TEST_T=itineraireflamme_tableau_test.c itineraireflamme_tableau.c region.c seatest.c
OBJECTS_TEST_T=itineraireflamme_tableau_test.o itineraireflamme_tableau.o region.o seatest.o

EXEC_TEST_L=test_list
MODULES_TEST_L=itineraireflamme_liste_test.c itineraireflamme_liste.c region.c seatest.c
OBJECTS_TEST_L=itineraireflamme_liste_test.o itineraireflamme_liste.o region.o seatest.o

## Files
EXEC_T=itineraireflamme_tableau
MODULES_T=main.c region.c itineraireflamme_tableau.c 
OBJECTS_T=main.o region.o itineraireflamme_tableau.o

EXEC_L=itineraireflamme_liste
MODULES_L=main.c region.c itineraireflamme_liste.c
OBJECTS_L=main.o region.o itineraireflamme_liste.o

## Compilation main program
all: $(EXEC)

itineraireflamme_tableau: $(OBJECTS_T)
	$(LD) -o $(EXEC_T) $(OBJECTS_T) $(LDFLAGS)
	
itineraireflamme_liste: $(OBJECTS_L)
	$(LD) -o $(EXEC_L) $(OBJECTS_L) $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

itineraireflamme_tableau_test.o: itineraireflamme_tableau_test.c
	$(CC) -c itineraireflamme_tableau_test.c -o itineraireflamme_tableau_test.o $(CFLAGS)

itineraireflamme_liste_test.o: itineraireflamme_liste_test.c
	$(CC) -c itineraireflamme_liste_test.c -o itineraireflamme_liste_test.o $(CFLAGS)

region.o: region.c
	$(CC) -c region.c -o region.o $(CFLAGS)
	
itineraireflamme_tableau.o: itineraireflamme_tableau.c
	$(CC) -c itineraireflamme_tableau.c -o itineraireflamme_tableau.o $(CFLAGS)
	
itineraireflamme_liste.o: itineraireflamme_liste.c
	$(CC) -c itineraireflamme_liste.c -o itineraireflamme_liste.o $(CFLAGS)

## End of the compilation

		
## Compilation tests program
test_array : $(OBJECTS_TEST_T)
	 $(LD) -o $(EXEC_TEST_T) $(OBJECTS_TEST_T) $(LDFLAGS_TEST)
	 
test_list : $(OBJECTS_TEST_L)
	 $(LD) -o $(EXEC_TEST_L) $(OBJECTS_TEST_L) $(LDFLAGS_TEST)
	 
## End of the test compilation

clean:
	rm -f *.o $(EXEC) *~

