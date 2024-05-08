//Imagine como se fosse um pedido no Mc'Donalds
//Pedido - Fazer um pedido de cada vez, considerando que um Pedido pode ter infinitas pizzas!
//Fazer o retorno dos sabores, tamanhos, em files! que servirá pra não precisar converter!
//Cadastro - Guardar em Files, e poder verificar se ele cadastrou certo!
//Selecionar a porção da pizza que o sabor irá ter!
//Nota fiscal, !!FUNCIONAL!!
//Adicionais/Montar sua pizza
//Registro de quantos pedidos ele já fez em todo o aplicativo! (opcional)

#include <stdio.h>
#include <windows.h>
#include <string.h>

#define SIZE_MAX_FLAVORS 4 //O valor máximo de sabores, que pode ser de 1 - 4
#define PRICE_PIZZA 24.75 //O preço da pizza é 24,75 x o tamanho
#define MAX_CHAR 100 //O máximo de caracteres do cadastro

typedef struct{ //A estrutura da pizza, que tem Tamanho, sabores e preço
    char size[20];
    char flavors[SIZE_MAX_FLAVORS][MAX_CHAR];
    float price;
}pizza;

typedef struct{ //A estrutura do cadastro, que tem o nome, o endereço e o numero dele
    char name[MAX_CHAR];
    char adress[MAX_CHAR];
    char number[MAX_CHAR];
}registerPizza;

//Todas as funções declaradas antes
void tamanhoPizza(); 
void saboresPizza();

//Variável file
FILE* filePizza;

int main(){
    system("cls");
    int option;
    int currentSize, sizeMaxArr = 0; 
    pizza* pizzaArr = malloc(sizeMaxArr * sizeof(pizza)); //O array de struct que usa alocação dinâmica de memória, para aumentar todo novo pedido
    do{
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
            tamanhoPizza();
            filePizza = fopen("size.txt", "r");
            fgets(pizzaArr[currentSize].size, MAX_CHAR, filePizza);
            fclose(filePizza);
            saboresPizza();
            
            break;//Termina o pedido

        case 1: //Quando ele deseja verificar os pedidos dele

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

void tamanhoPizza(){ //Descobre o tamanho da pizza que o usuário quer
    int optionT; //opção do tamanhoPizza
    filePizza = fopen("size.txt", "w");
    do{
        printf("Escolha o tamanho da sua pizza!\n");
        printf("\t[1] - Pequeno \n");
        printf("\t[2] - Medio\n");
        printf("\t[3] - Grande\n");
        printf("\t[4] - Familia\n");
        printf("Digite o valor do tamanho da pizza: ");
        scanf("%d",&optionT); //verifica qual ele selecionou
        switch (optionT)
        {
        case 1:
            fprintf(filePizza, "Pequeno");
            break;
        
        case 2:
            fprintf(filePizza, "Medio");
            break;

        case 3:
            fprintf(filePizza, "Grande");
            break;

        case 4:
            fprintf(filePizza, "Familia");
            break;
        
        default:
            printf("Opcao inválida! insira novamente!\n");
            optionT = 0;
            break;
        }
    }while (optionT == 0);
    fclose(filePizza);
}

void saboresPizza(){ //Descobre os sabores da pizza que o usuário quer (Sendo essa função ponteira, pois retorna um valor ponteiro)
    int quan, check = 1;
    int flavorP = 0;
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
        for(int i = 0; i<quan; i++){
            printf("Digite o valor do seu %d sabor: ",i+1);
                scanf("%d",&flavorP);
                if(i == 0){
                    filePizza = fopen("flavor.txt", "w");
                }else{
                    filePizza = fopen("flavor.txt", "a");
                }
                switch (flavorP)
                {
                case 1:
                    fprintf(filePizza, "Calabresa\n");
                    break;

                case 2:
                    fprintf(filePizza, "Frango com Catupiry\n");
                    break;

                case 3:
                    fprintf(filePizza, "Portuguesa\n");
                    break;

                case 4:
                    fprintf(filePizza, "Marguerita\n");
                    break;

                case 5:
                    fprintf(filePizza, "Estrogonofe\n");
                    break;

                case 6:
                    fprintf(filePizza, "Quatro queijos\n");
                    break;

                case 7:
                    fprintf(filePizza, "Sensação\n");
                    break;

                case 8:
                    fprintf(filePizza, "Romeu e Julieta\n");
                    break;
                
                default:
                    printf("Opção invalida! tente novamente!\n");
                    break;
                }
                fclose(filePizza);
        }
        check = 1; //faz o loop acabar
    }while(check == 0);
}

