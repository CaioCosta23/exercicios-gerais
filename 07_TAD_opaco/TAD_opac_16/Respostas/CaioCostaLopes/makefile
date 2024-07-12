all: geraos gerexe

geraos: main.c sistema.c data.c
	gcc -c main.c sistema.c data.c

geraexe: main.o sistema.o data.o
	gcc main.o sistema.o data.o -o prog

clean:
	rm -rf *.o prog