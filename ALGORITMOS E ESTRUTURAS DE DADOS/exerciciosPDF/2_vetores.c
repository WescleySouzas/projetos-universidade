#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[10];
    for(int i = 0; i < 10; i++){
        vet[i] = i;
    }

    for(int i = 0; i < 10; i++){
        if(i % 2 == 0){
            printf("vet[%d] = %d\n", vet[i], i);
        }
    }
}