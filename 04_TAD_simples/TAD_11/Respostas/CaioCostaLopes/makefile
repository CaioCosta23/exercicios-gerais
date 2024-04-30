all: geraos geraexe

geraos: main.c vendedor.c loja.c
	gcc -c main.c vendedor.c loja.c

geraexe: main.o vendedor.o loja.o
	gcc main.o vendedor.o loja.o -o prog

clean:
	rm -rf *.o prog