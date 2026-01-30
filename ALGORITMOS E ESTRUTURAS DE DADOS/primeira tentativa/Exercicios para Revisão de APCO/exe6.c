#include <stdio.h>

float serieAlternada(int n){
    float total = 0;
    for(int den = 1; den <= n; den++){
        if(den % 2 == 0){
            total -= 1.0/den;
        }
        else{
            total += 1.0/den;
        }
    }
    return total;
}  

int main(){
    printf("%f", serieAlternada(20));
}