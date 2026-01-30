#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

// ----------- INTERFACE ----------
typedef int item;
typedef struct fila fila;

#define ERRO -9999

/*
Esvazia uma fila
Entrada: referência para a fila f
Saída: Não tem
*/
void fila_esvaziar(fila *f);

/*
Libera a memória da fila
Entrada: referência para a fila f
Saída: Não tem
*/
void fila_finalizar(fila *f);

/*
Cria uma fila
Entrada: Não tem
Saída: referência para a fila criada
*/
fila* fila_inicializar();

/*
Insere um item na fila (no final)
Entrada: referência para a fila f e o item it a ser inserido
Saída: true se inserido com sucesso; false caso contrário
*/
bool fila_inserir(fila *f, item it);

/*
Remove um item da fila (do início)
Entrada: referência para a fila f
Saída: true se removido com sucesso; false caso contrário
*/
bool fila_remover(fila *f);

/*
Informa o tamanho da fila, ou seja, o número
de itens armazenados em um dado momento
Entrada: referência para a fila f
Saída: o tamanho da fila
*/
int fila_tamanho(fila *f);

/*
Retorna o item da frente da fila
Entrada: referência para a fila f
Saída: item da frente ou comportamento inesperado caso fila vazia
*/
item fila_frente(fila *f);

/*
Informa se uma fila está vazia ou não
Entrada: referência para a fila f
Saída: true se estiver vazia; false caso contrário
*/
bool fila_vazia(fila *f);

#endif // FILA_H