#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sorteio(){
    int numero = rand() % 100;
    return numero;
}

int main(){
    srand(time(NULL));

    int numero = sorteio();
    int n = 0;
    int count = 0;
    while(1){
        printf("Digite o numero desejado: ");
        scanf("%d", &n);

        if(n == numero){
            printf("PARABENS, voce acertou o numero!!\n");
            return 1;
        }
        else{
            if(n < numero){
                printf("ERROU, o numero desejado e MAIOR\n");
            }
            else{
                printf("ERROU, o numero desejado e MENOR\n");
            }
            count++;
            if(count == 10){
            printf("As chances acabaram, VOCE PERDEU!!");
            return 0;
        }
        }
       
    }

}