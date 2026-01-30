#include <stdio.h>

float somar(int n){
    float resultado = 0;
    for (int den = 1; den <= n; den++){
        resultado += 1.0/den;
    }
    return resultado;
}

int main(){
    printf("%.2f", somar(10));
}