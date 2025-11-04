// INCLUDE GUARD
#ifndef LISTA_H
#define LISTA_H

// INTERFACE DA ESTRUTURA DE DADOS
#include <stdbool.h>

typedef struct lista lista;

/*
Informa se o item 'valor' encontra-se na lista
Entrada: lista L
Saída: posicao na lista ou 0 caso não esteja na lista
*/
int busca(lista *L, int valor);

/*
Informa a capacidade da lista (número máximo de itens)
Entrada: lista L
Saída: capacidade da lista
*/
int capacidade(lista *L);

/*
Informa se a lista está cheia
Entrada: lista L
Saída: true se lista cheia; false c.c.
*/
bool cheia(lista *L);

/*
Exibe o conteúdo da lista
Entrada: lista L
Saída: Não tem
*/
void exibir(lista *L);

/*
Inicializa uma lista e a retorna
Entrada: a capacidade da lista
Saída: uma lista inicializada
*/
lista* inicializar(int capacidade);

/*
Insere um item no fim da lista
Entrada: lista L e o item it
Saída: true se inseriu com sucesso; false c.c.
*/
bool inserir_fim(lista *L, int it);

/*
Insere um item no inicio da lista
Entrada: lista L e o item it
Saída: true se inseriu com sucesso; false c.c.
*/
bool inserir_inicio(lista *L, int it);

/*
Insere um item no meio da lista
Entrada: lista L, o item it e a posição (1 <= pos <= tamanho+1)
Saída: true se inseriu com sucesso; false c.c.
*/
bool inserir_meio(lista *L, int it, int pos);

/*
Libera a memória alocada para a lista
Entrada: lista L
Saída: retorna NULL caso tenha sido liberada
*/
lista* liberar(lista* L);

/*
Remove um item no fim da lista
Entrada: lista L
Saída: true se inseriu com sucesso; false c.c.
*/
bool remover_fim(lista *L);

/*
Remove um item no inicio da lista
Entrada: lista L
Saída: true se inseriu com sucesso; false c.c.
*/
bool remover_inicio(lista *L);

/*
Remove um item no meio da lista
Entrada: lista L e o item pos
Saída: true se inseriu com sucesso; false c.c.
*/
bool remover_meio(lista *L, int pos);

/*
Informa o tamanho da lista (número de itens na lista)
Entrada: lista L
Saída: tamanho da lista
*/
int tamanho(lista *L);

/*
Informa se a lista está vazia
Entrada: lista L
Saída: true se lista vazia; false c.c.
*/
bool vazia(lista *L);

#endif