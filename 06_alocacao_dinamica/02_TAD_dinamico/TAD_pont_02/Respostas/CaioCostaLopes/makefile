all: geraos geraexe

geraos: main.c eleicao.c candidato.c eleitor.c
	gcc -c main.c eleicao.c candidato.c eleitor.c

geraexe: main.o eleicao.o candidato.o eleitor.o
	gcc main.o eleicao.o candidato.o eleitor.o -o prog

clean:
	rm -rf *.o prog