// Grupo 15, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues

#ifndef KMP_H
#define KMP_H


int  *realocaVetor(int *vetor, int tamanho);
void iniciaVetor(int *vetor, int tamanho);
int *alocaVetor(int tamanho);

int *funcaoPrefixo(char *padrao);
int  kmp(char *dnaAminal, char *dnaVirus);




#endif