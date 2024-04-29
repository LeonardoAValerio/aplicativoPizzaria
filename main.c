//Imagine como se fosse um pedido no Mc'Donalds
//Pedido - Fazer um pedido de cada vez, considerando que um Pedido pode ter infinitas pizzas!
//Fazer o retorno dos sabores, tamanhos, em files! que servirá pra não precisar converter!
//Cadastro - Guardar em Files, e poder verificar se ele cadastrou certo!
//Selecionar a porção da pizza que o sabor irá ter!
//Nota fiscal, !!FUNCIONAL!!
//Adicionais/Montar sua pizza
//Registro de quantos pedidos ele já fez em todo o aplicativo! (opcional)

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define maxFlavors 4

typedef struct{
    char size[100];
    int flavors[maxFlavors];
    float price;
}pizza;

int main(){
    int option, quan = 0;
    //Menu Inicial
    do{
    system("cls");
    printf("Bem-vindo a Pizzaria Galla!\n");
    printf("\t[1] - Pedir uma pizza\n");
    printf("\t[0] - Sair\n");
    printf("Informe oque deseja fazer: ");
    scanf("%d",&option);
    switch (option){
    case 1:
        //Pedir a pizza
        do{ //Quantas pizzas
            printf("Informe quantas pizzas o senhor deseja: \n");
            scanf("%d",&quan); //Cria o array de struct das pizzas
        }while(quan>0);
        pizza arrayPizzas[quan];
        

        for(int i = 0; i<quan; i++){ //Loop para preencher todas as pizzas
            //Tamanho
            arrayPizzas[i].price = 2;
            //Sabores
        }
        break;
    
    case 0:
        //Sair
        printf("Volte sempre!");
        break;

    default:
        //Opcao invalida
        break;
    }
    }while(option != 0);
    return 0;
}

