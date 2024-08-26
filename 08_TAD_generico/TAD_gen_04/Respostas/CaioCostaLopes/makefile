all: geraos geraexe

geraos: main.c banco.c agencia.c conta.c vector.c
	gcc -c main.c banco.c agencia.c conta.c vector.c

geraexe: main.o banco.o agencia.o conta.o vector.o
	gcc main.o banco.o agencia.o conta.o vector.o -o prog

clean:
	rm -rf *.o prog