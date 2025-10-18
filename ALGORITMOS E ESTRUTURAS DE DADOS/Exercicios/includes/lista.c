// IMPLEMENTAÇÃO DA ESTRUTURA DE DADOS
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
    int *dados;
    int cap;
    int qtde;
};

int busca(lista *L, int valor) {
    if(!vazia(L))
        for(int i = 0; i < tamanho(L); i++)
            if(valor == L->dados[i])
                return i+1;        

    return 0;   
}

int capacidade(lista *L) {
    if(L == NULL)
        return 0;

    return L->cap;
}

bool cheia(lista *L) {
    if(L == NULL || L->qtde == L->cap)
        return true;

    return false;
}

void exibir(lista *L) {
    if(vazia(L))
        return;

    for(int i = 0; i < L->qtde; i++)
        printf("%d ", L->dados[i]);
}

lista* inicializar(int capacidade) {
    if(capacidade <= 0)
        return NULL;

    lista *L = (lista*) malloc(sizeof(lista));
    if(L == NULL)
        return NULL;

    L->dados = (int*) malloc(capacidade * sizeof(int));
    if(L->dados == NULL) {
        free(L);
        return NULL;
    }

    L->qtde = 0;
    L->cap = capacidade;

    return L;
}

bool inserir_fim(lista *L, int it) {
    if(cheia(L))
        return false;
    
    L->dados[L->qtde] = it;
    L->qtde++;

    return true;
}

bool inserir_meio(lista *L, int it, int pos) {
    if(cheia(L) || pos < 1 || pos > tamanho(L)+1)
        return false;
    
    for(int i = tamanho(L); i >= pos; i--)
        L->dados[i] = L->dados[i-1];
    L->dados[pos-1] = it;

    L->qtde++;

    return true;
}

bool inserir_inicio(lista *L, int it) {
    if(cheia(L))
        return false;
    
    for(int i = tamanho(L); i > 0; i--)
        L->dados[i] = L->dados[i-1];
    L->dados[0] = it;
    L->qtde++;

    return true;
}

lista* liberar(lista* L) {
    if(L != NULL) {
        free(L->dados);
        free(L);
    }
    
    return NULL;
}

int pares(lista *L){
    int cont = 0;
    
    for(int i = 0; i < tamanho(L); i++){
        if(L->dados[i] % 2 == 0)
            cont++;
    }
    return cont;
}

bool remover_fim(lista *L) {
    if(vazia(L))
        return false;
    
    L->qtde--;

    return true;
}

bool remover_inicio(lista *L) {
    if(vazia(L))
        return false;
    
    for(int i = 0; i < tamanho(L) - 1; i++)
        L->dados[i] = L->dados[i+1];
    L->qtde--;

    return true;
}

bool remover_meio(lista *L, int pos) {
    if(vazia(L) || pos < 1 || pos > tamanho(L))
        return false;
    
    for(int i = pos-1; i < tamanho(L)-1; i++)
        L->dados[i] = L->dados[i+1];
    L->qtde--;

    return true;
}

int tamanho(lista *L) {
    if(L == NULL)
        return 0;

    return L->qtde;
}

bool vazia(lista *L) {
    if(L == NULL || L->qtde == 0)
        return true;
    
    return false;
}