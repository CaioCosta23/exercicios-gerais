all: geraos geraexe


geraos: main.c tabuleiro.c jogador.c jogada.c jogo.c
	gcc -c main.c tabuleiro.c jogador.c jogada.c jogo.c

geraexe: main.o tabuleiro.o jogador.o jogada.o jogo.c
	gcc main.o tabuleiro.o jogador.o jogada.o jogo.o -o prog

clean: 
	rm -rf *.o prog