all: geraos geraexe

geraos: main.c evento.c
	gcc -c main.c evento.c

geraexe: main.o evento.o
	gcc main.o evento.o -o prog

clean:
	rm -rf *.o prog