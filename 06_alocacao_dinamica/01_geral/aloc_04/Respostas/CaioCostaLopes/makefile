all: geraos geraexe

geraos: main.c utils_char2.c
	gcc -c main.c utils_char2.c

geraexe: main.o utils_char2.o
	gcc main.o utils_char2.o -o prog

clean:
	rm -rf *.o prog