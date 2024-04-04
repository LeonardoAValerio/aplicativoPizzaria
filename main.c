#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX_FLAVORS 4

typedef struct{
    int size;
    int flavors[SIZE_MAX_FLAVORS];
    float price;
}pizza;

int tamanhoPizza();
int* saboresPizza();
void pedidosPizza(pizza*, int);

int main(){
    int option, currentSize, sizeMaxArr = 0;
    int* arrFlavor;
    pizza* pizzaArr = malloc(sizeMaxArr * sizeof(pizza));
    do{
        system("cls");
        printf("Bem vindo a Pizzaria Galla!\n");
        printf("\t[2]-Novo Pedido\n");
        printf("\t[1]-Verificar/Confirmar Pedidos\n");
        printf("\t[0]-Sair\n");
        printf("Digite oque deseja fazer: ");
        scanf("%d",&option);
        switch (option)
        {
        case 2:
            sizeMaxArr++;
            currentSize = sizeMaxArr-1;
            pizzaArr = realloc(pizzaArr, sizeMaxArr * sizeof(pizza));
            printf("Vamos montar uma pizza!\n");
            pizzaArr[currentSize].size = tamanhoPizza();
            arrFlavor = saboresPizza();
            for(int k = 0; k<SIZE_MAX_FLAVORS; k++){
                pizzaArr[currentSize].flavors[k] = arrFlavor[k];
            }
            continue;
        
        case 1:
            pedidosPizza(pizzaArr, sizeMaxArr);
            continue;

        case 0:
            printf("Volte Sempre!\n");
            continue;
                    
        default:
            printf("Opcao invalida!\n");
            continue;
        }
    }while(option != 0);
    free(pizzaArr);
    return 0;
}

int tamanhoPizza(){
    int optionT = 1;
    do{
        printf("Escolha o tamanho da sua pizza!\n");
        printf("\t[1] - Pequeno \n");
        printf("\t[2] - Medio\n");
        printf("\t[3] - Grande\n");
        printf("\t[4] - Familia\n");
        printf("Digite o valor do tamanho da pizza: ");
        scanf("%d",&optionT);
        if(optionT < 0 || optionT > 4){
            printf("Opcao invalida!");
            optionT = 0;
        }
    }while (optionT == 0);
    return optionT;
}

int* saboresPizza(){
    int *flavorP = malloc(SIZE_MAX_FLAVORS * sizeof(int));
    int quan, check = 1;
    for(int i = 0; i<SIZE_MAX_FLAVORS; i++){
        flavorP[i] = 0;
    }
    do{
        printf("Informe quantos sabores deseja(1-4): ");
        scanf("%d",&quan);
        if(quan<1 || quan >4){
            printf("Opcao invalida!\n");
            check = 0;
            continue;
        }

        printf("CARDAPIO DE SABORES:\n");
        printf("\t[1] - Calabresa\n");
        printf("\t[2] - Frango com Catupiry\n");
        printf("\t[3] - Marguerita\n");
        printf("\t[4] - 4 Queijos\n");
        printf("\t[5] - Tomate Seco\n");
        printf("\t[6] - Moda da Casa\n");
        for(int i = 0; i<quan; i++){
            printf("Digite o valor do seu %d sabor: ",i+1);
            scanf("%d",&flavorP[i]);
        }
        check = 1;
    }while(check == 0);
    return flavorP;
}

void pedidosPizza(pizza* arr, int sizeArr){
    int optionP, k;
    do{
        printf("Seus pedidos sao:\n");
        for(k = 0; k<sizeArr; k++){
            printf("\t[Pizza %d]:\n",k+1);
            printf("\tTamanho: %d\n",arr[k].size);
            printf("\tSabores: \n");
            for(int i = 0; i<SIZE_MAX_FLAVORS; i++){
                int printFlavor = arr[k].flavors[i];
                if(printFlavor != 0){
                    printf("\t%d\n",printFlavor);
                }
            }  
        }
        if(k > 0){
            printf("\t[2] - Confirmar Pedido(s)\n");
            printf("\t[1] - Cancelar Pedido(s)\n");
        }
        printf("\t[0] - Voltar\n");
        scanf("%d",&optionP);
    }while(optionP);
}