#include <stdio.h>
#include <stdlib.h>


int *merge(int *v1, int *v2, int t1, int t2){
  int i = 0, j = 0, k = 0;
  int *r = (int *) calloc(t1+t2, sizeof(int));
  while(i < t1||j < t2){
    if(i < t1 && j < t2){
        if(v1[i] < v2[j]){
            r[k] = v1[i];
            i++;
        }else{
            r[k] = v2[j];
            j++;
        }
    }else if(i < t1){
        r[k] = v1[i];
        i++;
    }else{
        r[k] = v2[j];
        j++;
    }
    k++;
  }
  return r;
}

int *mergeSort(int *v, int tamanho){
    if(tamanho == 1){
        return v;
    }
    int *l1, *l2, t1, t2;
    if(!(tamanho & 1)){
        t1 = tamanho/2;
        t2 = t1;
    }else{
        t1 = tamanho/2;
        t2 = t1 + 1;
    }
    l1 = (int *) calloc(t1, sizeof(int));
    l2 = (int *) calloc(t2, sizeof(int));

    for(int i = 0; i < tamanho; i++){
        if(i < t1){
            l1[i] = v[i];
        }else{
            l2[i - t1] = v[i];
        }
    }
    int *d1 = mergeSort(l1, t1);
    int *d2 = mergeSort(l2, t2);

    return merge(d1, d2, t1, t2);
}
void imprime(int *A, int tamanho){
    printf("{");
    for(int i = 0; i < tamanho; i++){
        printf("%d,", A[i]);
    }
    printf("}\n");

}


int main(){
    int *A = (int *)calloc(8, sizeof(int));
    // int A[8] = {13, 4, 15, 9, 2, 7, 10, 8};
    A[0] = 13;
    A[1] = 4;
    A[2] = 15;
    A[3] = 9;
    A[4] = 2;
    A[5] = 7;
    A[6] = 10;
    A[7] = 8;
    


    imprime(A, 8);
    A = mergeSort(A, 8);
    imprime(A, 8);    


    return 0;
}