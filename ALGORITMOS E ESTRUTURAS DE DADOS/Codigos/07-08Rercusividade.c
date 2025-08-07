#include <stdio.h>
#include <stdlib.h>


int potencia(int x, int n){
    if (n == 0){
        return 1;
    }
    else{
        return x * potencia(x, n-1);
    }
}
int fibonacci(int n){
    if(n == 1){
        return 0;
    }
    else if(n ==2){
        return 1;
    }
    else{
        return fibonacci(n -1) + fibonacci(n - 2);
    }
}
    

int fatorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * fatorial(n - 1);
    }
}

int somatorio(int n){
    int i = 1; 
    
    if (n == 0){
        return 0;
    }
    else{
        return n + somatorio(n - 1);
    }
}
int main(){
    int x = 2;
    int n = 3;
    
    // Potencia
    int pot = potencia(x, n);
    printf("Resultado da Potencia: %d\n", pot);

    //Fibonacci
    int m = fibonacci(10);
    printf("Resultado da Fibonacci: %d\n", m);

    int num = 5;

    // Fatorial 
    int fat = fatorial(num);
    printf("Resultado do Fatorial: %d\n", fat);

    // Somatorio
    int soma = somatorio(num);
    printf("Resultado da Soma %d", soma);

    return 0;
}