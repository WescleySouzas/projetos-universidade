#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int vet[5];
    int escalar = 2;

    srand(time(NULL));

    for(int i = 0; i < 5; i++){
        vet[i] = rand()%50;
        printf("%d ", vet[i]);
    }
    
    printf("\n");

    for(int i = 0; i < 5; i++){
        int produto = vet[i] * escalar;

        printf("%d ", produto);
    }


}
