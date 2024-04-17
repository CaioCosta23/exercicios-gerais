all: geraos geraexe

geraos: main.c matrix_utils.c
	gcc -c main.c matrix_utils.c

geraexe: main.o matrix_utils.o
	gcc main.o matrix_utils.o - o prog

clean:
	rm -rf *.o prog