#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int procura(int v[], int num){
    for(int i = 0; i < 15; i++){
        if(num == v[i]){
            return num;
        }
    }
    return -1;
}

int main(){
    srand(time(NULL));

    int vet[15];
      for(int i = 0; i < 15; i++){
        vet[i] = rand()%15;
        printf("%d ", vet[i]);
    }
    printf("\n");

    printf("%d", procura(vet, 5));
}