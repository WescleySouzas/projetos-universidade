#include <stdio.h>

// exercicio numero 1
int somaNumeros(int x){
    int total = 0;
    for(int i = 0; i < x; i++){
        total += i;
    }
    return total;
}

// exercicio numero 2
int somaNumerosIpares(int x){
    int total = 0;
    for(int i = 1; i < x; i += 2){
        total += i;
    }
    return total;
}

// exercicio numero 3
int produtoPares(int n){
    int total = 1;
    for(int i = 2; i <= n; i+=2){
        total *= i;
    }
    return total;   
}

// exercicio numero 4
int serieAlternada(int x){
    
    if(x % 2 == 0){
        return -x / 2;
    }
    else{
        return (x + 1)/ 2;
    }
}

int main()
{
    
    printf("%d", somaNumeros(101));

    printf("\n%d\n", somaNumerosIpares(101));
    
    printf("%d\n", produtoPares(10));

    printf("%d", serieAlternada(5));
    return 0;
}
