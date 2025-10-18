/*
1) Inclua uma função na lista para retornar a quantidade de números pares presentes na lista
2) Faça um programa que gere 25 números aleatórios no intervalo [-25, 25]
3) Imprima os números na tela, separados por um espaço e em uma mesma linha
4) Inclua os números em uma lista
5) Exiba o conteúdo da lista
6) Use a função implementada no item 1) para informar a quantidade de números pares na lista
*/

#include <stdio.h>
#include "../includes/lista.h"
#include <stdlib.h>
#include <time.h>

void apresentacao(lista *L);

int main(){
    srand(time(NULL));
    lista *L = inicializar(10);
    apresentacao(L);

    for(int i = 1; i <= capacidade(L); i++){
        if(inserir_fim(L,-25 + rand()%25)){
            printf("Item %d inserido com sucesso\n", i);
        }
        else
            printf("Erro na inserçao do item %d\n", i);
        exibir(L);
        printf("\n");
    }
    apresentacao(L);
    L = liberar(L);


}

void apresentacao(lista *L) {
    printf("Capacidade de L: %d\n", capacidade(L));
    printf("Tamanho de L: %d\n", tamanho(L));

    if(vazia(L))
        printf("Lista L vazia\n");
    else
        printf("Lista L NAO vazia\n");

    if(cheia(L))
        printf("Lista L cheia\n");
    else
        printf("Lista L NAO cheia\n");
}