#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void encherV(int vet[], int tam){
      for(int i = 0; i < tam; i++){
        vet[i] = rand()%10;
    }
}

void monstraV(int v[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}


int main(){
    srand(time(NULL));

    int V[20];
    encherV(V, 20);

    int vetpar[10], vetimpar[10];
    int p = 0, imp = 0;

    for(int i = 0; i < 20; i++){
        if(V[i] % 2 == 0){
            if(p < 10){
            vetpar[p++] = V[i];
            }
        }
        else{
            if(imp < 10){
            vetimpar[imp++] = V[i];
            }
        }
    }
    
    monstraV(V, 20);
    monstraV(vetpar, 10);
    monstraV(vetimpar, 10);
}