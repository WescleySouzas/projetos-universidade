#include <stdio.h>
#include "../includes/fila.h"
#include "../includes/pilha.h"

void apresentacao_p(pilha *P);
void apresentacao_f(fila *F);

int main() {
    fila *f1 = f_inicializar(10);
        
    apresentacao_f(f1);
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

    apresentacao_f(f1);
    f1 = f_liberar(f1);

    pilha *p1 = p_inicializar(20);
    apresentacao_p(p1);
    for(int i = 1; i <= p_capacidade(p1); i++) {
        if(p_inserir(p1, i))
            printf("Item %d inserido com sucesso\n", i);
        else
            printf("Erro na insercao do item %d\n", i);
        printf("Topo da pilha: %d", p_topo(p1));
        printf("\n");
    }

    printf("\n");
    while(!p_vazia(p1)) {
        printf("%d ", p_topo(p1));
        p_remover(p1);
    }

    apresentacao_p(p1);
    p1 = p_liberar(p1);

    return 0;
}

void apresentacao_p(pilha *P) {
    printf("Capacidade de P: %d\n", p_capacidade(P));
    printf("Tamanho de P: %d\n", p_tamanho(P));

    if(p_vazia(P))
        printf("Pilha P vazia\n");
    else
        printf("Pilha P NAO vazia\n");

    if(p_cheia(P))
        printf("Pilha P cheia\n");
    else
        printf("Pilha P NAO cheia\n");
}

void apresentacao_f(fila *F) {
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