all: geraos geraexe

geraos: main.c matrizgenerica.c numcomplexo.c
	gcc -c main.c matrizgenerica.c numcomplexo.c

geraexe: main.o matrizgenerica.o numcomplexo.o
	gcc geraexe main.o matrizgenerica.o numcomplexo.o -o prog

clean:
	rm -f *.o prog