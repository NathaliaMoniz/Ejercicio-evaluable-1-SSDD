CC = gcc
CFLAGS = -Wall -O2

all: cliente servidor

cliente: cliente.o claves.o
	$(CC) $(CFLAGS) -o cliente cliente.o claves.o

servidor: servidor.o claves.o
	$(CC) $(CFLAGS) -o servidor servidor.o claves.o

cliente.o: cliente.c claves.h message.h
	$(CC) $(CFLAGS) -c cliente.c

servidor.o: servidor.c claves.h message.h
	$(CC) $(CFLAGS) -c servidor.c

claves.o: claves.c claves.h
	$(CC) $(CFLAGS) -c claves.c

clean:
	rm -f cliente servidor *.o
