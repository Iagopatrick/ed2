// Grupo 13, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues

#ifndef LISTA_H
#define LISTA_H

#include "no.h"
//estrutura Lista
typedef struct lista{
    No *inicio;
    No *fim;
}Lista;

//Funções de Lista
Lista *criaLista();
void insereNo(int chave, Lista *l);





#endif