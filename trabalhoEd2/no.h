// Grupo 15, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues

#ifndef NO_H
#define NO_H
#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int chave;
    struct no *prox;
}No;

No *criaNo(int chave);





#endif