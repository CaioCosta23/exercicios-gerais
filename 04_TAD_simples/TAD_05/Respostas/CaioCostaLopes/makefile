all: geraos geraexe

geraos: main.c usuario.c conta.c
	gcc -c main.c usuario.c conta.c

geraexe: main.o usuario.o conta.o
	gcc main.o usuario.o conta.o -o prog

clean:
	rm -rf *.o prog