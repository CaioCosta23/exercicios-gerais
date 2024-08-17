all: geraos geraexe

geraos: main.c agencia.c conta.c operacao.c
	gcc -c main.c agencia.c conta.c operacao.c

geraexe: main.o agencia.o conta.o operacao.o
	gcc main.o agencia.o conta.o operacao.o -o prog

clean:
	rm -rf *.o prog