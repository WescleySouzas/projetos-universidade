#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    for(int i = 0; i < 100; i++){
        printf("%d ", 5 + rand() % 21);
    }
}