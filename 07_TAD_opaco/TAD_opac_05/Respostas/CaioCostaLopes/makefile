all: geraos geraexe

geraos: main.c banco.c conta.c usuario.c
	gcc -c main.c banco.c conta.c usuario.c

geraexe: main.o banco.o conta.o usuario.o
	gcc main.o conta.o usuario.o

clean:
	rm -rf *.o prog