// Grupo 15, Iago Patrick de Melo Gripp Vilas Boas e Victor Henrique Rodrigues

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kmp.h"




int main(){
    FILE *padroes, *baseDados;
    // Abertura de arquivos
    padroes = fopen("PadroesVirus.txt", "r");
    if(padroes == NULL){
        printf("Erro, arquivo PadroesVirus nao pode ser aberto!");
        system("pause");
        exit(1);
    }
    baseDados = fopen("BaseDadosDNA.txt", "r");
    if(baseDados == NULL){
        printf("Erro, arquivo BaseDadosDNA nao pode ser aberto!");
        system("pause");
        exit(1);
    }
    //Lógica de percorrer o arquivo de padroes
    char padrao[71];
    int linhaVariante = 1;
    char linha[71];
    // char padrao[8] = "ABCDABCA";

    
    do{
        fgets(padrao, 70, padroes);
        
        if(linhaVariante == 1){ //Essa linha refere-se a uma variante
            fgets(linha, 70, baseDados);
            fgets(linha, 70, baseDados);
            fgets(padrao, 70, padroes);
            // padrao = "ABCDABCA";
            
            printf("%s", padrao);
            printf("%s", linha);
            
            kmp(linha, padrao);
        }


        // Mostrar o resultado da variante atual

        break;
    }while(padrao[1] != 'E');

    


    int x;
    // x = kmp(string, padrao, 10, 4);

    return 0;
}

// A cada iteração o sistema percorre com a variante todos os dna e printa o que é preciso na tela