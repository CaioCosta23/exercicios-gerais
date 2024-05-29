all: geraos geraexe

geraos: main.c biblioteca.c livro.
	gcc -c main.c biblioteca.c livro.c

geraexe: main.o biblioteca.o livro.o
	gcc main.o biblioteca.o livro.o

clean:
	rm -rf *.o prog