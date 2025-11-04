#include <stdio.h>

int fibonacci(int n){
    int anterior = 0;
    int proximo = 1;
    int soma = 0;

    for(int i = 0; i < n; i++){
        soma = anterior + proximo;
        anterior = proximo;
        proximo = soma;
    }
    return soma;
}

int main(){
    int n = 10;

    printf("%d", fibonacci(n));

}