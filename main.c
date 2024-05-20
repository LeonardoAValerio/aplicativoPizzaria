#include <stdio.h>
#include <windows.h>
#include <string.h>

typedef struct{ //A estrutura da pizza, que tem Tamanho, sabores e preço
    char size;
    char flavors[4][20];
    float price;
}pizza;

//Todas as funções declaradas antes
void sizePricePizza(char**, float**);
void flavorsPizza(char*);

int main(){
    system("cls");
    int option, quan;
    printf("Bem vindo a Pizzaria Galla!\n");
    do{
        printf("\tMENU\n");
        printf("\t[1]-Novo Pedido\n");
        printf("\t[0]-Sair\n");
        printf("Digite oque deseja fazer: ");
        scanf("%d",&option);
        system("cls");
        switch (option){ //Verifica qual opção ele deseja
        case 1: //Quando ele deseja uma nova pizza
            printf("Informe quantas pizzas serao feitas no pedido: ");
            scanf("%d",&quan);
            if(quan>0){ //Quando a quantidade de pizzas é maior que 0
                pizza order[quan]; //cria as pizzas!
                for(int i = 0; i<quan; i++){
                    pizza* structOrder = &order[i]; //ponteiro que aponta a Struct atual
                    char* size = &structOrder->size; //ponteiro que aponta o "tamanho" da struct
                    float* price = &structOrder->price; //ponteiro que aponta o "preço" da struct
                    char* flavors = structOrder->flavors[0]; //ponteiro que aponta os "preço" da struct
                    //** guarda o endereço de memória de outro ponteiro
                    printf("Vamos montar sua pizza n %d\n",i+1);
                    sizePricePizza(&size, &price);//é enviado o endereçamento de memória do "tamanho" e do "preço" da struct
                    flavorsPizza(flavors);
                    for (int i = 0; i < 4; i++){
                        printf("%s\n",structOrder->flavors[i]);
                    }
                    
                }
            }else{ //Quando a quantidade de pizzas é menor que 0 volta para o menu!
                printf("Quantidade invalida!\nVoltando para o menu...\n");
            }
            break;

        case 0: //Quando ele deseja sair
            printf("Volte Sempre!\n");
            break;
                    
        default: //Quando ele digita um valor inválido
            printf("Opcao invalida!\n");
            break;
        }
    }while(option != 0);
    return 0;
}

void sizePricePizza(char** size, float** price){ //Descobre o tamanho e preço da pizza que o usuário quer
    int option; //opção do tamanhoPizza
    do{
        option = 1;
        printf("Escolha o tamanho da sua pizza!\n");
        printf("\t[1] - Pequeno - R$24.75\n");
        printf("\t[2] - Medio   - R$49.50\n");
        printf("\t[3] - Grande  - R$74.25\n");
        printf("\t[4] - Familia - R$99.00\n");
        printf("Digite o valor do tamanho da pizza: ");
        scanf("%d",&option); //verifica qual ele selecionou
        switch(option)
        {
        case 1:
            strcpy(*size, "Pequeno");
            **price = 24.75;
            break;
        
        case 2:
            strcpy(*size, "Medio");
            **price = 49.5;
            break;

        case 3:
            strcpy(*size, "Pequeno");
            **price = 74.25;
            break;

        case 4:
            strcpy(*size, "Pequeno");
            **price = 99;
            break;
        
        default:
            printf("Opcao inválida! insira novamente!\n");
            option = 0;
            break;
        }
    }while (option == 0);
    return;
}

//ERRO AQUI!
void flavorsPizza(char* flavors){
    //int quan, check, flavor;
    for(int i = 0; i<4; i++){
        strcpy(flavors + i * 20, "0");
    }
    return;
}