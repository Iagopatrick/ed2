// Grupo 15, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues

#ifndef KMP_H
#define KMP_H


void realocaVetor(int *vetor, int tamanho);
void iniciaVetor(int *vetor, int tamanho);

int *kmp(char *string, char *padrao);



#endif