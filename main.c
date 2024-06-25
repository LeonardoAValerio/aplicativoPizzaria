#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
    char tamanho[20];
    char sabores[4][20];
    float preco;
} pizza;

void menu();
void criaPedidos(pizza *pedido, int quanPizzas);
void tamanhoPrecoPizza(char *tamanho, float *preco);
void saboresPizza(char sabores[][20]);
void notaFiscal(pizza *pedido, int quanPizzas);
int checkPedido(pizza* pedido, int pizzas);
void mostrarPedido(pizza* pedido, int quanPizzas);
void alterarPedido(pizza* pedido, int quanPizzas);

int main() {
    int continuar = 1;
    int pizzas;
    int confirm;
    do{
        menu();
        scanf("%d", &continuar);
        fflush(stdin); // Limpa o buffer de entrada para evitar problemas com o scanf
        switch (continuar) {
            case 1: // Deseja pedir
                for(;;){
                    printf("Vamos aos pedidos!\n");
                    printf("Escolha a quantidade de pizzas: \n");
                    scanf("%d", &pizzas);
                    fflush(stdin); // Limpa o buffer de entrada

                    if (pizzas < 1) {
                        printf("Escolha um valor valido\n");
                        break;
                    }

                    printf("Voce escolheu %d pizzas. Esta correto? (1-Sim; 2-Nao)\n", pizzas);
                    scanf("%d", &confirm);
                    fflush(stdin); // Limpa o buffer de entrada

                    if(confirm == 1){ // Pedido confirmado
                        pizza pedido[pizzas];
                        criaPedidos(pedido, pizzas); // Cria todos os pedidos
                        if(checkPedido(pedido, pizzas)){
                            notaFiscal(pedido, pizzas); // Chama a função para gerar a nota fiscal
                            continue;
                        }else{
                            break;
                        }
                    }else if (confirm == 2) { // Cliente deseja voltar
                        printf("Voltando para o menu...\n");

                    }else { // Opção invalida1'1
                        printf("Opcao invalida\n");
                        confirm = 1;
                    }
                } while (confirm != 1);
                break;
                
            case 0: // Deseja fechar
                printf("Volte sempre!");
                break;

            default:
                printf("Digite uma opcao valida!\n");
        }
        
    }while (continuar == 1);

    return 0;
}

void menu() {
    printf("Bem vindos a Pizzaria Galla's!\n");
    printf("Vamos fazer um pedido?\n");
    printf("[1] - Novo pedido\n");
    printf("[0] - Sair\n");
}

void criaPedidos(pizza *pedido, int quanPizzas) {
    for (int i = 0; i < quanPizzas; i++) {
        system("cls");
        pizza *structPedido = &pedido[i]; // Ponteiro que aponta para a struct atual
        printf("Vamos montar sua pizza n %d\n", i + 1);

        tamanhoPrecoPizza(structPedido->tamanho, &structPedido->preco); // Passando diretamente o tamanho e o preço
        saboresPizza(structPedido->sabores);
    }
}

void tamanhoPrecoPizza(char *tamanho, float *preco) {
    int flavor;
    do {
        flavor = 1;
        printf("Escolha o tamanho da sua pizza!\n");
        printf("\t[1] - Pequeno - R$24.75\n");
        printf("\t[2] - Medio   - R$49.50\n");
        printf("\t[3] - Grande  - R$74.25\n");
        printf("\t[4] - Familia - R$99.00\n");
        printf("Digite o valor do tamanho da pizza: ");
        scanf("%d", &flavor); // Verifica qual ele selecionou
        fflush(stdin); // Limpa o buffer de entrada

        switch (flavor) {
            case 1:
                strcpy(tamanho, "Pequeno");
                *preco = 24.75;
                break;

            case 2:
                strcpy(tamanho, "Medio");
                *preco = 49.5;
                break;

            case 3:
                strcpy(tamanho, "Grande");
                *preco = 74.25;
                break;

            case 4:
                strcpy(tamanho, "Familia");
                *preco = 99;
                break;

            default:
                printf("Opcao inválida! insira novamente!\n");
                flavor = 0;
                break;
        }
    } while (flavor == 0);
}

