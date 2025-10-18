// INCLUDE GUARD
#ifndef PILHA_H
#define PILHA_H

// INTERFACE DA ESTRUTURA DE DADOS
#include <stdbool.h>

typedef struct pilha pilha;

/*
Informa a capacidade da pilha (número máximo de itens)
Entrada: pilha P
Saída: capacidade da pilha
*/
int p_capacidade(pilha *P);

/*
Informa se a pilha está cheia
Entrada: pilha P
Saída: true se pilha cheia; false c.c.
*/
bool p_cheia(pilha *P);

/*
Exibe o topo da pilha
Entrada: pilha P
Saída: Não tem
*/
int p_topo(pilha *P);

/*
Inicializa uma pilha e a retorna
Entrada: a capacidade da pilha
Saída: uma pilha inicializada
*/
pilha* p_inicializar(int capacidade);

/*
Insere um item na pilha
Entrada: pilha P e o item it
Saída: true se inseriu com sucesso; false c.c.
*/
bool p_inserir(pilha *P, int it);

/*
Libera a memória alocada para a pilha
Entrada: pilha P
Saída: retorna NULL caso tenha sido liberada
*/
pilha* p_liberar(pilha* L);

/*
Remove um item no fim da pilha
Entrada: pilha P
Saída: true se inseriu com sucesso; false c.c.
*/
bool p_remover(pilha *P);

/*
Informa o tamanho da pilha (número de itens na pilha)
Entrada: pilha P
Saída: tamanho da pilha
*/
int p_tamanho(pilha *P);

/*
Informa se a pilha está vazia
Entrada: pilha P
Saída: true se pilha vazia; false c.c.
*/
bool p_vazia(pilha *P);

#endif