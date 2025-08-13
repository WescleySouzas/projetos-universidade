#include <stdio.h>
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
            return 1;
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

int main() {
    Lista l;
    l.tamanho = 0;

    inserir(&l, 10, 0);
    inserir(&l, 20, 1);
    inserir(&l, 30, 2);
    inserir(&l, 15, 1);

    printf("Lista depois das inserções: ");
    imprimir(&l);

    int valor = 20;
    int pos = buscar(&l, valor);
    if(pos != -1)
        printf("Valor %d encontrado na posição %d\n", valor, pos);
    else
        printf("Valor %d não encontrado\n", valor);

    remover(&l, 15);
    printf("Lista depois de remover 15: ");
    imprimir(&l);

    remover(&l, 30);
    printf("Lista depois de remover 30: ");
    imprimir(&l);

    return 0;
}