#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int kmp(char *string, char *padrao, int strTamanho, int padrao_tamanho){
    int prefixo[4] = {0, 0, 0, 0};
    int respostas[4] = {0, 0, 0, 0};
    int j = -1;
    int flag = 0, r = -1;
    for(int i = 0; i < padrao_tamanho; i++){
        if(padrao[j] == padrao[i]){
            j++;
            prefixo[j] = j;
        }else if(padrao[j] != padrao[i] && j > 0){
            j--;
            prefixo[j] = j;
            i--;
        }
    }

    for(int i = 0; i < 4; i++){
        printf("posicao: %d, valor: %d\n", i, prefixo[i]);
    }
    j = 0;
    for(int i = 0; i < strTamanho; i++){
        printf("Letra da string: %c", string[i]);
        if(string[i] == padrao[j] && padrao_tamanho >= j){
            printf("Achei uma posicao: %d\n", j);
            printf("letra do padrao, letra comparada %c, %c\n", padrao[j], string[i]);
            j++;
            if(j == padrao_tamanho - 1){
                printf("\n\ni:%d\n\n", i);
                respostas[0] = i + 1 - j;
            }

        }else if(string[i] != padrao[j] && j > 0){
            printf("Devo voltar para: %d\n", prefixo[j]);
            j = prefixo[j];
            flag = 0;
        }
        
        printf("valor de i: %d\n", i);
    }
        printf("\nsua string ta aqui: %d\n", respostas[0]);
    return j;
}




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
    do{
        fgets(padrao, 70, padroes);
        
        if(linhaVariante == 1){ //Essa linha refere-se a uma variante
            
            printf("%s", padrao + 1);
        }


        // Mostrar o resultado da variante atual

        break;
    }while(padrao[1] != 'E');

    


    int x;
    // x = kmp(string, padrao, 10, 4);

    return 0;
}

// A cada iteração o sistema percorre com a variante todos os dna e printa o que é preciso na tela