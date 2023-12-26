all: geraos geraexe

geraos: main.c string_utils.c
	gcc -c main.c string_utils.c

geraexe: main.o string_utils.o
	gcc main.o string_utils.o -o prog

clean:
	rm -rf *.o prog