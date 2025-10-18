#include <stdio.h>
#include "../includes/lista.h"

void apresentacao(lista *L);

int main() {
    lista *L1 = inicializar(5);
    apresentacao(L1);
    for(int i = 1; i <= capacidade(L1); i++) {
        if(inserir_meio(L1, i, tamanho(L1)+1))
            printf("Item %d inserido com sucesso\n", i);
        else
            printf("Erro na insercao do item %d\n", i);
        exibir(L1);
        printf("\n");
    }
    apresentacao(L1);
    L1 = liberar(L1);

    lista *L2 = inicializar(7);
    apresentacao(L2);
    int i = 1;
    while(!cheia(L2)) {
        if(inserir_meio(L2, i, tamanho(L2)+1))
            printf("Item %d inserido com sucesso\n", i);
        else
            printf("Erro na insercao do item %d\n", i);
        i++;
        exibir(L2);
        printf("\n");
    }
    apresentacao(L2);
    L2 = liberar(L2);

    return 0;
}

void apresentacao(lista *L) {
    printf("Capacidade de L: %d\n", capacidade(L));
    printf("Tamanho de L: %d\n", tamanho(L));

    if(vazia(L))
        printf("Lista L vazia\n");
    else
        printf("Lista L NAO vazia\n");

    if(cheia(L))
        printf("Lista L cheia\n");
    else
        printf("Lista L NAO cheia\n");
}