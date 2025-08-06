#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maxmin1(int A[], int *max , int *min){
    int i;
    *min = A[0];
    *max =  A[0];

    for(i = 1; i < 10; i++){
        if(A[i] >= *max){
            *max = A[i];
        }
        else if(A[i] <= *min){
            *min = A[i];
        }
    }
}

int main(){

    int *valores = (int*)malloc(10 *sizeof(int));

    srand(time(NULL));

    for(int i = 0; i<10; i++){
        valores[i] = rand() % 50;
        printf("%d ", valores[i]);
    }
    printf("\n");

    int max, min;
    maxmin1(valores, &max, &min);
    
    printf("Valores maximos: %d\n", max);
    printf("Valores minimo: %d\n", min);
    
    

    free(valores);
    return 0;
}