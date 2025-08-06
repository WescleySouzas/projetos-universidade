#include <stdio.h>
#include <stdlib.h>


int main() {
  /*  int *b[5][5];

    for(int i=0; i < 5; i++){
        for(int j = 0; j < 5; j++){
         printf("%p\n", &b[i][j]);
    }
}
*/
    int a=10;
    int *p = NULL;
    p=&a;
    *p =5;

    printf("%d\t %d\t %p\n", a ,*p, p);

    return 0;
}