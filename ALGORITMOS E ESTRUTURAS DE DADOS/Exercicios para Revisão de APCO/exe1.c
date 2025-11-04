#include <stdio.h>

int somaNumeros(int x){
    int total = 0;
    for(int i = 0; i <= x; i++){
        total += i;
    }
    return total;
}

int main(){
    printf("%d", somaNumeros(100));
}