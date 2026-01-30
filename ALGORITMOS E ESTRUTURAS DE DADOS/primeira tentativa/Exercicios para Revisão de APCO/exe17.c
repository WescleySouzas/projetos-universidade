#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preecher(int vet[], int tam){
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        vet[i] = (rand()%35) - 15;
    }
}


int main(){
    int n;
    scanf("%d", &n);

    int vet[n];

    preecher(vet, n);

    for (int i = 0; i < n; i++){
        printf("%d, ", vet[i]);
    }

}