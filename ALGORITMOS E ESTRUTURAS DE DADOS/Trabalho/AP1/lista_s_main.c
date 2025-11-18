#include <stdio.h>
#include <stdlib.h>
#include "lista_s.h"
#include <time.h>

int main(){
    srand(time(NULL));

    lista *l1 = lista_inicializar(10);

    if(l1 == NULL){
        printf("Erro ao inicializar a lista!\n");
        return 1;
    }

    for(int i = 0; i <20; i++){
        int valor1 = rand() % 56 - 20;

        lista_inserir_fim(l1, valor1);
    }

    lista_exibir(l1);
    printf("\n");

    int impares_l1 = lista_contar_impares(l1);
    printf("Quantidade de ímpares em l1: %d\n", impares_l1);
    int consecutivos_l1 = lista_conta_consecutivos(l1);
    printf("Quantidade de números consecutivos em l1: %d\n", consecutivos_l1);
    lista_finalizar(l1);
    return 0;
}
