// Grupo 13, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues
#include "no.h"

// função que cria um nó e aloca na memória
No *criaNo(int chave){
    No *tmp = (No *) malloc(sizeof(No));
    tmp->chave = chave;
    tmp->prox = NULL;
    return tmp;
}

