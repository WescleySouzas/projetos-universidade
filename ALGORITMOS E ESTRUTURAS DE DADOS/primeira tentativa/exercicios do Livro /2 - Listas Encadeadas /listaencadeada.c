// IMPLEMENTAÇÃO DA ESTRUTURA DE DADOS
#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"


struct lista{
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* lst_cria(void){
    return NULL;
}

Lista* lst_insere_inicio(Lista* L, int it){
    Lista * novo = (Lista*) malloc(sizeof(Lista));
    novo->info = it;
    novo->prox = L;
    return novo;
}

Lista* lst_insere_ordenado(Lista* L, int v){
    Lista* novo;
    Lista* ant = NULL;
    Lista* P = L;

    while(P != NULL && P->info < v){
        ant = P;
        P = P->prox;
    }

    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;

    if(ant == NULL){
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return L;
}

void lst_imprime(Lista* L){
    Lista* p;
    for(p = L; p != NULL; p = p->prox)
        printf("Info = %d\n", p->info);
}

/*void lst_inprime_recursiva(Lista* L){
    if(lst_vazia(L))
        return;
    else{
        printf("info: %d\n", L->info);
        lst_inprime_recursiva(L->prox);
    }
}
*/

int lst_vazia(Lista* L){
    if(L == NULL)
        return 1;
    else
        return 0;
}

Lista* lst_busca(Lista* L, int v){
    Lista* p;
    for(p = L; p != NULL; p = p->prox){
        if (p->info == v)
            return p;
    }      
    return NULL;

}

Lista* lst_retira(Lista* L, int v){
    Lista* ant = NULL;
    Lista* p = L;

    while(p != NULL && p->info != v){
        ant = p;
        p = p->prox;
    }
    if(p == NULL)
        return L;
    
    if(ant == NULL)
        L = p->prox;
    
    else
        ant->prox = p->prox;
    free(p);
    return L;

}

void lst_libera(Lista* L){
    Lista* p = L;
    
    while(p != NULL){
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}

void lcirc_imprime(Lista* L){
    Lista* P = L; 
    if(P) do {
        printf("%d\n", P->info);
            P = P->prox;
    } while(P != L);
}









