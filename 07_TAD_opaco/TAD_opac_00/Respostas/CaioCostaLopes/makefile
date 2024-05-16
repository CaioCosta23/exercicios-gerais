all: geraos geraexe

geraos: main.c circulo.c ponto.c
	gcc -c main.c circulo.c ponto.c

geraexe: main.o circulo.o ponto.o
	gcc main.o circulo.o ponto.o -o prog -lm

clean:
	rm -rf *.o prog