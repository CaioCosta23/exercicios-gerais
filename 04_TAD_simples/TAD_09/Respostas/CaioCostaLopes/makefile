all: geraos geraexe

geraos: main.c empresa.c funcionario.c
	gcc -c main.c funcionario.c empresa.c

geraexe: main.o empresa.o funcionario.o
	gcc main.o empresa.o funcionario.o -o prog

clean:
	rm -rf *.o prog