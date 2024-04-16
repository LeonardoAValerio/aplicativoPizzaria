/*
-Bebidas
-Preço Pizza
-Nota fiscal/Pagamento(Gabriel)
*/

#include <stdio.h>
#include <windows.h>
#include <string.h>

#define SIZE_MAX_FLAVORS 4 //O valor máximo de sabores, que pode ser de 1 - 4
#define PRICE_PIZZA 24.75 //O preço da pizza é 24,75 x o tamanho
#define MAX_CHAR 100 //O máximo de caracteres do cadastro

typedef struct{ //A estrutura da pizza, que tem Tamanho, sabores e preço
    int size;
    int flavors[SIZE_MAX_FLAVORS];
    float price;
}pizza;

typedef struct{ //A estrutura do cadastro, que tem o nome, o endereço e o numero dele
    char name[MAX_CHAR];
    char adress[MAX_CHAR];
    char number[MAX_CHAR];
}registerPizza;

//Todas as funções declaradas antes
int tamanhoPizza(); 
int* saboresPizza();
int pedidosPizza(pizza*, int);
registerPizza getRegister();
void notafiscal(pizza*, int);

int main(){
    int option, pagamento; //Variáveis de checkagem, como a da opção inicial e quando ele decidir pagar.
    int currentSize, sizeMaxArr = 0; 
    //currentSize: a posição do array dos pedidos que vou alterar / sizeMaxArr: o numero de pedidos totais
    int* arrFlavor; //Variavel ponteira que ira receber a função ponteira
    registerPizza registered; //A estrutura que recebe o cadastro do cliente da função
    pizza* pizzaArr = malloc(sizeMaxArr * sizeof(pizza)); 
    //O array de struct que usa alocação dinâmica de memória, para aumentar todo novo pedido
    do{
        system("cls");
        printf("Bem vindo a Pizzaria Galla!\n");
        printf("\t[2]-Novo Pedido\n");
        printf("\t[1]-Verificar/Confirmar Pedidos\n");
        printf("\t[0]-Sair\n");
        printf("Digite oque deseja fazer: ");
        scanf("%d",&option); 
        switch (option){ //Verifica qual opção ele deseja
        case 2: //Quando ele deseja uma nova pizza
            sizeMaxArr++; //Acrescenta um pedido ao valor total de pedido
            currentSize = sizeMaxArr-1; //Define qual será o pedido que será alterado na array
            pizzaArr = realloc(pizzaArr, sizeMaxArr * sizeof(pizza)); //redimensiona o tamanho do array, sendo vezes o valor total de pedidos
            printf("Vamos montar uma pizza!\n");
            pizzaArr[currentSize].size = tamanhoPizza(); //no array atual, alteramos o tamanho da struct com a função tamanhoPizza(); 
            arrFlavor = saboresPizza(); //Guardamos primeiro em um valor ponteiro todo o array devolvido com a função saboresPizza();
            for(int k = 0; k<SIZE_MAX_FLAVORS; k++){ //Fazemos um loop para usar os valores recebidos da váriavel para trocar cada sabor da struct
                pizzaArr[currentSize].flavors[k] = arrFlavor[k];
            }
            pizzaArr[currentSize].price = (float)pizzaArr[currentSize].size * PRICE_PIZZA; //Fazemos um cálculo simples para alterar o preço, com o tamanho*preçoPizza
            break;//Termina o pedido

        case 1: //Quando ele deseja verificar os pedidos dele
            pagamento = pedidosPizza(pizzaArr, sizeMaxArr); //mostra todos os pedidos e retorna a opção que ele escolheu
            switch (pagamento){
            case 2: //Quandoele escolhe finalizar o pedido
                registered = getRegister(); //Guarda na struct a função que retorna a struct que o usuário mudou
                notafiscal(pizzaArr, sizeMaxArr); //chama o função que mostra nota fiscal final
                break;
            case 1: //Quando ele escolhe limpar todos os pedidos
                free(pizzaArr); //limpa a memória da alocação dinâmica
                currentSize = 0; //define que a posição do array agora é 0
                sizeMaxArr = 0; //zera o valor de pedidos
                pizzaArr = malloc(sizeMaxArr * sizeof(pizza)); //cria a array de structs novamente coms os valores zerados
                break;
            default: //Quando nenhua é escolhida, não acontece nada
                break;
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
    free(pizzaArr); //Limpa a memória dinâmica utilizada
    return 0;
}

int tamanhoPizza(){ //Descobre o tamanho da pizza que o usuário quer
    int optionT; //opção do tamanhoPizza
    do{
        printf("Escolha o tamanho da sua pizza!\n");
        printf("\t[1] - Pequeno \n");
        printf("\t[2] - Medio\n");
        printf("\t[3] - Grande\n");
        printf("\t[4] - Familia\n");
        printf("Digite o valor do tamanho da pizza: ");
        scanf("%d",&optionT); //verifica qual ele selecionou
        if(optionT < 0 || optionT > 4){ //se ele selecionou errado ele deixa a var igual a 0, loopando de novo
            printf("Opcao invalida!\n");
            optionT = 0;
        }
    }while (optionT == 0);
    return optionT; //retorna a opção selecionada para quem chamou
}

int* saboresPizza(){ //Descobre os sabores da pizza que o usuário quer
    int *flavorP = malloc(SIZE_MAX_FLAVORS * sizeof(int)); //cria uma alocação dinâmica para conseguir retornar um array em uma função
    int quan, check = 1;
    for(int i = 0; i<SIZE_MAX_FLAVORS; i++){ //inicia todos os valores em 0, para quando não tiver sabor
        flavorP[i] = 0;
    }
    do{
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
        for(int i = 0; i<quan; i++){//loop para trocar os valores do array com o valor do sabores
            while(flavorP[i]<1 || flavorP[i]>8){ //while pra verificar se ele selecionou um sabor existente
            printf("Digite o valor do seu %d sabor: ",i+1);
                scanf("%d",&flavorP[i]); //troca o valor no array de sabores com valor escrito
                if(flavorP[i]<1 || flavorP[i]>8){ 
                    printf("Opcao invalida!\n");//se ele não seleciona um correto, ele avisa que foi inválido
                }
            }
        }
        check = 1; //faz o loop acabar
    }while(check == 0);
    return flavorP; //retorna o array de sabores de alocação dinâmica
}

int pedidosPizza(pizza* order, int numOrder){ //Mostra os pedidos e as opções
    //order: struct de arrays / numOrder: valor total de pedidos
    int confirm; //variavél de checkagem
    do{
    printf("\nSeus pedidos sao:\n");
    for (int i = 0; i < numOrder; i++) { //faz um loop usando o valor total de pedidos
        printf("Pedido %d:\n", i + 1);
        char size[10]; //Faz uma variável pra mostrar o nome do tamanho
        switch (order[i].size){ //Muda o nome "size" baseado no valor do tamanho da struct atual
        case 4:
            strcpy(size, "Familia"); //copia a string para dentro da variável
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
        printf("\tTamanho: %s\n", size); //printa o nome do size
        for(int k = 0; k<SIZE_MAX_FLAVORS; k++){ //Faz um loop para conseguir printar os 4 sabores
            char flavor[20]; //Uma variável pra mostrar o nome do sabor
            switch (order[i].flavors[k]) //muda do nome "flavor" baseado no valor do sabor que está sendo testado no loop atual
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
            if(order[i].flavors[k] != 0){ //quando o sabor é igual a 0, ele não printa aquele sabor, pois não há sabor
                printf("\tSabor %d: %s\n", k+1,flavor);
            }
        }
        printf("\tPreco: R$%.2f\n", order[i].price);
    }
    printf("\n");
    if(numOrder > 0){// Quando o numero de pizzas for maior que 1, ele mostra que ele pode confirmar ou cancelar o pedido
            printf("\t[2] - Confirmar Pedido(s)\n");
            printf("\t[1] - Cancelar Pedido(s)\n");
        }
        printf("\t[0] - Voltar\n");
    scanf("%d", &confirm); //verifica a opção do usuário

    if(confirm == 2 && numOrder>0){ //Quando ele confirmar o pedido e poder confirmar:
        return 2; //retorna para a main, que usa esse valor
    }else if(confirm == 1 && numOrder>0){ //Quando ele cancelar o pedido e poder cancelar
        return 1; 
    }else if(confirm == 0){ //Quando ele voltar para o menu
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

void notafiscal(pizza* pedidos, int maxPedidos){
    //loop{
    //printar o pedido (pedido 1)
    //printar o tamanho dele
    //printar o 4 sabores (considerando que o sabores que forem 0 não apareceram)
    //printar o tamanho
    //}
}