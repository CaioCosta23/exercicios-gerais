all: geraos geraexe

geraos: main.c nba.c franquia.c partida.c
	gcc -c main.c nba.c franquia.c partida.c

geraexe: main.o nba.o franquia.o partida.o
	gcc main.o nba.o franquia.o partida.o

clean:
	rm -rf *.o