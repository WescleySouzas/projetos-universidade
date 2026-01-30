#include <stdio.h>

unsigned long prod_naturais(unsigned n) {
    unsigned long produto = 1;
    for(int i = 1; i <= n; i++)
        produto *= i*2; // iteração
    
    return produto;
}

int main() {
    int n;
    printf("Entre com um numero natural n [1, 20]: ");

    scanf("%d", &n);

    for(int i = 1; i <= 20; i++)
        printf("Produto (%5d): %-20ld\n", i, prod_naturais(i));

    return 0;
}