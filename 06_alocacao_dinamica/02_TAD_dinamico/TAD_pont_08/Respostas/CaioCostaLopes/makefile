all: geraos geraexe

geraos: main.c departamento.c
	gcc -c main.c departamento.c

geraexe: main.o departamento.o
	gcc main.o departamento.o -o prog -lm

clean:
	rm -rf *.o prog