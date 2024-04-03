#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int* flavors;
    float price;
}pizza;

int tamanhoPizza();
int* saboresPizza();
void pedidosPizza(pizza*, int);

int main(){
    int option, j, i = 0;
    pizza* pizzaArr = malloc(i * sizeof(pizza));
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
            i++;
            j = i-1;
            pizzaArr = realloc(pizzaArr, i * sizeof(pizza));
            printf("Vamos montar uma pizza!\n");
            printf("%d",j);
            pizzaArr[j].size = tamanhoPizza();
            pizzaArr[j].flavors = saboresPizza();
            continue;
        
        case 1:
            pedidosPizza(pizzaArr, i);
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
        printf("\t[1] - Pequeno\n");
        printf("\t[2] - Medio\n");
        printf("\t[3] - Grande\n");
        printf("\t[4] - Familia\n");
        scanf("%d",&optionT);
        if(optionT < 0 || optionT > 4){
            printf("Opcao invalida!");
            optionT = 0;
        }
    }while (optionT == 0);
    return optionT;
}

int* saboresPizza(){
    int* flavorP[4];
    for(int i = 0; i>4; i++){
        flavorP[i] = 0;
    }
    return *flavorP;
}

void pedidosPizza(pizza* arr, int sizeArr){
    int optionP, k;
    do{
        printf("Seus pedidos sao:\n");
        for(k = 0; k<sizeArr; k++){
            printf("\t[Pizza %d]:\n",k+1);
            printf("\tTamanho: %d\n",arr[k].size);
        }
        if(k > 0){
            printf("\t[2] - Confirmar Pedido(s)\n");
            printf("\t[1] - Cancelar Pedido(s)\n");
        }
        printf("\t[0] - Voltar\n");
        scanf("%d",&optionP);
    }while(optionP);
}