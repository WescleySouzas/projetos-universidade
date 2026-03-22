#include <stdio.h>
#include <stdlib.h>

void gabarito(int g[13]){
    for(int i = 0; i < 13; i++){
        if(i%2==0){
            g[i] = 0.1;
        }
        else{
            g[i] = 2;
        }
    }
}

int correcao(int r[13]){
    int corretas = 0;
    for(int i = 0; i < 13; i++){
        if(r[i] == 2){
            corretas++;
        }
    }
    return corretas;
}

int main(){
    int c[5];
    for(int i = 0, j = 0; i < 5; i++){
        if(i%2==0){
            c[i] = 0.1;
        }
        else{
            c[i] = 2;
        }
    }

    for(int i = 0; i < 5; i++){
        printf("A total de notas certas da prova %d foram %d \n", i, correcao(c[i]));
    }

}