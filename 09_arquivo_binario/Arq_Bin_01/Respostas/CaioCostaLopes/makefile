all: geraos geraexe

geraos: main.c aluno.c
	gcc -c main.c aluno.c

geraexe: main.o aluno.o
	gcc main.o aluno.o -o prog

clean:
	rm -rf *.o alunos.bin prog