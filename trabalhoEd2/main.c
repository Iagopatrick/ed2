// Grupo 15, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kmp.h"
#include "lista.h"



int main(){
    FILE *padroesVirus, *baseDadosDna;
    // Abertura de arquivos
    padroesVirus = fopen("PadroesVirus.txt", "r");
    if(padroesVirus == NULL){
        printf("Erro, arquivo PadroesVirus nao pode ser aberto!");
        system("pause");
        exit(1);
    }
    baseDadosDna = fopen("BaseDadosDNA.txt", "r");
    if(baseDadosDna == NULL){
        printf("Erro, arquivo BaseDadosDNA nao pode ser aberto!");
        system("pause");
        exit(1);
    }
    //Lógica de percorrer o arquivo de padroes
    char dnaVirus[71];
    int linhaVariante = 1; //flag para saber que estou na linha do nome do vírus
    char dnaAnimal[71];
    char nomeAnimal[71];
    int linhaNomeAnimal = 1;
    char *padraoAnimal;
    size_t tamanhoVetor = 0;
    Lista *l = criaLista();

    do{//loop dos virus
        fgets(dnaVirus, 71, padroesVirus);
        
        if(linhaVariante == 1){ //Essa linha refere-se a uma variante
            linhaVariante *= -1;
            printf("%s", dnaVirus+1);
            continue;
        }
       
        do{//percorrendo o arquivo de animais
            fgets(dnaAnimal, 71, baseDadosDna);
            if(linhaNomeAnimal == 1){//salva o nome do animal e pega a primeira linha do dna do animal, colocando essa linha no padrao animal
                strcpy(nomeAnimal, dnaAnimal+1);
                linhaNomeAnimal *= -1;
                printf("\nnome animal:%s\n", nomeAnimal);    
                continue;
            }
            
            
            int indiceArquivo = 0;
            
            insereNo(0, l);
            
           
            do
            {
                int *tmp;
                tmp = kmp(dnaAnimal, dnaVirus);
                l->inicio->chave += tmp[0];
                printf("valor da minha chave inicio: %d\n", l->inicio->chave);

                for(int i = 1; i < sizeof(kmp); i++){
                    insereNo(tmp[i]+indiceArquivo, l);
                }
                indiceArquivo += sizeof(dnaAnimal);
                fgets(dnaAnimal, 71, baseDadosDna);
                
            } while (dnaAnimal[0] != '>');
            printf("ocorrencias: %d\n", l->inicio->chave);
            
            printf("%s\n", nomeAnimal);
            // printf("no. ocorrencias %d\n", l->inicio->chave);

            
            break;
        }while(dnaAnimal[1] != 'E');
        
        
        break;
        
    }while(dnaVirus[1] != 'E');
    
   

    return 0;
}

// A cada iteração o sistema percorre com a variante todos os dna e printa o que é preciso na tela