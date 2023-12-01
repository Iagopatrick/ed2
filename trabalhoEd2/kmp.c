// Grupo 15, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues
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
    int padraoTamanho = strlen(padrao)-1, strTamanho = strlen(string)-1;
    int prefixo[padraoTamanho], *respostas;
    respostas = (int *) malloc(2*sizeof(int));
    respostas[0] = respostas[1] = 0;
    printf("\nTamanho do vetor %d\n", padraoTamanho);
    printf("%s\n", padrao);
    iniciaVetor(prefixo, padraoTamanho);

    int j = 0;
    int r = -1;

    // fazendo o vetor de padroes
    for(int i = 0; i < padraoTamanho; i++){
        if(padrao[j] == padrao[i]){
            printf("entrei aqui");
            j++;
            r++;
            prefixo[i] = r>-1? r:0;
        }else if(padrao[j] != padrao[i] && j >= 0){
            j = prefixo[j];
            
            i--;
        }else{

            prefixo[i] = r>-1? r:0;
        }
    }

    for(int i = 0; i < padraoTamanho; i++){
        printf("posicao: %d, valor: %d\n", i, prefixo[i]);
    }

    j = 0;
    for(int i = 0; i < strTamanho; i++){
        
        if(string[i] == padrao[j] && padraoTamanho >= j){
            
            
            j++;
            if(j == padraoTamanho - 1){
                printf("\n\ni:%d\n\n", i);
                respostas[0] = i + 1 - j;
                // flag = 1;
            }

        }else if(string[i] != padrao[j] && j > 0){
            // printf("Devo voltar para: %d\n", prefixo[j]);
            j = prefixo[j];
            // flag = 0;
        }
        
       
    }
        printf("r: %d", respostas[0]);
    return respostas;
}




/* Antoações: é preciso saber como vou printar as informações vou passar um vetor de respostas para a main? Vou passar o padrão de saida para o kmp?

*/