CFLAGS = -Wall -Wextra -std=c99

all: grafo

grafo: matriz_adj.o
	$(gcc) $(CFLAGS) -o grafo matriz_adj.o

grafo.o: grafo.c grafo.h
	$(gcc) $(CFLAGS) -c grafo.c

clean:
	rm -f grafo *.o
