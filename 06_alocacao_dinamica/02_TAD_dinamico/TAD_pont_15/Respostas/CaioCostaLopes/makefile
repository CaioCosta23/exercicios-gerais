all: geraos geraexe

geraos: main.c dracomania.c carta.c duelo.c
	gcc -c main.c dracomania.c carta.c duleo.c

geraexe: main.o dracomania.o carta.o duelo.o
	gcc main.o dracomania.o carta.o duelo.o -o prog

clean:
	rm -rf *.o prog