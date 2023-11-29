#include <stdio.h>
#include <stdlib.h>


int *Particao(int *A, int p, int r){
    int k, x, i, j, temp, *resposta;
    resposta = (int *) malloc(sizeof(int) * 2);
    x = A[r];
    i = p-1;
    j = p;
    k = r;
    for(j = p; j < k; j++){
        if(A[j] < x){
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }else if(A[j] == x){
            k--;
            temp = A[j];
            A[j] = A[k];
            A[k] = temp;
            j--; //Não deixando o J atualizar
        }
    }
    x = j;
    j = i+1;
    for(k; k < r+1; k++){
        temp = A[j];
        A[j] = A[k];
        A[k] = temp;
        k++;
        j++;
    }
    j = x;
   
    resposta[0] = i+1;
    resposta[1] = j-1;

    return resposta;
}
void QuickSort(int *A, int p, int r){
    int *q, a, b;
    if(p < r){
        q = Particao(A, p, r);
        a = q[0];
        b = q[1];
        QuickSort(A, p, a-1);
        QuickSort(A, b + 1, r);
    }
} 

void Imprime(int *A, int tamanho){
    for(int i=0; i< tamanho; i++){
        printf("%d: %d\n", i, A[i]);
    }
}


int main(){
    int A[7] = {3, 2, 6, 5, 5, 4, 4};

    Imprime(A, 7);
    QuickSort(A, 0, 6);
    printf("\nOrdenado: \n");
    Imprime(A, 7);
    return 0;
}