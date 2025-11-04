#include <stdio.h>

int somaNumerosIpares(int x){
    int total = 0;
    for(int i = 1; i <= x; i += 2){
        total += i;
    }
    return total;
}

int main(){
    printf("%d", somaNumerosIpares(100));
}