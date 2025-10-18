// IMPLEMENTAÇÃO DA ESTRUTURA DE DADOS
#include <stdio.h>
#include <stdlib.h>
#include "listae.h"

typedef struct celula celula;

struct listae {
    celula *prim;
    int qtde;
};

struct celula {
    int conteudo;
    celula* prox;
};

static celula* criar_celula(int it) {
    celula* nova = (celula*) malloc(sizeof(celula));
    if(nova != NULL) {
        nova->conteudo = it;
        nova->prox = NULL;
    }

    return nova;
}

int le_busca(listae *L, int valor) {
    /*if(!le_vazia(L))
        for(int i = 0; i < tamanho(L); i++)
            if(valor == L->dados[i])
                return i+1;        */

    return 0;   
}

void le_exibir(listae *L) {
    if(le_vazia(L))
        return;

    celula *temp = L->prim;
    while(temp != NULL) {
        printf("%d ", temp->conteudo);
        temp = temp->prox;
    }
}

listae* le_inicializar() {
    listae *L = (listae*) malloc(sizeof(listae));
    if(L == NULL)
        return NULL;

    L->prim = NULL;
    L->qtde = 0;

    return L;
}

bool le_inserir_fim(listae *L, int it) {
    if(L == NULL)
        return false;

    celula *nova = criar_celula(it);
    if(nova == NULL)
        return false;

    if(le_vazia(L)) {
        L->prim = nova;
    } else {
        celula *temp = L->prim;
        while(temp->prox != NULL)
            temp = temp->prox;
        temp->prox = nova;
    }
    L->qtde++;

    return true;
}

bool le_inserir_meio(listae *L, int it, int pos) {
    if(pos < 1 || pos > le_tamanho(L)+1)
        return false;
    
    /*for(int i = le_tamanho(L); i >= pos; i--)
        L->dados[i] = L->dados[i-1];
    L->dados[pos-1] = it;

    L->qtde++;*/

    return false;
}

bool le_inserir_inicio(listae *L, int it) {
    if(L == NULL)
        return false;
    
    celula *nova = criar_celula(it);
    if(nova == NULL)
        return false;

    nova->prox = L->prim;
    L->prim = nova;
    L->qtde++;

    return true;
}

listae* le_liberar(listae* L) {
    if(L != NULL) {
        while(!le_vazia(L))
            le_remover_inicio(L);
        free(L);
    }
    
    return NULL;
}

bool le_remover_fim(listae *L) {
    if(le_vazia(L))
        return false;
    
    //L->qtde--;

    return false;
}

bool le_remover_inicio(listae *L) {
    if(le_vazia(L))
        return false;
    
    celula * temp = L->prim;
    L->prim = temp->prox;
    free(temp);
    L->qtde--;

    return true;
}

bool le_remover_meio(listae *L, int pos) {
    if(le_vazia(L) || pos < 1 || pos > le_tamanho(L))
        return false;
    
    /*for(int i = pos-1; i < le_tamanho(L)-1; i++)
        L->dados[i] = L->dados[i+1];
    L->qtde--;*/

    return false;
}

int le_tamanho(listae *L) {
    if(L == NULL)
        return 0;

    return L->qtde;
}

bool le_vazia(listae *L) {
    if(L == NULL || L->qtde == 0)
        return true;
    
    return false;
}