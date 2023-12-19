all: geraos geraexe

geraos: main.c rolagem.c
	gcc -c main.c rolagem.c

geraexe: main.o rolagem.o
	gcc main.o rolagem.o -o prog

clean:
	rm -rf *.o prog