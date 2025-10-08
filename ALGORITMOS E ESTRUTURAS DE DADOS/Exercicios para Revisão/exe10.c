#include <stdio.h>

void extraçao(float n, int *inteira, float *frac){
    *inteira = n;
    *frac = n - (int) n;
}

int main(){
    float n = 3.45, franc;
    int inteiro;

    extraçao(n, &inteiro, &franc);
    printf("%d, %.2f\n", inteiro, franc);
}