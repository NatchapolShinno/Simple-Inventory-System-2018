#################################################################
# | This makefile is intended to build cpeInventory program     |
# | Create By Mr.Supakij Buasod 61070503438 (FIRST)             |
# | Create date 9 December 2018 (Update 12 December 2018)       |
#################################################################

EXECUTABLES=checkFunction searchFunction displayFunction main cpeInventory

all : $(EXECUTABLES)

checkFunction : checkFunction.c checkFunction.h
	gcc -c checkFunction.c

searchFunction : searchFunction.c searchFunction.h
	gcc -c searchFunction.c

displayFunction : displayFunction.c displayFunction.h
	gcc -c displayFunction.c 

main : main.c checkFunction.h searchFunction.h displayFunction.h
	gcc -c main.c

cpeInventory : main.o checkFunction.o searchFunction.o displayFunction.o
	gcc -o cpeInventory main.o checkFunction.o searchFunction.o displayFunction.o

clean : 
	-rm *.o
	-rm cpeInventory