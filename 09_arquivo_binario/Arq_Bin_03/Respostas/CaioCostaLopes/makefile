all: geraos geraexe

geraos: main.c imagem.c
	gcc -c main.c imagem.c

geraexe: main.o imagem.o
	gcc main.o imagem.o -o prog

clean:
	rm -rf *.o prog