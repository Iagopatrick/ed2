// Grupo 15, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues

#include "no.h"
#include "lista.h"

Lista *criaLista(){
   
    Lista *novaLista;
    novaLista = (Lista *) malloc(sizeof(Lista));
    if(novaLista == NULL){
        perror("Alocacao de lista invalida!");
        exit(1);
    }
    novaLista->fim = NULL;
    novaLista->inicio = NULL;
    return novaLista;
}


void insereNo(int chave, Lista *l){
    No *aux = criaNo(chave);
    if(l->fim == NULL){
        l->inicio = aux;
        l->fim = aux;
    }else{

        l->fim->prox = aux;
        l->fim = aux;
    }
}