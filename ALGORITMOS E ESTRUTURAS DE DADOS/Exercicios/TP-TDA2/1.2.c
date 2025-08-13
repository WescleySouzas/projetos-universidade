#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int tamanho;
} Lista;

int inserir(Lista *l, int valor, int pos){
    if(l->tamanho >= MAX){
        return 0;
    }
    if(pos < 0){
        pos = 0;
    }
    if(pos > l->tamanho){
        pos = l->tamanho;
    }
    for(int i = l->tamanho; i > pos; i--){
        l->dados[i] = l->dados[i - 1];
    }
    l->dados[pos] = valor;
    l->tamanho++;
    return 1;
}

int buscar(Lista *l, int valor){
    for (int i = 0; i < l->tamanho; i++){
        if(l->dados[i] == valor){
            return i; 
        }
    }
    return -1;
}

int remover(Lista *l, int valor){
    int pos = buscar(l, valor);
    if(pos == -1){return 0;}
    for(int i = pos; i < l->tamanho - 1; i++){
        l->dados[i] = l->dados[i +1];
    }
    l->tamanho--;
    return 1;
}

void imprimir(Lista *l) {
    for(int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}

typedef struct No {
    int valor;
    struct No *prox;
} No;

void inserirApos(No *p, int y, int x) {
    while (p != NULL) {
        if (p->valor == y) {
            No *novo = malloc(sizeof(No));
            novo->valor = x;
            novo->prox = p->prox;
            p->prox = novo;
            return;
        }
        p = p->prox;
    }
}

int main() {
    Lista l;
    l.tamanho = 0;

    for(int j=0; j < 10; j++){
        inserir(&l, rand()%50, j);
    }

    printf("Lista depois das inserções: ");
    imprimir(&l);

    int valor = 42;
    int pos = buscar(&l, valor);
    if(pos != -1)
        printf("Valor %d encontrado na posição %d\n", valor, pos);
    else
        printf("Valor %d não encontrado\n", valor);


    remover(&l, 36);
    printf("Lista depois de remover 30: ");
    imprimir(&l);

    return 0;
}