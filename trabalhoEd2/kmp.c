// Grupo 13, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues
#include "kmp.h"


int *alocaVetor(int tamanho){
    // Aloca um vetor com tamanho na memória
    int *vetor = (int *) malloc(tamanho*sizeof(int));
    if(vetor == NULL){
        perror("Vetor nao alocado corretamente!");
        exit(1);
    }
    return vetor;
}

// Função responsável por criar o vetor de prefixos
int *funcaoPrefixo(char *padrao){
    int tamanhoPadrao = strlen(padrao) - 1; //-1 por conta do \n contido na string
    int *prefixo, k = -1;//Ponteiro de vetor prefixo e o k é o indice que percorre o prefixo dentro do vetor de padrao, começa em -1 pois não existe prefixo no inicio
    
    // Alocação do vetor prefixo
    prefixo = alocaVetor(tamanhoPadrao);
    prefixo[0] = -1; //Primeira posição sempre começa com -1
    // Percorrendo o padrão, a partir da segunda posição
    for(int q = 1; q < tamanhoPadrao; q++){ 
        // Caso o k+1 seja diferente do q, o prefixo termina e k volta as posições contidas no padrao
        while(k > -1 && padrao[k+1] != padrao[q]){
            k = prefixo[k];
        }
        // Caso a posição do padrão seja igual ao prefixo, aumenta o tamanho do prefixo
        if(padrao[k+1] == padrao[q]){
            k++;
        }
        // Prefixo na posição do padrão recebe o valor do indice k
        prefixo[q] = k;
    }

    return prefixo;
}



void kmp(char *dnaAnimal, char *dnaVirus, Lista *l, int indiceArquivo){
    //q-> indice no vetor de prefixo, m -> tamanho do dna do virus, n -> tamanho do dna do animal
    int q = -1, m, n; 
    //Ponteiro para o vetor de prefixo
    int *prefixo;
   
    prefixo = funcaoPrefixo(dnaVirus);

    //-1 para retirar o \n e -1 para m conseguir ter o valor dos indices do vetor de prefixo
    m = strlen(dnaVirus) - 2; 

    //Não precisa do -1 pois no loop a ultima posição não é acessada, que seria a posição do \n
    n = strlen(dnaAnimal);
    
    //Loop para percorre a string a ser comparada
    for(int i = 0; i < n; i++){
        // Caso o vetor do padrão tenha uma diferença na string a sser comparada, q volta para a posição do possível prefixo
        while(q > -1 && dnaVirus[q+1] != dnaAnimal[i]){
            q = prefixo[q];
        }
        // Caso seja iguais, o indice no vetor de padrao avança
        if(dnaVirus[q+1] == dnaAnimal[i]){
            q++;
        }
        // Caso que o vetor de padrao foi todo encontrado na string analisada
        if(q == m){
            // O contador é acrescido de +1
            l->inicio->chave++;
            // O indice que ocorreu é inserido na lista + o valor do indice correspondente da linha
            insereNo((i-m) + indiceArquivo, l);
            q = -1;
            
        }

    }
    //terminada a função, o vetor prefixo pode liberar os recursos
    free(prefixo);
}