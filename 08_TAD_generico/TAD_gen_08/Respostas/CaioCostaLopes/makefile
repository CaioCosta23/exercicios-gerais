all: geraos geraexe

geraos: main.c movel.c fila.c vector.c
	gcc -c main.c movel.c fila.c vector.c

geraexe: main.o movel.o fila.o vector.o
	gcc main.o movel.o fila.o vector.o -o prog

clean:
	rm -rf *.o prog