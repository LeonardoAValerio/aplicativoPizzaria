#include <stdio.h>
#include <windows.h>

typedef struct {
    char tamanho[20];
    char sabor[20];
}Pedido;

int pedidosPizzas(int);

//"MENU"
int main(){
    int option, n, pagamento;
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
            
            continue;
        
        case 1:
            pagamento = pedidosPizzas(n);
            if(pagamento == 1){
                cadastro();
                notaFiscal();
            }
            continue;

        case 0:
            printf("Volte Sempre!\n");
            continue;
                    
        default:
            printf("Opcao invalida!\n");
            continue;
        }
    }while(option != 0);
    return 0;
}

int pedidosPizzas(int numPedidos){
    Pedido pedidos[1];
    int confirm, numPedidos = 0;
    do{
    printf("\nSeus pedidos sao:\n");
    for (int i = 0; i < numPedidos; i++) {
        printf("Pedido %d:\n", i + 1);
        printf("  Tamanho: %s\n", pedidos[i].tamanho);
        printf("  Sabor: %s\n", pedidos[i].sabor);
    }
    if(numPedidos > 0){
            printf("\t[2] - Confirmar Pedido(s)\n");
            printf("\t[1] - Cancelar Pedido(s)\n");
        }
        printf("\t[0] - Voltar\n");
    scanf("%d", &confirm);
    }while (confirm != 2);
    printf("\nVocê sera redirecionado para a pagina de pagamento.\n");
    return 0;
}

/*
//CADASTRO
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

struct Cadastro {
    char nome[MAX_LENGTH];
    char endereco[MAX_LENGTH];
    char telefone[MAX_LENGTH];
};

int main() {
    struct Cadastro cadastro;

    printf("Cadastro\n");
    printf("--------\n");

    printf("Nome completo: ");
    fgets(cadastro.nome, MAX_LENGTH, stdin);
    cadastro.nome[strcspn(cadastro.nome, "\n")] = 0;

    printf("EndereCo: ");
    fgets(cadastro.endereco, MAX_LENGTH, stdin);
    cadastro.endereco[strcspn(cadastro.endereco, "\n")] = 0;

    printf("Número de telefone: ");
    fgets(cadastro.telefone, MAX_LENGTH, stdin);
    cadastro.telefone[strcspn(cadastro.telefone, "\n")] = 0;

    printf("\nCadastro realizado com sucesso!\n\n");

    printf("Informacoes cadastradas:\n");
    printf("Nome: %s\n", cadastro.nome);
    printf("Endereco: %s\n", cadastro.endereco);
    printf("Numero de telefone: %s\n", cadastro.telefone);

    return 0;
}

printf("Menu:\n");
        printf("1. Refrigerante 2L aleatorio - R$10.00\n");
        printf("2. Agua 500ml - R$3.00\n");
        printf("3. Fardo de 6 latas de cerveja 473ml- R$36.00\n");
        printf("4. Energetico 2L- R$14.00\n");
*/
