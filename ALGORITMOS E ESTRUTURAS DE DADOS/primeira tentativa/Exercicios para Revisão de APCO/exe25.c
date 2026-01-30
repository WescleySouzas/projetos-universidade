#include <stdio.h>

int conta(char *str){
    int count = 0;
    while(*str){
        if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u'){
            count++;
        }
        str++;
    }
    return count;
}

int main(){
    char texto[] = {"abacate"};

    printf("%d", conta(texto));

}