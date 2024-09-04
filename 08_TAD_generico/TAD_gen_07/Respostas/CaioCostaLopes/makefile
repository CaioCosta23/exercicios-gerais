all: geraos geraexe

geraos: main.c histograma.c imagem.c
	gcc -c main.c histograma.c imagem.c

geraexe: main.o histrograma.o imagem.o
	gcc main.o histograma.o imagem.o -o prog

clean:
	rm -rf *.o prog