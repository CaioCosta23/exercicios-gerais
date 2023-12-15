all: geraos geraexe

geraos: main.c vetor.c
	gcc -c main.c vetor.c

geraexe:
	gcc main.o vetor.o -o prog

clean:
	rm -rf *.o prog