#include <stdio.h>
#include <stdlib.h>
# include <time.h>

int main(){
    srand(time(NULL));
    int vet[15];

    for(int i = 0; i < 15; i++){
        vet[i] = rand()%15;
        printf("%d ", vet[i]);
    }
    printf("\n");

    int valor = 5;
    int count = 0;

    for(int i = 0; i < 15; i++){
        if (valor == vet[i]){
            printf("Valor encontrado!!\n");
            count++;
        }
        if(i == 15 && count == 0){
            printf("Valor nao encontrado!!\n");
        }
    }
    printf("O valor esta presente no vetor %d vezes", count);


}