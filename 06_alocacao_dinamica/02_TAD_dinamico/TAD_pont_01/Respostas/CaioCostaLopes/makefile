all: geraos geraexe

geraos: main.c jogo.c tabuleiro.c jogador.c jogada.c
	gcc -c main.c jogo.c tabuleiro.c jogador.c jogada.c

geraexe: main.o jogo.o tabuleiro.o jogador.o jogada.o
	gcc main.o jogo.o tabuleiro.o jogador.o jogada.o

clean:
	rm -rf *.o prog