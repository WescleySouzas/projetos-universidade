#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    
    int vet[15];
      for(int i = 0; i < 15; i++){
        vet[i] = rand()%15;
        printf("%d ", vet[i]);
    }
    printf("\n");

    int menor = vet[0];
    int posicao;

    for(int i = 1; i < 15; i++){
        if(menor > vet[i]){
            menor = vet[i];
            posicao = i + 1;
        }
    }

    printf("O menor valor do vetor eh: %d e esta na posicao %d do vetor", menor, posicao);
}