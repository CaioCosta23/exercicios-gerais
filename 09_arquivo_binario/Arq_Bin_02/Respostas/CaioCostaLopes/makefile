all: geraos geraexe

geraos: main.c base_alunos.c aluno.c
	gcc -c main.c base_alunos.c aluno.c

geraexe: main.o base_alunos.o aluno.o
	gcc main.o base_alunos.o aluno.o -o prog

clean:
	rm -rf *.o prog