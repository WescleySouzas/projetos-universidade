#ifndef LISTA_H      // INCLUDE GUARD
#define LISTA_H

#include <stdbool.h> // bool => {false, true}

#define ERRO -9999

// ----------- INTERFACE ----------
typedef int item;
typedef struct lista lista;

/*
Informa a capacidade da lista, ou seja, o número máximo
de itens que podem ser armazenado na estrutura
Entrada: referência para a lista l
Saída: a capacidade da lista
*/
int lista_capacidade(lista *l);

/*
Informa se uma lista está cheia ou não
Entrada: referência para a lista l
Saída: true se estiver cheia; false caso contrário
Restrição: Comportamento inesperado caso a referência não seja uma lista inicializada
*/
bool lista_cheia(lista *l);

/*
Esvazia uma lista
Entrada: referência para a lista l
Saída: Não tem
*/
void lista_esvaziar(lista *l);

/*
Exibir uma lista
Entrada: referência para a lista l
Saída: Não tem
*/
void lista_exibir(lista *l);

/*
Libera a memória da lista
Entrada: referência para a lista l
Saída: referência nula (NULL)
*/
lista* lista_finalizar(lista *l);

/*
Inicializa uma lista com a capacidade cap
Entrada: capacidade da lista
Saída: referência para a lista criada
*/
lista* lista_inicializar(int cap);

/*
Insere um item na lista
Entrada: referência para a lista l e o item it a ser inserido
Saída: true se inserido com sucesso; false caso contrário
*/
bool lista_inserir(lista *l, item it); // enqueue

/*
Retorna o item da k-ésima posição da lista
Entrada: referência para a lista l
Saída: item da frente
*/
item lista_obter(lista *l, int k);

/*
Remove um item do fim da lista
Entrada: referência para a lista l
Saída: true se removido com sucesso; false caso contrário
*/
bool lista_remover_fim(lista *l);

/*
Remove um item do início da lista
Entrada: referência para a lista l
Saída: true se removido com sucesso; false caso contrário
*/
bool lista_remover_inicio(lista *l);

/*
Remove um item da k-ésima posição da lista
Entrada: referência para a lista l
Saída: true se removido com sucesso; false caso contrário
*/
bool lista_remover_meio(lista *l, int k);

/*
Informa o tamanho da lista, ou seja, o número
de iten armazenados em um dado momento
Entrada: referência para a lista l
Saída: o tamanho da lista
*/
int lista_tamanho(lista *l);

/*
Informa se uma lista está vazia ou não
Entrada: referência para a lista l
Saída: true se estiver vazia; false caso contrário
*/
bool lista_vazia(lista *l);

int lista_qtde_min(lista *l);

int lista_qtde_min_dif(lista *l);

#endif // lista_H