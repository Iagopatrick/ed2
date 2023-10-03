#include <stdio.h>
#include <stdlib.h>


void selectionSort (int *A, int tamanho){
    int min = 0, aux = -1;
    for(int i = 0; i < tamanho-1; i++){
        min = i;
        for(int j = i+1; j < tamanho; j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
        aux = A[min];
        A[min] = A[i];
        A[i] = aux;
        
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
    selectionSort(A, 7);
    imprime(A, 7);
    return 0;
}