#include <stdio.h>
#include "../includes/fila.h"

void apresentacao(fila *F);

int main() {
    fila *f1 = f_inicializar(10);
    apresentacao(f1);
    for(int i = 1; i <= f_capacidade(f1); i++) {
        if(f_inserir(f1, i))
            printf("Item %d inserido com sucesso\n", i);
        else
            printf("Erro na insercao do item %d\n", i);
        printf("Frente da fila: %d", f_frente(f1));
        printf("\n");
    }

    printf("\n");
    while(!f_vazia(f1)) {
        printf("%d ", f_frente(f1));
        f_remover(f1);
    }

    apresentacao(f1);
    f1 = f_liberar(f1);

    return 0;
}

void apresentacao(fila *F) {
    printf("Capacidade de F: %d\n", f_capacidade(F));
    printf("Tamanho de F: %d\n", f_tamanho(F));

    if(f_vazia(F))
        printf("Fila F vazia\n");
    else
        printf("Fila F NAO vazia\n");

    if(f_cheia(F))
        printf("Fila F cheia\n");
    else
        printf("Fila F NAO cheia\n");
}