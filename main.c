#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
    char tamanho[20];
    char sabores[4][20];
    float preco;
}pizza;

typedef struct{
    char nome[100];
    char cpf[12];
}cliente;

void menu();
void criaPedidos(pizza *pedido, int quanPizzas);
void tamanhoPrecoPizza(char *tamanho, float *preco);
void saboresPizza(char sabores[][20]);
int checkPedido(pizza* pedido, int pizzas);
void mostrarPedido(pizza* pedido, int quanPizzas);
void alterarPedido(pizza* pedido, int quanPizzas);
void criaCadastro(cliente* cadastro);
int validaCPF(char *cpf);
int validaNome(char *nome);
void notaFiscal(pizza *pedido, int quanPizzas, cliente *cadastro);

int main() {
    int continuar = 1;
    int pizzas;
    int confirm;
    for(;;){
        menu();
        scanf("%d", &continuar);
        fflush(stdin); // Limpa o buffer de entrada para evitar problemas com o scanf
        switch (continuar) {
            case 1: // Deseja pedir
                do{
                    system("cls || clear");
                    printf("Vamos aos pedidos!\n");
                    printf("Escolha a quantidade de pizzas: \n");
                    scanf("%d", &pizzas);
                    fflush(stdin); // Limpa o buffer de entrada
                    if (pizzas < 1) {
                        printf("Escolha um valor valido\n");
                        continue;
                    }
                    printf("Voce escolheu %d pizzas. Esta correto? (1-Sim; 2-Nao)\n", pizzas);
                    scanf("%d", &confirm);
                    fflush(stdin); // Limpa o buffer de entrada

                    if(confirm == 1){ // Pedido confirmado
                        pizza pedido[pizzas];
                        criaPedidos(pedido, pizzas); // Cria todos os pedidos
                        if(checkPedido(pedido, pizzas)){
                            cliente cadastro;
                            criaCadastro(&cadastro);
                            notaFiscal(pedido, pizzas, &cadastro); // Chama a função para gerar a nota fiscal
                            break;
                        }
                    }else if (confirm == 2) { // Cliente deseja voltar
                        printf("Voltando para o menu...\n");
                        confirm = 1;
                    }else { // Opção invalida1'1
                        printf("Opcao invalida\n");
                        confirm = 1;
                    }
                } while (confirm != 1);
                break;
            case 0: // Deseja fechar
                printf("Volte sempre!");
                continuar = 0;
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
        saboresPizza(structPedido->sabores); //Passa diretamente os sabores
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
                strcpy(tamanho, "Pequeno"); //Copia o tamanho pro vetor da struct
                *preco = 24.75; //Copia o valor pra struct
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
    for (int i = 0; i < 4; i++) { //Inicializa todos os valores
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
            check = 1;
            printf("Digite o valor do seu %d sabor: ", i + 1);
            scanf("%d", &flavor);
            fflush(stdin); // Limpa o buffer de entrada

            switch (flavor) {
                case 1:
                    strcpy(sabores[i], "Calabresa");//Copia pra linha que você deseja alterar
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
                    i--;
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
        mostrarPedido(pedido, pizzas); //Printa todos os pedidos
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
            continuar = 1;
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
    if (pedidoNum < 1 || pedidoNum > quanPizzas) { //Se seleciona um valor que não existe não permite
        printf("Pedido invalido!\n");
        return;
    }
    pizza* structPedido = &pedido[pedidoNum - 1]; //Manda a struct selecionada
    do {
        printf("O que deseja alterar?\n");
        printf("[1] - Tamanho\n");
        printf("[2] - Sabores\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                tamanhoPrecoPizza(structPedido->tamanho, &(structPedido->preco)); //Remanda pras funções de fazer os pedidos
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

void criaCadastro(cliente* cadastro){ //Cria o cadastro da compra
    system("cls || clear");
    printf("Vamos fazer seu cadastro:\n");
    do{
        printf("Digite seu nome:\n");
        fgets(cadastro->nome, 100, stdin);
        fflush(stdin);
        if(!(validaNome(cadastro->nome))){
            printf("Digite um NOME valido\n");
        }
    }while(!(validaNome(cadastro->nome))); //Enquanto o nome não for valido ele não sai
    do{
        printf("Digite seu cpf:\n");
        fgets(cadastro->cpf, 12, stdin);
        fflush(stdin);
        if(!(validaCPF(cadastro->cpf))){
            printf("Digite um CPF valido\n");
        }
    }while(!(validaCPF(cadastro->cpf))); //Enquanto o cpf não for valido não vai
    return;
}

int validaNome(char *nome){
    for(int i=0; i<(int)strlen(nome); i++){
        if(nome[i] >= 'a' && nome[i] <= 'z'){ //verifica se tá entre A a Z
                return 1;
        }
    }
    return 0;
}

int validaCPF(char *cpf){ //Valida o CPF com os cálculos malucos
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf)!=11){
        return 0;
    }
    else{
        for(i = 0, j = 10; i < (int)strlen(cpf)-2; i++, j--){ ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        }
        digito1 %= 11;
        if(digito1 < 2){
            digito1 = 0;
        }
        else{
            digito1 = 11 - digito1;
        }
        if((cpf[9]-48) != digito1){
            return 0;
        }
        ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        ///digito 2--------------------------------------------------
        else{
            for(i = 0, j = 11; i < (int)strlen(cpf)-1; i++, j--){ ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
            }
            digito2 %= 11;
            if(digito2 < 2){
                digito2 = 0;
            }
            else{
                digito2 = 11 - digito2;
            }
            if((cpf[10]-48) != digito2){
                return 0;
            }///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}

void notaFiscal(pizza *pedido, int quanPizzas, cliente *cadastro) {
    system("cls || clear");

    struct tm *data_hora_atual;
    time_t segundos; //representa o horario em segundos
    time(&segundos); //obtem o horario atual em segundos

    data_hora_atual = localtime(&segundos);

    FILE *arquivo;
    arquivo = fopen("nota_fiscal.txt", "w"); //abre um arquivo

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n"); //caso não puder ser aberto
        return;
    }

    // Imprime cabeçalho da nota fiscal
    fprintf(arquivo, "---------------------------------------------\n");
    fprintf(arquivo, "           NOTA FISCAL - Pizzaria Galla's\n");
    fprintf(arquivo, "---------------------------------------------\n");
    fprintf(arquivo, "Data e Hora do pedido: %02d/%02d/%04d %02d:%02d:%02d\n\n",
           data_hora_atual->tm_mday, //dia
           data_hora_atual->tm_mon + 1, //mes
           data_hora_atual->tm_year + 1900, //ano
           data_hora_atual->tm_hour, //hora
           data_hora_atual->tm_min, //minuto
           data_hora_atual->tm_sec); //segundos

    // Imprime  as informações do cliente
    fprintf(arquivo, "Cliente:\n");
    fprintf(arquivo, "Nome cadastrado: %s", cadastro->nome);
    fprintf(arquivo, "Cpf cadastrado: %s\n\n", cadastro->cpf);

    // Imprime os detalhes das pizzas pedidas
    fprintf(arquivo, "Pedido:\n");
    float valorTotal = 0.0; //acumula os o preço de todas as pizzas

    for (int e = 0; e < quanPizzas; e++) {
        pizza *structPedido = &pedido[e];

        fprintf(arquivo, "---------------------------------------------\n");
        fprintf(arquivo, "Pizza %d:\n", e + 1);
        fprintf(arquivo, "Tamanho: %s\n", structPedido->tamanho);
        fprintf(arquivo, "Sabores:\n");

        for (int j = 0; j < 4; j++) {
            if (strcmp(structPedido->sabores[j], "0") != 0) {
                fprintf(arquivo, " - %s\n", structPedido->sabores[j]);
            }
        }

        fprintf(arquivo, "Preco: R$ %.2f\n", structPedido->preco);
        valorTotal += structPedido->preco; //soma o valor das pizzas de forma individual
    }

    fprintf(arquivo, "---------------------------------------------\n");
    fprintf(arquivo, "Valor Total: R$ %.2f\n", valorTotal);
    fprintf(arquivo, "---------------------------------------------\n");

    fclose(arquivo); //Nada apos isso sera printado no TXT
    system("cls || clear");
    printf("Pedido Feito com sucesso!!\nPressione Enter para continuar...\n");
    getchar(); // Espera o enter para continuar
    system("cls || clear");
    return;
}