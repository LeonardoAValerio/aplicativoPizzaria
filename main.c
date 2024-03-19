#include <stdio.h>

int main(){
    int option;
    printf("Bem vindo a pizzaria Pizzas\n Oque Desejas?\n");
    printf("[1]Pedir uma pizza\n");
    printf("[2]Sair\n");
    scanf("%i",&option);
    if(option == 1){
        printf("Vamos escolher o tamanho da pizza!");
    }else{
        return 0;
    }
    return 0;
}