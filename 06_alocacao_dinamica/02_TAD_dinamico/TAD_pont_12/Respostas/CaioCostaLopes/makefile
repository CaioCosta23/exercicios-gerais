all: geraos geraexe

geraos: main.c array.c
	gcc -c main.c array.c

geraexe: main.o array.o
	gcc main.o array.o -o prog

clean:
	rm -rf *.o prog