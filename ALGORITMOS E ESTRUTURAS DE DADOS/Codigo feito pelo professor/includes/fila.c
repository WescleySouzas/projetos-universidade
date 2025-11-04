// IMPLEMENTAÇÃO DA ESTRUTURA DE DADOS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "fila.h"

#define INVALIDO INT_MIN

struct fila {
    int *dados;
    int cap;
    int qtde;
};

int f_capacidade(fila *F) {
    if(F == NULL)
        return 0;

    return F->cap;
}

bool f_cheia(fila *F) {
    if(F == NULL || F->qtde == F->cap)
        return true;

    return false;
}

int f_frente(fila *F) {
    if(f_vazia(F))
        return INVALIDO;

    return F->dados[0];
}

fila* f_inicializar(int capacidade) {
    if(capacidade <= 0)
        return NULL;

    fila *F = (fila*) malloc(sizeof(fila));
    if(F == NULL)
        return NULL;

    F->dados = (int*) malloc(capacidade * sizeof(int));
    if(F->dados == NULL) {
        free(F);
        return NULL;
    }

    F->qtde = 0;
    F->cap = capacidade;

    return F;
}

bool f_inserir(fila *F, int it) {
    if(f_cheia(F))
        return false;
    
    F->dados[F->qtde] = it;
    F->qtde++;

    return true;
}

fila* f_liberar(fila* F) {
    if(F != NULL) {
        free(F->dados);
        free(F);
    }
    
    return NULL;
}

bool f_remover(fila *F) {
    if(f_vazia(F))
        return false;
    
    for(int i = 0; i < f_tamanho(F) - 1; i++)
        F->dados[i] = F->dados[i+1];
    F->qtde--;

    return true;
}

int f_tamanho(fila *F) {
    if(F == NULL)
        return 0;

    return F->qtde;
}

bool f_vazia(fila *F) {
    if(F == NULL || F->qtde == 0)
        return true;
    
    return false;
}