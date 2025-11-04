#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maior(int vet[]){
    int maior = 1;
    for(int i = 0; i < 20; i++){
        if (vet[i] > maior){
            maior = vet[i];
        }
    }
    return maior;
}

int main(){
    srand(time(NULL));

    int vet[20];

    for(int i = 0; i < 20; i++){
        vet[i] = rand()%100;
        printf("%d ", vet[i]);
    }
    printf("\n");

    printf("O maior numero e: %d", maior(vet));
}