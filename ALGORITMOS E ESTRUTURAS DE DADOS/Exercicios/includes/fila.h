// INCLUDE GUARD
#ifndef FILA_H
#define FILA_H

// INTERFACE DA ESTRUTURA DE DADOS
#include <stdbool.h>

typedef struct fila fila;

/*
Informa a capacidade da fila (número máximo de itens)
Entrada: fila F
Saída: capacidade da fila
*/
int f_capacidade(fila *F);

/*
Informa se a fila está cheia
Entrada: fila F
Saída: true se fila cheia; false c.c.
*/
bool f_cheia(fila *F);

/*
Exibe a frente da fila
Entrada: fila F
Saída: item da frente da fila
*/
int f_frente(fila *F);

/*
Inicializa uma fila e a retorna
Entrada: a capacidade da fila
Saída: uma fila inicializada
*/
fila* f_inicializar(int capacidade);

/*
Insere um item na fila
Entrada: fila F e o item it
Saída: true se inseriu com sucesso; false c.c.
*/
bool f_inserir(fila *F, int it);

/*
Libera a memória alocada para a fila
Entrada: fila F
Saída: retorna NULL caso tenha sido liberada
*/
fila* f_liberar(fila *F);

/*
Remove um item no inicio da fila
Entrada: fila F
Saída: true se inseriu com sucesso; false c.c.
*/
bool f_remover(fila *F);

/*
Informa o tamanho da fila (número de itens na fila)
Entrada: fila F
Saída: tamanho da fila
*/
int f_tamanho(fila *F);

/*
Informa se a fila está vazia
Entrada: fila F
Saída: true se fila vazia; false c.c.
*/
bool f_vazia(fila *F);

#endif