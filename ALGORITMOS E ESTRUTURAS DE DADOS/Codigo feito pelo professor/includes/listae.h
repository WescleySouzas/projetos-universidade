// INCLUDE GUARD
#ifndef LISTA_H
#define LISTA_H

// INTERFACE DA ESTRUTURA DE DADOS
#include <stdbool.h>

typedef struct listae listae;

/*
Informa se o item 'valor' encontra-se na lista
Entrada: lista L
Saída: posicao na lista ou 0 caso não esteja na lista
*/
int le_busca(listae *L, int valor);

/*
Exibe o conteúdo da lista
Entrada: lista L
Saída: Não tem
*/
void le_exibir(listae *L);

/*
Inicializa uma lista e a retorna
Entrada: Não tem
Saída: uma lista inicializada
*/
listae* le_inicializar();

/*
Insere um item no fim da lista
Entrada: lista L e o item it
Saída: true se inseriu com sucesso; false c.c.
*/
bool le_inserir_fim(listae *L, int it);

/*
Insere um item no inicio da lista
Entrada: lista L e o item it
Saída: true se inseriu com sucesso; false c.c.
*/
bool le_inserir_inicio(listae *L, int it);

/*
Insere um item no meio da lista
Entrada: lista L, o item it e a posição (1 <= pos <= tamanho+1)
Saída: true se inseriu com sucesso; false c.c.
*/
bool le_inserir_meio(listae *L, int it, int pos);

/*
Libera a memória alocada para a lista
Entrada: lista L
Saída: retorna NULL caso tenha sido liberada
*/
listae* le_liberar(listae* L);

/*
Remove um item no fim da lista
Entrada: lista L
Saída: true se inseriu com sucesso; false c.c.
*/
bool le_remover_fim(listae *L);

/*
Remove um item no inicio da lista
Entrada: lista L
Saída: true se inseriu com sucesso; false c.c.
*/
bool le_remover_inicio(listae *L);

/*
Remove um item no meio da lista
Entrada: lista L e o item pos
Saída: true se inseriu com sucesso; false c.c.
*/
bool le_remover_meio(listae *L, int pos);

/*
Informa o tamanho da lista (número de itens na lista)
Entrada: lista L
Saída: tamanho da lista
*/
int le_tamanho(listae *L);

/*
Informa se a lista está vazia
Entrada: lista L
Saída: true se lista vazia; false c.c.
*/
bool le_vazia(listae *L);

#endif