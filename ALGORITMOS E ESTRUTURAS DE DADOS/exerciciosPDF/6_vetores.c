#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int nota1, nota2, nota3;
    int total;
}aluno;

int media(aluno *a, int quantidade_alunos){
    int total_media = 0;

    for(int i = 0; i < 20; i++){
        a[i].total = a[i].nota1 + a[i].nota2 + a[i].nota3;
        total_media = a[i].nota1 + a[i].nota2 + a[i].nota3;
    }

    total_media = total_media / quantidade_alunos;

    return total_media;
}

int reprovados(aluno *a){
    for(int i = 0; i < 20; i++){
        if(a[i].total < 6){
            printf("Aluno %d esta REPROVADO! com a nota total de: %d\n", i + 1, a[i].total);
        }
    }
}

int aprovados(aluno *a){
     for(int i = 0; i < 20; i++){
        if(a[i].total >= 6){
            printf("Aluno %d esta APROVADO! com a nota total de: %d\n", i + 1, a[i].total);
        }
    }

}

int main(){
    srand(time(NULL));
    aluno a[20];

    for(int i=0; i < 20; i++){
        a[i].nota1 = rand()%5;
        a[i].nota2 = rand()%5; 
        a[i].nota3 = rand()%5; 
    }

    printf("A media da turma foi %d \n", media(a, 20));

    aprovados(a);
    reprovados(a);
    aprovados(a);

}