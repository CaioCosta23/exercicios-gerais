all: geraos geraexe

geraos: main.c locadora.c filme.c
	gcc -c main.c locadora.c filme.c

geraexe: main.o locadora.o filme.o
	gcc main.o locadora.o filme.o -o prog

clean:
	rm -rf *.o prog