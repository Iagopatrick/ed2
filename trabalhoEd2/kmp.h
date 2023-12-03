// Grupo 13, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues

#ifndef KMP_H
#define KMP_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// funções do kmp
int *alocaVetor(int tamanho);
int *funcaoPrefixo(char *padrao);
void kmp(char *dnaAnimal, char *dnaVirus, Lista *l, int indiceArquivo);




#endif