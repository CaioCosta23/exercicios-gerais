all: geraos geraexe

geraos: main.c pad.c pacinete.c lesao.c data.c
	gcc -c main.c pad.c paciente.c lesao.c data.c

geraexe: main.o pad.o paciente.o lesao.o data.o
	gcc main.o pad.o paciente.o lesao.o data.o -o prog

clean:
	rm -rf *.o prog