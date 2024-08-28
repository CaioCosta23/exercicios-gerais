all: geraos geraexe

geraos: main.c agendatarefas.c tarefasoma.c tarefamultiplica.c tarefaimprime.c
	gcc -c agendatarefas.c tarefasoma.c tarefamultiplica.c tarefaimprime.c

geraexe: main.o agendatarefas.o tarefasoma.o tarefamultiplica.o tarefaimprime.o
	gcc main.o agendatarefas.o tarefasoma.o tarefamultiplica.o tarefaimprime.o -o prog

clean:
	rm -rf *.o prog