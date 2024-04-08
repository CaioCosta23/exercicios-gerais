all: geraos geraexe

geraos: main.c filme.c locadora.c
	gcc -c main.c filme.c locadora.c

geraexe: main.o filme.o locadora.o
	gcc main.o filme.o locadora.o -o prog

clean:
	rm -rf *.o prog