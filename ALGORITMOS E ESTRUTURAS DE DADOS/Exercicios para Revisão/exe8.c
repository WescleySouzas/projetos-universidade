#include <stdio.h>

void quadrado(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("*");
            
        }printf("\n");
    }
}
void tringuloLado1(){
    int j = 1;
    for(int i = 1; i <= 5- j +1; i++){
        for(; j <= 5; j++){
            printf("*");
        }
        printf("\n");
    }
}


void trianguloLado2(){
     for (int i = 1; i <= 5; i++) {  
        for (int j = 1; j <= 5 - i + 1; j++) {  
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    trianguloLado1();

}