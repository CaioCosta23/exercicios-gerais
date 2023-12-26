all: geraos geraexe

geraos: main.c esfera_utils.c
	gcc -c main.c esfera_utils.c

geraexe: main.o esfera_utils.o
	gcc main.o esfera_utils.o -o prog -lm

clean:
	rm -rf *.o prog