void saboresPizza(char sabores[][20]) {
    int quan, check, flavor;
    for (int i = 0; i < 4; i++) {
        strcpy(sabores[i], "0");
    }
    do {
        check = 1;

        printf("Informe quantos sabores deseja(1-4): ");
        scanf("%d", &quan); // Verifica quantos sabores o usuário deseja
        fflush(stdin); // Limpa o buffer de entrada

        if (quan < 1 || quan > 4) { // Checka se ele selecionou a quantidade entre 1-4, e se não ele fala pra ele repetir
            printf("Opcao invalida!\n");
            check = 0;
            continue; // Pula o código e volta para a seleção de sabores
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

        for (int i = 0; i < quan; i++) {
            printf("Digite o valor do seu %d sabor: ", i + 1);
            scanf("%d", &flavor);
            fflush(stdin); // Limpa o buffer de entrada

            switch (flavor) {
                case 1:
                    strcpy(sabores[i], "Calabresa");
                    break;

                case 2:
                    strcpy(sabores[i], "Frango com Catupiry");
                    break;

                case 3:
                    strcpy(sabores[i], "Portuguesa");
                    break;

                case 4:
                    strcpy(sabores[i], "Marguerita");
                    break;

                case 5:
                    strcpy(sabores[i], "Estrogonofe");
                    break;

                case 6:
                    strcpy(sabores[i], "Quatro queijos");
                    break;

                case 7:
                    strcpy(sabores[i], "Sensacao");
                    break;

                case 8:
                    strcpy(sabores[i], "Romeu e julieta");
                    break;

                default:
                    printf("Opção invalida! tente novamente!\n");
                    check = 0;
                    break;
            }
        }
    } while (check == 0);
}

int checkPedido(pizza* pedido, int pizzas){
    int opcao, continuar;
    do{
        system("cls || clear");
        mostrarPedido(pedido, pizzas);
        printf("Opcoes:\n");
        printf("[1] - Confirmar Pedido\n");
        printf("[2] - Alterar Pedido\n");
        printf("[3] - Cancelar Pedido\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao) {
            case 1:
            printf("Pedido confirmado!\n");
            continuar = 0;
            break;

            case 2:
            alterarPedido(pedido, pizzas);
            break;

            case 3:
            printf("Pedido cancelado.\n");
            continuar = 0;
            break;

            default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
        }
    }while (opcao != 1 && opcao != 3);
    return continuar;
}

void mostrarPedido(pizza* pedido, int quanPizzas) {
    for (int i = 0; i < quanPizzas; i++) {
        printf("\nPedido %d:\n", i + 1);
        printf("Tamanho: %s\n", pedido[i].tamanho);
        printf("Preco: %.2f\n", pedido[i].preco);
        printf("Sabores:\n");
        for (int j = 0; j < 4; j++) {
            if (strcmp(pedido[i].sabores[j], "0") != 0) {
                printf(" - %s\n", pedido[i].sabores[j]);
            }
        }
    }
}

void alterarPedido(pizza* pedido, int quanPizzas) {
    int pedidoNum, opcao;
    printf("Qual pedido deseja alterar? (1-%d): ", quanPizzas);
    scanf("%d", &pedidoNum);
    if (pedidoNum < 1 || pedidoNum > quanPizzas) {
        printf("Pedido invalido!\n");
        return;
    }
    pizza* structPedido = &pedido[pedidoNum - 1];
    do {
        printf("O que deseja alterar?\n");
        printf("[1] - Tamanho\n");
        printf("[2] - Sabores\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                tamanhoPrecoPizza(structPedido->tamanho, &(structPedido->preco));
                break;
            case 2:
                saboresPizza(structPedido->sabores);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                opcao = 0;
                break;
        }
    } while (opcao == 0);
}

void notaFiscal(pizza *pedido, int quanPizzas) {
    system("cls || clear");
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);

    data_hora_atual = localtime(&segundos);

    FILE *arquivo;
    arquivo = fopen("nota_fiscal.txt", "w");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Data e Hora: %02d/%02d/%04d %02d:%02d:%02d\n\n",
           data_hora_atual->tm_mday,
           data_hora_atual->tm_mon + 1,
           data_hora_atual->tm_year + 1900,
           data_hora_atual->tm_hour,
           data_hora_atual->tm_min,
           data_hora_atual->tm_sec);

    float totalGeral = 0.0;

    for (int e = 0; e < quanPizzas; e++) {

        pizza *structPedido = &pedido[e];

        fprintf(arquivo, "Pizza %d:\n", e + 1);
        fprintf(arquivo, "Tamanho:\n %s\n\n", structPedido->tamanho);
        fprintf(arquivo, "Sabores:\n");

        for (int j = 0; j < 4; j++) {
            if (strcmp(structPedido->sabores[j], "0") != 0)
             {
                fprintf(arquivo, "%s\n ", structPedido->sabores[j]);
            }
        }
        fprintf(arquivo, "\nPreco: R$ %.2f\n\n", structPedido->preco);
        totalGeral += structPedido->preco;
    }

    fprintf(arquivo, "Valor Total: R$ %.2f\n", totalGeral);

    fclose(arquivo);
    system("cls || clear");
    printf("Pedido Feito com sucesso!! \n\n\n\n\n");
    return;
}