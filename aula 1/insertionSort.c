#include <stdio.h>
#include <stdlib.h>


void insertionSort(int *v, int tamanho){
    int chave = -1, i = 0;
    for(int j = 1; j < tamanho; j++){
        chave = v[j];
        i = j - 1;
        while(i >= 0 && v[i] > chave){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = chave;
    }


}
void imprime(int *A, int tamanho){
    printf("{");
    for(int i = 0; i < tamanho; i++){
        printf("%d,", A[i]);
    }
    printf("}\n");

}


int main(){
    int A[7] = {7, 4, 3, 8, 2, 5, 3};
    imprime(A, 7);
    insertionSort(A, 7);
    imprime(A, 7);    


    return 0;
}