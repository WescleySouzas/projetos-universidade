#include <stdio.h>
#include "listaencadeada.h"


typedef struct lista Lista;

int main(){
    Lista* L;
    L = lst_cria();

    for(int i = 1; i <= 5; i++){
        L = lst_insere_inicio(L, i);
    }
    lst_imprime(L);

    printf("\n");
    
    L = lst_retira(L, 4);
    lst_imprime(L);

    lcirc_imprime(L);
}

