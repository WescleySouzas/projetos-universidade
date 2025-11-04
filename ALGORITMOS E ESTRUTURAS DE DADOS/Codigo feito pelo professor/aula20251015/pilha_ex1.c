#include <stdio.h>
#include "../includes/pilha.h"

void apresentacao(pilha *P);

int main() {
    pilha *p1 = inicializar(10);
    apresentacao(p1);
    for(int i = 1; i <= capacidade(p1); i++) {
        if(inserir(p1, i))
            printf("Item %d inserido com sucesso\n", i);
        else
            printf("Erro na insercao do item %d\n", i);
        printf("Topo da pilha: %d", topo(p1));
        printf("\n");
    }

    printf("\n");
    while(!vazia(p1)) {
        printf("%d ", topo(p1));
        remover(p1);
    }

    apresentacao(p1);
    p1 = liberar(p1);

    return 0;
}

void apresentacao(pilha *P) {
    printf("Capacidade de P: %d\n", capacidade(P));
    printf("Tamanho de P: %d\n", tamanho(P));

    if(vazia(P))
        printf("Pilha P vazia\n");
    else
        printf("Pilha P NAO vazia\n");

    if(cheia(P))
        printf("Pilha P cheia\n");
    else
        printf("Pilha P NAO cheia\n");
}