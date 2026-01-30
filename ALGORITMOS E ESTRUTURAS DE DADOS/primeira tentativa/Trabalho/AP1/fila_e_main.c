#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila_e.h"
#include "pilha_e.h"

// b1)
int qtde_pares(fila *f) {
    if(f == NULL || fila_vazia(f))
        return 0;
    
    int contador = 0;
    fila *fila_temp = fila_inicializar();
    
  
    while(!fila_vazia(f)) {
        item elemento = fila_frente(f);
        fila_inserir(fila_temp, elemento);
        fila_remover(f);
        
        if(elemento % 2 == 0) {
            contador++;
        }
    }
    
    while(!fila_vazia(fila_temp)) {
        item elemento = fila_frente(fila_temp);
        fila_inserir(f, elemento);
        fila_remover(fila_temp);
    }
    
    fila_finalizar(fila_temp);
    return contador;
}



int main() {
    srand(time(NULL));
    
    // b3) 
    fila *f = fila_inicializar();
    if(f == NULL) {
        printf("Erro ao criar a fila!\n");
        return 1;
    }
    
    printf("Números gerados: ");
    for(int i = 0; i < 25; i++) {
        int numero = rand() % 66 - 25; // Gera números de -25 a 40
        printf("%d ", numero);
        fila_inserir(f, numero);
    }
    printf("\n\n");
    
    // b4) C
    int pares = qtde_pares(f);
    printf("Quantidade de números pares na fila: %d\n\n", pares);
    

    

    fila_finalizar(f);
    
    return 0;
}