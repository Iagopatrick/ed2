// Grupo 15, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues
#include "no.h"

No *criaNo(int chave){
    No *tmp = (No *) malloc(sizeof(No));
    tmp->chave = chave;
    tmp->prox = NULL;
    return tmp;
}

