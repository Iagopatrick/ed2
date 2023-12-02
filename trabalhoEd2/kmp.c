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

int *realocaVetor(int *vetor, int tamanho){
    //Tamanho é o novo tamanho a ser realocado
    int *temp = (int *) realloc(vetor, tamanho * sizeof(int));
    if(temp == NULL){
        perror("Erro ao tentar realocar o vetor.");
        exit(1);
    }

   
    return temp;
}

int *alocaVetor(int tamanho){
    int *vetor = (int *) malloc(tamanho*sizeof(int));
    if(vetor == NULL){
        perror("Vetor nao alocado corretamente!");
        exit(1);
    }
    return vetor;
}


int *funcaoPrefixo(char *padrao){
    int tamanhoPadrao = strlen(padrao);
    int *prefixo, k = -1;
    prefixo = alocaVetor(tamanhoPadrao);
    prefixo[0] = -1;

    for(int q = 0; q < tamanhoPadrao; q++){
        while(k > -1 && padrao[k+1] != padrao[q]){
            k = prefixo[k];
        }
        if(padrao[k+1] == padrao[q]){
            k++;
        }
        prefixo[q] = k;
    }

    return prefixo;
}



int  kmp(char *dnaAminal, char *dnaVirus){
    int q = -1, m, n; //q-> indice no vetor de prefixo, m -> tamanho do dna do virus, n -> tamanho do dna do animal
    int *prefixo;
    int qntdIndices = 0; //indice correspondente das respostas na linha analisada
    
    
    prefixo = funcaoPrefixo(dnaVirus);
    m = strlen(dnaVirus);
    n = strlen(dnaAminal);
    for(int i = 0; i < n; i++){
        while(q > -1 && dnaVirus[q+1] != dnaAminal[i]){
            q = prefixo[q];
        }
        if(dnaVirus[q+1] == dnaAminal[i]){
            q++;
        }
        if(q == m){
            
            printf("Esta localizado em %d\n", i-m);
            q = prefixo[q];
            qntdIndices++;
        }

    }
    return qntdIndices;
}




/* Antoações: é preciso saber como vou printar as informações vou passar um vetor de respostas para a main? Vou passar o padrão de saida para o kmp?

*/