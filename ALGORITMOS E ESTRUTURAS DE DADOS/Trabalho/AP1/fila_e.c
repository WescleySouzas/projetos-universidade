#include <stdio.h>
#include <stdlib.h>
#include "fila_e.h"

typedef struct celula cel;

struct celula {
    item it;
    cel* prox;
};

struct fila {
    cel* prim;  
    cel* ult;   
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

void fila_esvaziar(fila *f) {
    if(f == NULL)
        return;

    while(!fila_vazia(f))
        fila_remover(f);
}

void fila_finalizar(fila *f) {
    if(f == NULL)
        return;

    fila_esvaziar(f);
    free(f);
}

fila* fila_inicializar() {
    fila* nova = (fila*) malloc(sizeof(fila));

    if(nova != NULL) {
        nova->prim = NULL;
        nova->ult = NULL;
        nova->qtde = 0;
    }

    return nova;
}

bool fila_inserir(fila *f, item it) {
    if(f == NULL)
        return false;
    
    cel* c = criar_celula(it);
    if(c == NULL)
        return false;

    // Se a fila está vazia
    if(fila_vazia(f)) {
        f->prim = c;
        f->ult = c;
    } else {
        f->ult->prox = c;
        f->ult = c;
    }

    f->qtde++;

    return true;
}

bool fila_remover(fila *f) {
    if(fila_vazia(f))
        return false;
    
    cel* temp = f->prim;
    f->prim = temp->prox;
    
    // Se a fila ficou vazia após a remoção
    if(f->prim == NULL)
        f->ult = NULL;
    
    free(temp);
    f->qtde--;

    return true;
}

int fila_tamanho(fila *f) {
    if(f == NULL)
        return 0;

    return f->qtde;
}

item fila_frente(fila *f) {
    if(f == NULL || fila_vazia(f)) {
        printf("Fila vazia!\n");
        return ERRO;
    }

    return f->prim->it;
}

bool fila_vazia(fila *f) {
    if(f == NULL)
        return true;
    
    return f->qtde == 0;
}