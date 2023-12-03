// Grupo 13, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues

#ifndef NO_H
#define NO_H
#include <stdlib.h>
#include <stdio.h>

//Estrutura da estrutura Nó, que compoe a lista
typedef struct no{
    int chave;
    struct no *prox;
}No;
//Funções do no
No *criaNo(int chave);





#endif