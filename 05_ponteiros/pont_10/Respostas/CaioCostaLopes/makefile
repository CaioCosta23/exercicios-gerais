all: geraos geraexe

geraos: main.c pessoa.c
	gcc -c main.c pessoa.c

geraexe: main.o pessoa.o
	gcc main.o pessoa.o -o prog

clean:
	rm -rf *.o prog