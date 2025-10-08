#include <stdio.h>

void soma(int a, int b, int *ret){
    *ret = a + b;
}

int main(){

    int  a = 4, b = 6;
    int resultado = 0;
    
    soma(a, b, &resultado);

    printf("%d\n", resultado);
}