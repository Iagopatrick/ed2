// Grupo 15, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues

#include <string.h>
#include <stdio.h>
#include <stdlib.h>




int *funcaoPrefixo(char *padrao){
    int tamanhoPadrao = strlen(padrao);
    int *prefixo, k = -1;
    prefixo = (int *) malloc(sizeof(int)*tamanhoPadrao);
    prefixo[0] = -1;

    for(int q = 1; q < tamanhoPadrao; q++){
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



void  kmp(char *dnaAminal, char *dnaVirus){
    
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
        if(q == m-1){
            
            q = prefixo[q];
            qntdIndices++;
        }

    }
    // return qntdIndices;
}



int main(){
    int *r;
    printf("Oi porra\n");
    
    r = funcaoPrefixo("AGGA");
    // printf("%d", r[0]);
    kmp("GGTACCTCCTACGGGAGGCAGCAGTGAGGAATTTTCCGCAATGGGCGAAAGCCTGACGGAGCAATACCGC", "AGGA");
    return 0;
}


/* Antoações: é preciso saber como vou printar as informações vou passar um vetor de respostas para a main? Vou passar o padrão de saida para o kmp?

*/