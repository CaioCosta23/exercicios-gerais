all: geraos geraxe

geraos: main.o jogo.c tabuleiro.c jogador.c jogada.c
	gcc -c main.o jogo.c tabuleiro.c jogador.c jogada.c

geraexe: main.o jogo.o tabuleiro.o jogador.o jogada.o
	gcc main.o jogo.o tabuleiro.o jogador.o jogada.o -o prog

clean:
	rm -rf *.o prog