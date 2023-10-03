#include <stdio.h>



int Particao(int *A, int p, int r){
    int k, x, i, j, temp;
    x = A[r];
    i = p-1;
    j = p;
    k = r;
    for(j = p; j < r; j++){
        if(A[j] < A[r]){
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;
    return i+1;
}
void QuickSort(int *A, int p, int r){
    int q;
    if(p < r){
        q = Particao(A, p, r);
        
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
} 

void Imprime(int *A, int tamanho){
    for(int i=0; i< tamanho; i++){
        printf("%d: %d\n", i, A[i]);
    }
}


int main(){
    int A[5] = {6, 5, 2, 4, 3};

    Imprime(A, 5);
    QuickSort(A, 0, 4);
    printf("\nOrdenado: \n");
    Imprime(A, 5);
    return 0;
}