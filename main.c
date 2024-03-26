#include <stdio.h>
#include <stdlib.h>

#define ARR_SAB 4

int tamanhoPizza();
int* saboresPizza();

int main(){ //O Menu inicial 
    int option;
    int* arr;
    printf("Bem vindo a pizzaria Pizzas\n Oque Desejas?\n");
    printf("[1]Pedir uma pizza\n");
    printf("[2]Sair\n");
    scanf("%i",&option);
    if(option == 1){
        tamanhoPizza();
        arr = saboresPizza();
        
    }else{
        return 0;
    }
    for(int i=0; i<4; i++){
        printf("%i\n",arr[i]);
    }
return 0;
}

int tamanhoPizza(){ //Definindo o tamanho da pizza
    int tam;
    printf("Vamos escolher um tamanho para sua pizza!\n");
    printf("[1]-Pequeno\n");
    printf("[2]-Medio\n");
    printf("[3]-Grande\n");
    printf("[4]-Familia\n");
    scanf("%i",&tam);
    return tam;
}

int* saboresPizza(){ //Definindo os sabores da pizza
    int *sab = malloc(ARR_SAB*sizeof(int));
    int quan;
    printf("Quantos sabores voce ira querer [1-4]:\n");
    scanf("%i",&quan);
    for(int i=0; i<quan; i++){
        printf("Escolha seu sabor numero %i:\n",i+1);
        printf("[1]Calabresa\n");
        printf("[2]Frango com catupiry\n");
        printf("[3]Marguerita\n");
        printf("[4]Baiana\n");
        scanf("%d",&sab[i]);
    }
    return sab;
}