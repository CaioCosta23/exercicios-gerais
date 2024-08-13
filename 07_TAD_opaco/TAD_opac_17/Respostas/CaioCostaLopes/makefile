all: geraos geraexe

geraos: main.c computador.c jogo.c
	gcc -c main.c computador.c jogo.c

geraexe: main.o computador.o jogo.o
	gcc main.o computador.o jogo.o -o prog -lm

clean:
	rm -rf *.o prog