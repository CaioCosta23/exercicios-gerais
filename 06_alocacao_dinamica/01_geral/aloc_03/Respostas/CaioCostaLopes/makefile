all: geraos geraexe

geraos: main.c utils_char.c
	gcc -c main.c utils_char.c

geraexe: main.o utils_char.o
	gcc main.o utils_char.o -o prog

clean:
	rm -rf *.o prog