all: geraos geraexe

geraos: main.c relatorio.c aluno.c vector.c
	gcc -c main.c relatorio.c aluno.c vector.c

geraexe: main.o relatorio.o aluno.o vector.o
	gcc main.o relatorio.o aluno.o vector.o -o prog

clean:
	rm -rf *.o prog