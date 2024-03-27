//RECADO IMPORTANTE: TENTEM NÃO USAR CHATGPT PARA CODAR O CÓDIGO DE NOSSO PROJETO, OBRIGADO. 
#include <stdio.h> //Incluindo a bilbioteca de entrada de valores
#include <stdlib.h> //Incluindo a biblioteca de alocação de memória

#define ARR_SAB 4 //Este define, serve para definir um nome com um valor especifico, Exemplo:
//#define PI 3.1416 
//Sempre que escrever "PI" dentro do código, será convertido para o valor colocado 

<<<<<<< HEAD
int tamanhoPizza(); //Chamada da função
int* saboresPizza(); //Chamada da função, ela tem um ponteiro, por conta que irá apontar uma localização na memória
=======
int tamanhoPizza(){
    printf("Vamos escolher um tamanho para sua pizza!\n");
    printf("[1]-Pequeno\n");
    printf("[1]-Médio\n");
    printf("[3]-Grande\n");
    printf("[4]-Fámilia\n");
    printf("[5]-Fámilia\n");
    scanf("%i",&tam);
    // ignore
>>>>>>> develop

int main(){ //O MENU INICIAL
    int option;
    int* arr; //Esse valor ele é um ponteiro, por conta que ele irá apontar a memória que o 'saboresPizza' está guardand
    printf("Bem vindo a pizzaria Pizzas\n Oque Desejas?\n");
    printf("[1]Pedir uma pizza\n");
    printf("[2]Sair\n");
    scanf("%i",&option);
    if(option == 1){ //PEDINDDO A PIZZA
                        //O Ato de chamar a função, é basicamente fazer ela rodar, na main
                        //Algumas funções podem ter parâmetros, sendo os valores dentro do parentênses
        //valor(n1,n2);
        tamanhoPizza(); //Chama a função tamanhoPizza
        arr = saboresPizza(); //Chama a função saboresPizza, e guarda o valor retornado, que é um vetor, em um ponteiro
        //Aqui vocês poderiam colocar as outras funções que irão aparecendo
    }else{
        return 0;
    }
    free(arr); //Limpa a memória guardada do 'arr'. Apenas utilize no final do código, pra esse código não pesar no seu PC
                //Mas isso serve para em programas mais complexos, limpar sempre a memória de uma váriavel
                //pra não ficar acumulando ou dar erro
return 0;
}

int tamanhoPizza(){ //DEFININDO O TAMANHO DA PIZZA
    int tam;
    printf("Vamos escolher um tamanho para sua pizza!\n");
    printf("[1]-Pequeno\n");
    printf("[2]-Medio\n");
    printf("[3]-Grande\n");
    printf("[4]-Familia\n");
    scanf("%i",&tam); //Aqui ele pega o valor definido do tamanho da Pizza
    return tam; //E isso ele retorna o valor pra quem ele chamou. 
                //Esse valor se não for guardado em uma váriavel, é apagado
}

int* saboresPizza(){ //DEFININDO OS SABORES DA PIZZA
    //Essa função tem os comandos mais complexos, mas que vocês precisam
    //entender, e provavelmente usar, por exemplo, nos refrigerantes
    
    int *sab = malloc(ARR_SAB*sizeof(int)); //Essa aqui é uma variavél ponteiro, pois vai apontar um local na memória
    //Definimos o tamanho dela com o 'malloc' ou 'memorie-allocation' uma função da biblioteca <stdlib.h>
    //Dentro do malloc colocamos a quantidade de valores que iramos querer, exemplo ARR_SAB (Que vale 4, como definimos no início)
    //Esse valor vezes(*) 'sizeof(tipoVariavel)'. Então você vai usar a função sizeof(), e dentro de seus parentêses você coloca
    //o tipo de variavel que irá ser, pois isso irá definir o tamnho, em Bytes dessa váriavel. Por conta disso, é importante você
    //escrever certinho pra não dar nada errado na memória! :D
    int quan;
    for(int i=0; i<ARR_SAB; i++){//Isso é um loop simples para definir todos os valores do vetor, serem igual a 0
        sab[i] = 0;
    }
    //Recomendo que para vocês entenderem bem, veja o vídeo:
    //https://www.youtube.com/watch?v=F3Kn4iyrrEA&list=PLpaKFn4Q4GMOBAeqC1S5_Fna_Y5XaOQS2&index=14
    //Esse tipo de loop é muito importante vocês entenderem, provavelmente o professor vai ensinar
    //mas se quiseres aprenderem antes
    printf("Quantos sabores voce ira querer [1-4]:\n");
    scanf("%i",&quan);
    for(int i=0; i<quan; i++){ //Loop que dependendo da quantidade de sabores, ele vai printar esse código inteiro na quantidade de sabores
        printf("Escolha seu sabor numero %i:\n",i+1);
        printf("[1]Calabresa\n");
        printf("[2]Frango com catupiry\n");
        printf("[3]Marguerita\n");
        printf("[4]Baiana\n");
        scanf("%d",&sab[i]); //Ele guarda em sab[i], pois dependo do valor que está sendo i, ele guarda naquele local
        //Essa parte, recomendo que vocês vejam sobre vetores e arrays:
        //https://www.youtube.com/watch?v=5fSf9xSJK7c&list=PLpaKFn4Q4GMOBAeqC1S5_Fna_Y5XaOQS2&index=16
    }
    return sab; //Retorna para quem chamou o vetor dos sabores
}

//Qualquer coisa é só me chamar
//Atenciosamente Leonardo Valério.