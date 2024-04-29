all: geraos geraexe

geraos: main.c loja.c vendedor.c
	gcc -c main.c loja.c vendedor.c

geraexe: main.o loja.o vendedor.o
	gcc main.o loja.o vendedor.o -o prog

clean:
	rm -rf *.o prog