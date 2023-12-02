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
    
    //Lógica de percorrer o arquivo de padroes
    char dnaVirus[71];
    int linhaVariante = 1; //flag para saber que estou na linha do nome do vírus
    char dnaAnimal[71];
    char nomeAnimal[71];
    int linhaNomeAnimal = 1;
    

    
    Lista *l = criaLista();

    while(dnaVirus[1] != 'E'){//loop dos virus
        fgets(dnaVirus, 71, padroesVirus);
        if(dnaVirus[1] == 'E'){
            break;
        }
        if(linhaVariante == 1){ //Essa linha refere-se a uma variante
            linhaVariante *= -1;
            printf("%s", dnaVirus+1);
            continue;
        }
        
        baseDadosDna = fopen("BaseDadosDNA.txt", "r");
        if(baseDadosDna == NULL){
            printf("Erro, arquivo BaseDadosDNA nao pode ser aberto!");
            system("pause");
            exit(1);
        }

        do{//percorrendo o arquivo de animais
            fgets(dnaAnimal, 71, baseDadosDna);
            if(linhaNomeAnimal == 1){//salva o nome do animal e pega a primeira linha do dna do animal, colocando essa linha no padrao animal
                strcpy(nomeAnimal, dnaAnimal+1);
                linhaNomeAnimal *= -1;
                nomeAnimal[strcspn(nomeAnimal, "\n")] = '\0';
                    
                continue;
            }
            
            
            int indiceArquivo = 0;
            
            insereNo(0, l);
            
            
            do{
                int *tmp;
                dnaAnimal[strcspn(dnaAnimal, "\n")] = '\0';
                tmp = kmp(dnaAnimal, dnaVirus);
                // printf("O que estou recebendo: %s\n", dnaAnimal);
                l->inicio->chave += tmp[0];
                if(tmp[0] != 0){
                    insereNo(tmp[1] + indiceArquivo, l);
                }
                fgets(dnaAnimal, 71, baseDadosDna);

                if(strcspn(dnaAnimal, "\n") == 0){
                    fgets(dnaAnimal, 71, baseDadosDna);
                }
                indiceArquivo += sizeof(dnaAnimal) - 1;
                
            }while (dnaAnimal[0] != '>');
            
            
            // printf("%s\n", nomeAnimal);
            if(l->inicio->chave > 0){
                printf("[%s]", nomeAnimal);
                printf(" no. de ocorrencias: %d posicoes: ", l->inicio->chave);
                No *aux = l->inicio->prox;
                
                while(aux != NULL){
                    if(aux->chave != 0)
                    printf("%d ", aux->chave);
                    aux = aux->prox;
                }
                printf("\n");
            }
            free(l);
            l = criaLista();
            // linhaNomeAnimal *= -1;
            strcpy(nomeAnimal, dnaAnimal + 1);
            nomeAnimal[strcspn(nomeAnimal, "\n")] = '\0';

        }while(dnaAnimal[1] != 'E');
        fclose(baseDadosDna);
        linhaNomeAnimal *= -1;
        
        linhaVariante *= -1;
        

        
    };
    
   

    return 0;
}

// A cada iteração o sistema percorre com a variante todos os dna e printa o que é preciso na tela