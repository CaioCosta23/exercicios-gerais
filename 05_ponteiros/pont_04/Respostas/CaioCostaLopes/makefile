all: geraos geraexe

geraos: main.c utils.c
	gcc -c main.c utils.c

geraexe: main.o utils.o
	gcc main.o utils.o -o prog

clean:
	rm -rf *.o prog