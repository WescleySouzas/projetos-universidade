#include <stdio.h>

int main(){

int a = 5, b = 2;

int resultado = a / b;

if(resultado > 3){
    printf("%d\n",resultado);
}
else{
    printf("hahaha\n");
}
int conte = 1;
while(conte < 5){
for(int i=0; i<10; i++){
    
    printf("%d\n", conte);
    conte++;
}
}

soma(5, 5);
return 0;

}

void soma(int a, int b){
    printf("Resultado: %d", a + b);
}
