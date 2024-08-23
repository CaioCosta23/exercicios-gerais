all: geraos geraexe

geraos: main.c tadgen.c
	gcc -c main.c tadgen.c

geraexe: main.o tadgen.o
	gcc main.o tadgen.o -o prog

clean:
	rm -rf *.o prog