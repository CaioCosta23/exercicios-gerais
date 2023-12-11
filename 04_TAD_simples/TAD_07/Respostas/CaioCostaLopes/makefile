all: geraos geraexe

geraos: main.c data.c
	gcc -c main.c data.c

geraexe: main.o data.o
	gcc main.o data.o -o prog

clean:
	rm -rf *.o prog