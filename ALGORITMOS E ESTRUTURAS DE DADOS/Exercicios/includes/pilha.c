// IMPLEMENTAÇÃO DA ESTRUTURA DE DADOS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pilha.h"

#define INVALIDO INT_MIN

struct pilha {
    int *dados;
    int cap;
    int qtde;
};

int p_capacidade(pilha *P) {
    if(P == NULL)
        return 0;

    return P->cap;
}

bool p_cheia(pilha *P) {
    if(P == NULL || P->qtde == P->cap)
        return true;

    return false;
}

int p_topo(pilha *P) {
    if(p_vazia(P))
        return INVALIDO;

    return P->dados[P->qtde-1];
}

pilha* p_inicializar(int capacidade) {
    if(p_capacidade <= 0)
        return NULL;

    pilha *P = (pilha*) malloc(sizeof(pilha));
    if(P == NULL)
        return NULL;

    P->dados = (int*) malloc(capacidade * sizeof(int));
    if(P->dados == NULL) {
        free(P);
        return NULL;
    }

    P->qtde = 0;
    P->cap = capacidade;

    return P;
}

bool p_inserir(pilha *P, int it) {
    if(p_cheia(P))
        return false;
    
    P->dados[P->qtde] = it;
    P->qtde++;

    return true;
}

pilha* p_liberar(pilha* P) {
    if(P != NULL) {
        free(P->dados);
        free(P);
    }
    
    return NULL;
}

bool p_remover(pilha *P) {
    if(p_vazia(P))
        return false;
    
    P->qtde--;

    return true;
}

int p_tamanho(pilha *P) {
    if(P == NULL)
        return 0;

    return P->qtde;
}

bool p_vazia(pilha *P) {
    if(P == NULL || P->qtde == 0)
        return true;
    
    return false;
}