#include <stdio.h>

float soma(int n){
    float total = 0;

    for(int den = 1, num = 1; num < n; num++, den+=2){
        total += (float) num/den;
    }
    return total;
}

int main(){
    printf("%.2f", soma(10));
}