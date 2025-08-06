#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b){
    int n;
    n = *a;
    *a = *b;
    *b = n;
}

int main(){
    /* 
    
    int i = 0;
    int vetor[3] = {4, 7, 1};
    int *ptr= vetor;
    printf("%p\n", vetor);
    printf("%p\n", ptr);

    for(i=0;i<3; i++){
        printf("O endereco do indice %d do vetor eh %p\n", i, &ptr[i]);
        printf("o valor do indice %d do vetor eh %d\n", i, ptr[i]);
        
    }

    */

    int a = 5;
    int b = 10;

    printf("%d\t %d", a, b);

    trocar(a,b);

    printf("%d \t %d", a , b);
}