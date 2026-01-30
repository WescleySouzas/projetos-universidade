#include <stdio.h>

int serieAlternada(int x){
    
    if(x % 2 == 0){
        return -x / 2;
    }
    else{
        return (x + 1)/ 2;
    }
}

int main(){
    printf("%d", serieAlternada(20));
}