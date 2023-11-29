#include <stdio.h>

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
    char string[10] = "abacabcde", padrao[4] = "abc";
    int x;
    x = kmp(string, padrao, 10, 4);
}

