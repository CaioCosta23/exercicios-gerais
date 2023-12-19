all: geraos geraexe

geraos: main.c calculadora.c
	gcc -c main.c calculadora.c

geraexe: main.o calculadora.o
	gcc main.o calculadora.o -o prog

clean:
	rm -rf *.o prog