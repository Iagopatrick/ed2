# Grupo 13, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues
CC=gcc

CFLAGS=-O0 -c -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow 

all : main 

main : kmp.o main.o lista.o no.o
	$(CC)  kmp.o main.o lista.o no.o -o main

main.o: main.c
	$(CC) $(CFLAGS) main.c


kmp.o : kmp.c kmp.h
	$(CC) $(CFLAGS) kmp.c

lista.o : lista.c lista.h
	$(CC) $(CFLAGS) lista.c

no.o : no.c no.h
	$(CC) $(CFLAGS) no.c

 

clean : 
	rm *.o main kmp

run: 
	make && clear && ./main