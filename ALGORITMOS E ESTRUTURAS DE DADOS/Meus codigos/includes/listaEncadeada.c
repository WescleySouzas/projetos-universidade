// INPLEMENTAÇÃO DA ESTRUTURA DA DADOS

#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

typedef struct {
    int conteudo;
    celula* prox;
}celula;

struct listae{
    celula * prim;
    int qtde;
};

static celula* criar_celula(int it){ 
    celula* nova = (celula*) malloc(sizeof(celula));
    if(nova != NULL){
        nova->conteudo = it;
        nova->prox = NULL;
    }
    return nova;
}

int le_busca(listae *L, int valor){
    return 0;
}

void le_exibir(listae *L) { 
    if(le_vazia(L)){
        return;
    }
    celula *temp = L->prim;
    while(temp != NULL){
        printf("")
    }
}