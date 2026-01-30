#include <stdio.h>
#include "../includes/listae.h"

void apresentacao(listae *L);

int main() {
    listae *L1 = le_inicializar();
    apresentacao(L1);
    for(int i = 1; i <= 20; i++) {
        if(le_inserir_fim(L1, i))
            printf("Item %d inserido com sucesso\n", i);
        else
            printf("Erro na insercao do item %d\n", i);
        le_exibir(L1);
        printf("\n");
    }

    while(!le_vazia(L1)) {
        if(le_remover_inicio(L1))
            printf("Item removido com sucesso\n");
        else
            printf("Erro na remocao\n");
        le_exibir(L1);
        printf("\n");
    }

    apresentacao(L1);
    L1 = le_liberar(L1);

    return 0;
}

void apresentacao(listae *L) {
    printf("Tamanho de L: %d\n", le_tamanho(L));

    if(le_vazia(L))
        printf("Lista L vazia\n");
    else
        printf("Lista L NAO vazia\n");
}