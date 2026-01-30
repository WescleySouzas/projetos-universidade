#include <stdio.h>
#include <stdlib.h>
#include "lista_s.h"

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

bool lista_inserir_fim(lista *l, item it) {
    if(l == NULL || lista_cheia(l))
        return false;
    
    l->dados[l->qtde] = it;
    l->qtde++;

    return true;
}
// a
bool lista_inserir_inicio(lista *l, item it) {
    if(l == NULL || lista_cheia(l))
        return false;

    for(int i = l->qtde; i> 0; i--){
        l->dados[i] = l->dados[i-1];
    }
    l->dados[0] = it;
    l->qtde++;
    return true;

}

bool lista_inserir_meio(lista *l, item it, int k) {
    if(lista_cheia(l) || k < 1 || k > l->qtde+1)
        return false;
    
    for(int i = l->qtde; i >= k; i--)
        l->dados[i] = l->dados[i-1];

    l->dados[k-1] = it;
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
// b
bool lista_remover_inicio(lista *l) {
    if(l == NULL || lista_vazia(l))
        return false;
        
    for(int i = 0; i<l->qtde - 1; i++){
        l->dados[i] = l->dados[i+1];
    }
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
// c
int lista_contar_impares(lista* l){
    if(l == NULL)
        return 0;
    
    int cont = 0;
    for(int i = 0; i < l->qtde; i++){
        if(l->dados[i] % 2 != 0){
            cont++;
        }
    }
    return  cont;
}

int lista_conta_consecutivos(lista* l ){
    if(l == NULL || l->qtde < 2)
        return 0;

    int cont = 0;
    for (int i = 0; i < l->qtde - 1; i++){
        if (l->dados[i+1] == l->dados[i] + 1){
            cont++;
        }
    }
    return cont;
}
