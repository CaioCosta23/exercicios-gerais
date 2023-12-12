all: geraos geraexe

geraos: main.c livro.c biblioteca.c
	gcc -c main.c livro.c biblioteca.c

geraexe: main.o livro.o biblioteca.o
	gcc  main.o livro.o biblioteca.o -o prog

clean:
	rm -rf *.o prog