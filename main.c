/*
-Bebidas
-Preço Pizza
-Nota fiscal/Pagamento(Gabriel)
*/

#include <stdio.h>
#include <windows.h>
#include <string.h>

#define SIZE_MAX_FLAVORS 4
#define PRICE_PIZZA 24.75
#define MAX_CHAR 100

typedef struct{
    int size;
    int flavors[SIZE_MAX_FLAVORS];
    float price;
}pizza;

typedef struct{
    char name[MAX_CHAR];
    char adress[MAX_CHAR];
    char number[MAX_CHAR];
}registerPizza;

int pedidosPizza(pizza*, int);
int tamanhoPizza();
int* saboresPizza();
registerPizza getRegister();
//void invoice(pizza*, int, registerPizza);

int main(){
    int option, pagamento, currentSize, sizeMaxArr = 0;
    int* arrFlavor;
    registerPizza registered;
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
            pizzaArr[currentSize].price = (float)pizzaArr[currentSize].size * PRICE_PIZZA;
            break;
        case 1:
            pagamento = pedidosPizza(pizzaArr, sizeMaxArr);
            switch (pagamento)
            {
            case 2:
                registered = getRegister();
                //notafiscal(pizzaArr, sizeMaxArr, registered);
                break;
            
            case 1:
                free(pizzaArr);
                currentSize = 0; 
                sizeMaxArr = 0;
                pizzaArr = malloc(sizeMaxArr * sizeof(pizza));
                break;

            default:
                break;
            }
            break;
        case 0:
            printf("Volte Sempre!\n");
            break;
                    
        default:
            printf("Opcao invalida!\n");
            break;
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
            printf("Opcao invalida!\n");
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
        printf("\t[3] - Portuguesa\n");
        printf("\t[4] - Marguerita\n");
        printf("\t[5] - Estrogonofe\n");
        printf("\t[6] - Quatro queijos\n");
        printf("\t[7] - Sensacao\n");
        printf("\t[8] - Romeu e julieta\n");
        for(int i = 0; i<quan; i++){
            while(flavorP[i]<1 || flavorP[i]>8){
            printf("Digite o valor do seu %d sabor: ",i+1);
                scanf("%d",&flavorP[i]);
                if(flavorP[i]<1 || flavorP[i]>8){
                    printf("Opcao invalida!\n");
                }
            }
        }
        check = 1;
    }while(check == 0);
    return flavorP;
}

int pedidosPizza(pizza* order, int numOrder){
    int confirm;
    do{
    printf("\nSeus pedidos sao:\n");
    for (int i = 0; i < numOrder; i++) {
        char size[10];
        printf("Pedido %d:\n", i + 1);
        switch (order[i].size){
        case 4:
            strcpy(size, "Familia");
            break;
        
        case 3:
            strcpy(size, "Grande");
            break;
        
        case 2:
            strcpy(size, "Medio");
            break;

        case 1:
            strcpy(size, "Pequeno");
            break;
        default:
            break;
        }
        printf("\tTamanho: %s\n", size);
        for(int k = 0; k<SIZE_MAX_FLAVORS; k++){
            char flavor[20];
            switch (order[i].flavors[k])
            {
            case 1:
                strcpy(flavor, "Calabresa");
                break;
            case 2:
                strcpy(flavor, "Frango com Catupiry");
                break;
            case 3:
                strcpy(flavor, "Portuguesa");
                break;
            case 4:
                strcpy(flavor, "Marguerita");
                break;
            case 5:
                strcpy(flavor, "Estrogonofe");
                break;
            case 6:
                strcpy(flavor, "Quatro queijos");
                break;
            case 7:
                strcpy(flavor, "Sensacao");
                break;
            case 8:
                strcpy(flavor, "Romeu e Julieta");
                break;
            default:
                break;
            }
            if(order[i].flavors[k] != 0){
                printf("\tSabor %d: %s\n", k+1,flavor);
            }
        }
        printf("\tPreco: R$%.2f\n", order[i].price);
    }
    printf("\n");
    if(numOrder > 0){
            printf("\t[2] - Confirmar Pedido(s)\n");
            printf("\t[1] - Cancelar Pedido(s)\n");
        }
        printf("\t[0] - Voltar\n");
    scanf("%d", &confirm);

    if(confirm == 2 && numOrder>0){
        return 2;
    }else if(confirm == 1 && numOrder>0){
        return 1;
    }else if(confirm == 0){
        return 0;
    }else{
        printf("Opcao invalida!\n");
    }

    }while (confirm != 0);
    return 0;
}

registerPizza getRegister(){
    registerPizza registration;
    fflush(stdin);
    printf("\tCadastro: \n");
    printf("Informe seu nome:\n");
    fgets(registration.name, MAX_CHAR, stdin);
    printf("Informe seu endereco:\n");
    fgets(registration.adress, MAX_CHAR, stdin);
    printf("Informe seu numero:\n");
    fgets(registration.number, MAX_CHAR, stdin);
    return registration;
}

/*void invoice(pizza* order, int numOrder, registerPizza registered){

}*/

/*
printf("Menu:\n");
        printf("1. Refrigerante 2L aleatorio - R$10.00\n");
        printf("2. Agua 500ml - R$3.00\n");
        printf("3. Fardo de 6 latas de cerveja 473ml- R$36.00\n");
        printf("4. Energetico 2L- R$14.00\n");
*/
