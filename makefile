postfix: mycomp.o complex.o
	gcc mycomp.o complex.o -o postfix

mycomp.o: mycomp.c complex.h
	gcc -c -ansi -pedantic -Wall -g mycomp.c -o mycomp.o

complex.o: complex.c complex.h
	gcc -c -ansi -pedantic -Wall -g complex.c -o complex.o -lm
