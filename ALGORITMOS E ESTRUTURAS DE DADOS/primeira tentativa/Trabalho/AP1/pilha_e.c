#include <stdio.h>
#include <stdlib.h>
#include "pilha_e.h"

typedef struct celula cel;

struct celula {
    item it;
    cel* prox;
};

struct pilha {
    cel* prim;
    int qtde;
};

static cel* criar_celula(item it) {
    cel* nova = (cel*) malloc(sizeof(cel));
    if(nova != NULL) {
        nova->it = it;
        nova->prox = NULL;
    }
    
    return nova;
}

void pilha_esvaziar(pilha *p) {
    if(p == NULL)
        return;

    while(!pilha_vazia(p))
        pilha_remover(p);
}

void pilha_finalizar(pilha *p) {
    if(p == NULL)
        return;

    pilha_esvaziar(p);
    free(p);
}

pilha* pilha_inicializar() {
    pilha* nova = (pilha*) malloc(sizeof(pilha));

    if(nova != NULL) {
        nova->prim = NULL;
        nova->qtde = 0;
    }

    return nova;
}

bool pilha_inserir(pilha *p, item it) {
    if(p == NULL)
        return false;
    
    cel* c = criar_celula(it);
    if(c == NULL)
        return false;

    c->prox = p->prim;
    p->prim = c;

    p->qtde++;

    return true;
}

bool pilha_remover(pilha *p) {
    if(pilha_vazia(p))
        return false;
    
    cel* temp = p->prim;
    p->prim = temp->prox;
    free(temp);

    p->qtde--;

    return true;
}

int pilha_tamanho(pilha *p) {
    if(p == NULL)
        return 0;

    return p->qtde;
}

item pilha_topo(pilha *p) {
    if(p == NULL) {
        printf("Pilha vazia!\n");
        return ERRO;
    }

    return p->prim->it;
}

bool pilha_vazia(pilha *p) {
    return p->qtde == 0;
}