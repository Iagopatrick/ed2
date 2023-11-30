#include "kmp.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void iniciaVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = 0;
    }
}

void realocaVetor(int *vetor, int tamanho){
    int *temp = (int *) realloc(vetor, tamanho * sizeof(int));
    if(temp == NULL){
        perror("Erro ao tentar realocar o vetor.");
        exit(1);
    }

    vetor = temp;
}

int  *kmp(char *string, char *padrao){
    int padraoTamanho = strlen(padrao), strTamanho = strlen(string);
    int prefixo[padraoTamanho], respostas[1] = {0};

    iniciaVetor(prefixo, padraoTamanho);

    int j = -1;
    int flag = 0, r = -1;

    // fazendo o vetor de padroes
    for(int i = 0; i < padraoTamanho; i++){
        if(padrao[j] == padrao[i]){
            j++;
            prefixo[j] = j;
        }else if(padrao[j] != padrao[i] && j > 0){
            j--;
            prefixo[j] = j;
            i--;
        }
    }

    // for(int i = 0; i < 4; i++){
    //     printf("posicao: %d, valor: %d\n", i, prefixo[i]);
    // }

    j = 0;
    for(int i = 0; i < strTamanho; i++){
        
        if(string[i] == padrao[j] && padraoTamanho >= j){
            
            
            j++;
            if(j == padraoTamanho - 1){
                printf("\n\ni:%d\n\n", i);
                respostas[0] = i + 1 - j;
            }

        }else if(string[i] != padrao[j] && j > 0){
            printf("Devo voltar para: %d\n", prefixo[j]);
            j = prefixo[j];
            flag = 0;
        }
        
       
    }
        
    return respostas;
}




/* Antoações: é preciso saber como vou printar as informações vou passar um vetor de respostas para a main? Vou passar o padrão de saida para o kmp?

*/