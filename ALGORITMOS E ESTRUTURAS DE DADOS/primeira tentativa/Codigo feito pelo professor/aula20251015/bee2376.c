// https://resources.beecrowd.com/repository/UOJ_2376.html
#include <stdio.h>
#include "../includes/fila.h"

int main() {
    fila *times = f_inicializar(16);

    for(int i = 0; i < 16; i++)
        f_inserir(times, 'A'+i);

    char time1, time2;
    int gols1, gols2;
    
    for(int i = 1; i <= 15; i++) {
        time1 = (char) f_frente(times);
        f_remover(times);
        scanf("%d", &gols1);

        time2 = (char) f_frente(times);
        f_remover(times);
        scanf("%d", &gols2);

        if(gols1 > gols2)
            f_inserir(times, time1);
        else
            f_inserir(times, time2);
    }

    printf("%c\n", f_frente(times));

    f_liberar(times);

    return 0;
}