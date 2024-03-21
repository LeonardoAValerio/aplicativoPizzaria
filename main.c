#include <stdio.h>

int tam;

int tamanhoPizza(){
    printf("Vamos escolher um tamanho para sua pizza!\n");
    printf("[1]-Pequeno\n");
    printf("[1]-Médio\n");
    printf("[3]-Grande\n");
    printf("[4]-Fámilia\n");
    printf("[5]-Fámilia\n");
    scanf("%i",&tam);

    return tam;
}

int main(){
    int option;
    printf("Bem vindo a pizzaria Pizzas\n Oque Desejas?\n");
    printf("[1]Pedir uma pizza\n");
    printf("[2]Sair\n");
    scanf("%i",&option);
    if(option == 1){
        tamanhoPizza();
    }else{
        return 0;
    }
    printf("%i",tam);
    return 0;
}