#include <stdio.h>
#include <windows.h>
#include <string.h>

typedef struct{ //A estrutura da pizza, que tem Tamanho, sabores e preço
    char tamanho[20];
    char sabores[4][20];
    float preco;
}pizza;

//Todas as funções declaradas antes
void menu();
void criaPedidos(pizza* pedido, int quanPizzas);
void tamanhoPrecoPizza(char**, float**);
void saboresPizza(char*);

#include <stdio.h>
#include <stdlib.h>

int main() {
    int continuar = 1;
    int pizzas;
    int confirm;
    do{
        menu();
        scanf("%d", &continuar);
        system("cls || clear");
        switch (continuar) {
            case 1: //Deseja pedir
                do{
                    printf("Vamos aos pedidos!\n");
                    printf("Escolha a quantidade de pizzas: \n");
                    scanf("%d", &pizzas);
                    if(pizzas<1){
                        printf("Escolha um valor valido\n");
                        break;
                    }else{}
                    printf("Voce escolheu %d pizzas. Esta correto? (1-Sim; 2-Nao)\n", pizzas);
                    scanf("%d", &confirm);
                    if(confirm == 1){ //Pedido confirmado
                        pizza pedido[pizzas];
                        criaPedidos(&pedido, pizzas); //Cria todos os pedidos
                        //Confirma pedidos
                        //Cadastra informações
                        //Notafiscal
                    }else if(confirm == 2){ //Cliente deseja voltare
                        printf("Voltando para o menu...\n");
                    }else{ //Opção invalida
                        printf("Opcao invalida\n");
                        confirm = 1;
                    }
                }while(confirm !=1);
                break;
            case 0: //Deseja fechar
                printf("Volte sempre!");
                break;

            default:
                printf("Digite uma opçao valida!\n");
            }
    }while(continuar == 1);
    return 0;
}

void menu(){
    printf("Bem vindos a Pizzaria Galla's!\n");
    printf("Vamos fazer um pedido?\n");
    printf("[1] - Novo pedido\n");
    printf("[0] - Sair\n");
    return;
}

void criaPedidos(pizza* pedido, int quanPizzas){
    for(int i = 0; i<quanPizzas; i++){
        pizza* structPedido = &pedido[i]; //ponteiro que aponta a Struct atual
        char* tamanho = structPedido->tamanho; //ponteiro que aponta o "tamanho" da struct
        float* preco = &structPedido->preco; //ponteiro que aponta o "preço" da struct
        char* sabores = structPedido->sabores[0]; //ponteiro que aponta os "preço" da struct
        //** guarda o endereço de memória de outro ponteiro
        printf("Vamos montar sua pizza n %d\n",i+1);
        tamanhoPrecoPizza(&tamanho, &preco);//é enviado o endereçamento de memória do "tamanho" e do "preço" da struct
        saboresPizza(sabores);
        for (int i = 0; i < 4; i++){
            printf("%s\n",structPedido->sabores[i]);
        }
    }
    return;
}

void tamanhoPrecoPizza(char** tamanho, float** preco){ //Descobre o tamanho e preço da pizza que o usuário quer
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
            strcpy(*tamanho, "Pequeno");
            **preco = 24.75;
            break;
        
        case 2:
            strcpy(*tamanho, "Medio");
            **preco = 49.5;
            break;

        case 3:
            strcpy(*tamanho, "Pequeno");
            **preco = 74.25;
            break;

        case 4:
            strcpy(*tamanho, "Pequeno");
            **preco = 99;
            break;
        
        default:
            printf("Opcao inválida! insira novamente!\n");
            flavor = 0;
            break;
        }
    }while (flavor == 0);
    return;
}

void saboresPizza(char* sabores){
    int quan, check, flavor;
    for(int i = 0; i<4; i++){
        strcpy(sabores + i * 20, "0");
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
                    strcpy(sabores + i * 20, "Calabresa");
                    break;

                case 2:
                    strcpy(sabores + i * 20, "Frango com Catupiry");
                    break;

                case 3:
                    strcpy(sabores + i * 20, "Portuguesa");
                    break;

                case 4:
                    strcpy(sabores + i * 20, "Marguerita");
                    break;

                case 5:
                    strcpy(sabores + i * 20, "Estrogonofe");
                    break;

                case 6:
                    strcpy(sabores + i * 20, "Quatro queijos");
                    break;

                case 7:
                    strcpy(sabores + i * 20, "Sensacao");
                    break;
                
                case 8:
                    strcpy(sabores + i * 20, "Romeu e julieta");
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
