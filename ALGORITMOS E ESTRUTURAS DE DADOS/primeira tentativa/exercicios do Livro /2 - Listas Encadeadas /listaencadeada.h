#ifndef LISTA_H
#define LISTA_H

typedef struct lista Lista;

/* Funçao de criação: rertona uma lista NULL*/
Lista* lst_cria();

/* Inserção no inicio: retorna a lista atualixada*/
Lista* lst_insere_inicio(Lista* L, int it);

/*
Funçao insere_ordenado: insere elemento em ordem ou no meio da fila
*/
Lista* lst_insere_ordenado(Lista* L, int v);

/*
Função que inprime : Imprime valores dos elementos
*/
void lst_imprime(Lista* L);


/*
Função Vazia: retorna 1 se vazria ou 0 se nao vazia 
*/
int lst_vazia(Lista* L);

/*
Função busca: busca um elemento na lista
*/
Lista* lst_busca(Lista* L, int v);

/*
Função retira: retira elemento da lista
*/
Lista* lst_retira(Lista* L, int v);


/*
Função libera: libera a lista
*/
void lst_libera(Lista* L);

void lcirc_imprime(Lista* L);

#endif