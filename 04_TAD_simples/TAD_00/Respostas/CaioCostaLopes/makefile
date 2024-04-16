all: geraos geraexe

geraos: main.c ponto.c
	gcc -c main.c ponto.c

geraexe: main.o ponto.o
	gcc main.o ponto.o -o prog -lm

clean:
	rm -rf *.o prog