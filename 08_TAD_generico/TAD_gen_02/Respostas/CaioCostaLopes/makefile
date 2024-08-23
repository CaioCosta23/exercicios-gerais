all: geraos geraexe

geraos: main.c gerenciadorpacotes.c pacote.c
	gcc -c main.c gerenciadorpacotes.c pacote.c

geraexe: main.o gerenciadorpacotes.o pacote.o
	gcc main.o gerenciadorpacotes.o pacote.o -o prog

clean:
	rm -rf *.o prog