// Grupo 15, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues

#ifndef LISTA_H
#define LISTA_H

#include "no.h"

typedef struct lista{
    No *inicio;
    No *fim;
}Lista;

Lista *criaLista();
void insereNo(int chave, Lista *l);





#endif