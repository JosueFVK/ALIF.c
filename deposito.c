#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "deposito.h"

#define MAX_PRODUTOS 100
#define MAX_DEPOSITO 5


void clearInputBufferDeposito() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int validaCep(char cep[MAX_CEP]){
    int tamanho = strlen(cep);

    if(tamanho != 9){
        return 1;
    }

    for(int i = 0; i<tamanho-1;i++){
        if(i == 5){
            if(cep[i] == '-'){
                return 0;
            }else{
                if(!isdigit(cep[i])){
                    return 1;
                }
            }
        }
    }
    return 1;
}


void cadastrarDeposito(int numDepositos, Deposito deposito[]) {
    if (numDepositos >= MAX_DEPOSITO) {
        printf("Numero maximo de depositos atingido!\n");
        return;
    }

    Deposito novoDeposito;

    printf("\nNome do Deposito:  ");
    scanf("%s", novoDeposito.nome);
    clearInputBufferDeposito();

    char cepInput[MAX_CEP];
    int verifica = 1;  // Initialized to a non-zero value to enter the loop

    printf("CEP no formato XXXXX-XXX: ");
    scanf("%s", cepInput);
    clearInputBufferDeposito();

    while (verifica != 0) {
        verifica = validaCep(cepInput);
        if (verifica == 0) {
            break;
        }
        printf("Cep invalido, digite novamente: ");
        scanf("%s", cepInput);
        clearInputBufferDeposito();
    }
    strcpy(novoDeposito.cep, cepInput);

    printf("Endereco: ");
    scanf(" %[^\n]s", novoDeposito.endereco);
    clearInputBufferDeposito();

    printf("Telefone: ");
    scanf(" %[^\n]s", novoDeposito.telefone);
    clearInputBufferDeposito();

    printf("Capacidade máxima (em metros cúbicos): ");
    scanf("%f", &novoDeposito.capacidade);
    clearInputBufferDeposito();

    novoDeposito.estoque = 0;

    deposito[numDepositos] = novoDeposito;
    numDepositos++;

    printf("Deposito cadastrado!\n\n");
}


void consultarDeposito(int numDepositos, Deposito deposito[]) {
    char cep[MAX_CEP];
    printf("Digite o CEP do deposito: ");
    scanf(" %[^\n]s", cep);
    clearInputBufferDeposito();

    for (int i = 0; i < numDepositos; i++) {
        if (strcmp(deposito[i].cep, cep) == 0) {
            
            printf("\nNome do deposito: %s\n", deposito[i].nome);
            printf("CEP: %s\n", deposito[i].cep);
            printf("Endereco: %s\n", deposito[i].endereco);
            printf("Telefone: %s\n", deposito[i].telefone);
            printf("Estoque: %.2f de %.2f metros cubicos\n\n", deposito[i].estoque, deposito[i].capacidade);
            return;
        }
    }

    printf("\nDeposito nao encontrado.\n");
}


void consultarTodosDepositos(int numDepositos, Deposito deposito[]){
    if (numDepositos == 0) {
        printf("Nenhum deposito encontrado! \n");
        return;
    }

    for(int i = 0; i < numDepositos; i++){
        printf("\n----- Deposito %d -----\n",i+1);
        printf("Deposito %d:\n", i+1);
        printf("Nome do deposito: %s\n", deposito[i].nome);
        printf("CEP: %s\n", deposito[i].cep);
        printf("Endereco: %s\n", deposito[i].endereco);
        printf("Telefone: %s\n", deposito[i].telefone);
        printf("Estoque: %.2f de %.2f metros cubicos\n\n", deposito[i].estoque, deposito[i].capacidade);
        printf("\n");
    }
}

void atualizarDadosDeposito(int numDepositos, Deposito deposito[]){
    int opcao;
    char cep[MAX_CEP];
    printf("Digite o CEP do deposito: ");
    scanf(" %[^\n]s", cep);
    clearInputBufferDeposito();

    for(int i = 0; i < numDepositos; i++){
        if(strcmp(deposito[i].cep, cep) == 0){

            while(opcao != 6){
                printf("Qual dado voce quer atualizar?\n");
                printf("1. Nome do Deposito\n");
                printf("2. CEP\n");
                printf("3. Endereco\n");
                printf("4. Telefone\n");
                printf("5. Capacidade maxima\n");
                printf("6. Voltar ao menu\n");
                printf("Opcao: ");
                scanf("%d", &opcao);
                clearInputBufferDeposito();

                if(opcao == 1){
                    printf("Novo nome do Deposito: ");
                    scanf("%s", deposito[i].nome);
                    clearInputBufferDeposito();
                    printf("Atualizado!\n");
                }
                else if(opcao == 2){
                    printf("Novo CEP: ");
                    scanf("%s", deposito[i].cep);
                    clearInputBufferDeposito();
                    printf("Atualizado!\n");
                }
                else if(opcao == 3){
                    printf("Novo Endereco: ");
                    scanf("%s", deposito[i].endereco);
                    clearInputBufferDeposito();
                    printf("Atualizado!\n");
                }
                else if(opcao == 4){
                    printf("Novo Telefone: ");
                    scanf("%s", deposito[i].telefone);
                    clearInputBufferDeposito();
                    printf("Atualizado!\n");
                }
                else if(opcao == 5){
                    printf("Nova capacidade maxima (em metros cubicos): ");
                    scanf("%f", &deposito[i].capacidade);
                    clearInputBufferDeposito();

                    if(deposito[i].estoque <= deposito->capacidade){
                        printf("Atualizado!\n");
                    }
                    else{
                        printf("A nova capacidade maxima e menor do que o quantitativo de estoque atual. Atualizacao nao permitida.\n");
                    }
                }
                else{
                    printf("Opcao invalida!\n");
                }
            }
            return;
        }
    }
    printf("Deposito nao encontrado!\n");
}

void deletarDeposito(int* numDepositos, Deposito deposito[]) {
    char cep[MAX_CEP];
    printf("Digite o CEP do depósito a ser deletado: ");
    scanf(" %[^\n]s", cep);
    clearInputBufferDeposito();

    int indiceDeposito = -1;  // Índice do depósito a ser deletado

    for (int i = 0; i < *numDepositos; i++) {
        if (strcmp(deposito[i].cep, cep) == 0) {
            indiceDeposito = i;  // Encontrou o depósito a ser deletado
            break;
        }
    }

    if (indiceDeposito != -1) {
        // Remover o depósito encontrado
        for (int i = indiceDeposito; i < *numDepositos - 1; i++) {
            deposito[i] = deposito[i + 1];
        }

        (*numDepositos)--;
        printf("Depósito deletado!\n");
    } else {
        printf("Depósito não encontrado.\n");
    }
}
