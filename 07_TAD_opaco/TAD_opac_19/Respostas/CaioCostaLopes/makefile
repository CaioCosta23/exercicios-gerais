all: geraos geraexe

geraos: main.c cidade.c defesa.c missil.c
	gcc -c main.c cidade.c defesa.c missil.c

geraexe: main.o cidade.o defesa.o missil.o
	gcc main.o defesa.o missil.o -o prog

clean:
	rm -rf *.o prog