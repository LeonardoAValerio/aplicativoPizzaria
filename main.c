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
    int flavor, quan;
    printf("Bem vindo a Pizzaria Galla!\n");
    do{
        printf("\tMENU\n");
        printf("\t[1]-Novo Pedido\n");
        printf("\t[0]-Sair\n");
        printf("Digite oque deseja fazer: ");
        scanf("%d",&flavor);
        system("cls");
        switch (flavor){ //Verifica qual opção ele deseja
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
    }while(flavor != 0);
    return 0;
}

void sizePricePizza(char** size, float** price){ //Descobre o tamanho e preço da pizza que o usuário quer
    int flavor; //opção do tamanhoPizza
    do{
        flavor = 1;
        printf("Escolha o tamanho da sua pizza!\n");
        printf("\t[1] - Pequeno - R$24.75\n");
        printf("\t[2] - Medio   - R$49.50\n");
        printf("\t[3] - Grande  - R$74.25\n");
        printf("\t[4] - Familia - R$99.00\n");
        printf("Digite o valor do tamanho da pizza: ");
        scanf("%d",&flavor); //verifica qual ele selecionou
        switch(flavor)
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
            flavor = 0;
            break;
        }
    }while (flavor == 0);
    return;
}

//ERRO AQUI!
void flavorsPizza(char* flavors){
    int quan, check, flavor;
    for(int i = 0; i<4; i++){
        strcpy(flavors + i * 20, "0");
    }
    do{
        check = 1;
        printf("Informe quantos sabores deseja(1-4): ");
        scanf("%d",&quan); //verifica quantos sabores o usuário deseja
        if(quan<1 || quan >4){ //checka se ele seleciona a quantidade entre 1-4, e se não ele fala pra ele repitir
            printf("Opcao invalida!\n");
            check = 0; 
            continue; //pula o código e volta pra seleção de sabores
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
            printf("Digite o valor do seu %d sabor: ",i+1);
                scanf("%d",&flavor);
                switch (flavor)
                {
                case 1:
                    strcpy(flavors + i * 20, "Calabresa");
                    break;

                case 2:
                    strcpy(flavors + i * 20, "Frango com Catupiry");
                    break;

                case 3:
                    strcpy(flavors + i * 20, "Portuguesa");
                    break;

                case 4:
                    strcpy(flavors + i * 20, "Marguerita");
                    break;

                case 5:
                    strcpy(flavors + i * 20, "Estrogonofe");
                    break;

                case 6:
                    strcpy(flavors + i * 20, "Quatro queijos");
                    break;

                case 7:
                    strcpy(flavors + i * 20, "Sensacao");
                    break;
                
                case 8:
                    strcpy(flavors + i * 20, "Romeu e julieta");
                    break;
                
                default:
                    printf("Opção invalida! tente novamente!\n");
                    check = 0;
                    break;
                }
        }
         //faz o loop acabar
    }while(check == 0);
    return;
}