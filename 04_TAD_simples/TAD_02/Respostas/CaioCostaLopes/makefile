all: geraos geraexe

geraos: main.c eleicao.c eleitor.c candidato.c
	gcc -c main.c eleicao.c eleitor.c candidato.c

geraexe: main.o eleicao.o eleitor.o candidato.o
	gcc main.o eleicao.o eleitor.o candidato.o -o prog

clean:
	rm -rf *.o prog