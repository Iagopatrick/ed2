CC=gcc

CFLAGS=-O0 -c -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow 

all : main kmp

main : kmp.o main.o
	$(CC)  kmp.o main.o -o main




kmp.o : kmp.c
	$(CC) $(CFLAGS) kmp.c





 

clean : 
	rm *.o main kmp