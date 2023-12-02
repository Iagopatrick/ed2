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
    // size_t tamanhoVetor = 0;
    // Lista *l = criaLista();

    // do{
    //     fgets(dnaVirus, 71, padroesVirus);
        
    //     if(linhaVariante == 1){ //Essa linha refere-se a uma variante
    //         linhaVariante *= -1;
    //         printf("%s", dnaVirus+1);
    //         continue;
    //     }
    //     // fgets(dnaAnimal, 71, baseDadosDna);
    //     // fgets(dnaAnimal, 71, baseDadosDna);
    //     // printf("%s\n", dnaAnimal);
    //     // printf("%s\n", dnaVirus);
    //     int r = kmp("ABCDABCC", "ABCC");
        
        
    //     break;
        
    // }while(dnaVirus[1] != 'E');
    printf("AWD");
    int r = kmp("ABCDABCC", "ABCC");

    


    int x;
    // x = kmp(string, padrao, 10, 4);

    return 0;
}

// A cada iteração o sistema percorre com a variante todos os dna e printa o que é preciso na tela