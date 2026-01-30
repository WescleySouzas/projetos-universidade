#include <stdio.h>
#include <stdlib.h>
#include "lista_so.h"

struct lista {
    item *dados;
    int qtde, cap;
};

int lista_capacidade(lista *l) {
    if(l == NULL)
        return 0;

    return l->cap;
}

bool lista_cheia(lista *l) {
    return l->qtde == l->cap;
}

void lista_esvaziar(lista *l) {
    if(l == NULL)
        return;

    l->qtde = 0;
}

void lista_exibir(lista *l) {
    for(int i = 0; i < l->qtde; i++)
        printf("%d ", l->dados[i]);
}

lista* lista_finalizar(lista *l) {
    if(l == NULL)
        return l;

    free(l->dados);
    l->dados = NULL;
    printf("fila finalizada!");
    free(l);
    
    return NULL;
}

lista* lista_inicializar(int cap) {
    lista *nova = (lista*) calloc(1, sizeof(lista));
    if(nova != NULL) {
        nova->qtde = 0;
        nova->cap = cap;
        nova->dados = (item*) calloc(cap, sizeof(item));
        if(nova->dados == NULL) {
            free(nova);
            nova = NULL;
        }
    }

    return nova;
}

bool lista_inserir(lista *l, item it) {
    if(l == NULL || lista_cheia(l))
        return false;
    
    int aux = l->qtde;
    while(aux > 0 && l->dados[aux-1] > it) {
        l->dados[aux] = l->dados[aux-1];
        aux--;
    }
    l->dados[aux] = it;
    l->qtde++;

    return true;
}

item lista_obter(lista *l, int k) {
    if(k < 1 || k > l->qtde)
        return ERRO;

    return l->dados[k-1];
}

bool lista_remover_fim(lista *l) {
    if(lista_vazia(l))
        return false;
    
    l->qtde--;

    return true;
}

bool lista_remover_meio(lista *l, int k) {
    if(lista_vazia(l) || k < 1 || k > l->qtde)
        return false;
    
    for(int i = k-1; i < l->qtde - 1; i++)
        l->dados[i] = l->dados[i+1];
    l->qtde--;

    return false;
}

int lista_tamanho(lista *l) {
    if(l == NULL)
        return 0;

    return l->qtde;
}

bool lista_vazia(lista *l) {
    if(l == NULL)
        return 0;

    return l->qtde == 0;
}

// a) 
int lista_qtde_min(lista *l) {
    if(l == NULL)
        return 0;
    
    int contador = 0;
    for(int i = 0; i < l->qtde; i++) {
        if(l->dados[i] >= 'a' && l->dados[i] <= 'z') {
            contador++;
        }
    }
    
    return contador;
}

