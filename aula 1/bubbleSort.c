#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int *v, int tamanho){
    int i, j, temp;
    for(i = tamanho - 1; i >= 0; i--){
        for(j = 1; j <= i; j++){
            if(v[j-1] > v[j]){
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            }
        }
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
    bubbleSort(A, 7);
    imprime(A, 7);    


    return 0;
}