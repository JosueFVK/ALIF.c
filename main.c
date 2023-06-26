#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"
#include "produtos.h"
#include "deposito.h"

#define MAX_PRODUTOS 100
#define MAX_DEPOSITO 5

void cadastrarDeposito(int numDepositos, Deposito deposito[]);
void consultarDeposito(int numDepositos, Deposito deposito[]);
void consultarTodosDepositos(int numDepositos, Deposito deposito[]);
void atualizarDadosDeposito(int numDepositos, Deposito deposito[]);
void deletarDeposito(int* numDepositos, Deposito deposito[]);
void cadastrarNovoProduto(int numDepositos, int numProdutos, Produto produto[], Deposito deposito[]);
void consultarProduto(int numProdutos,Produto produto[]);
void consultarTodosProdutos(int numProdutos,Produto produto[]);
void atualizarDadosProduto(int numProdutos,Produto produto[],int numDepositos,Deposito deposito[]);
void excluirProduto(int numProdutos,Produto produto[]);

void exibirMenuInicial(int* menuInicial);
void exibirMenuDeposito(Deposito deposito[], int* numDepositos);
void exibirMenuProduto(Deposito deposito[], int numDepositos, Produto produto[], int* numProdutos);

int main() {
    int menuInicial = 4;
    int numDepositos = 0;
    int numProdutos = 0;

    Deposito deposito[MAX_DEPOSITO];
    Produto produto[MAX_PRODUTOS];

    while (menuInicial != 3) {
        exibirMenuInicial(&menuInicial);

        if (menuInicial == 1) {
            exibirMenuDeposito(deposito, &numDepositos);
        }
        else if (menuInicial == 2) {
            exibirMenuProduto(deposito, numDepositos, produto, &numProdutos);
        }
    }

    return 0;
}

void exibirMenuInicial(int* menuInicial) {
    printf("------  ALIFB -----------------------\n");
    printf("\n1 - Depósitos;\n2 - Produtos;\n3 - Sair do sistema.\n");
    //printf("\n--------------------------------------\n");
    scanf("%d", menuInicial);
}

void exibirMenuDeposito(Deposito deposito[], int* numDepositos) {
    int menuDeposito = 7;

    while (menuDeposito != 6) {
        printf("-----Menu Deposito -----------------------\n");
        printf("\n1 - Cadastrar depósito\n2 - Consultar informações sobre um depósito\n3 - Consultar informações sobre todos os depósitos\n4 - Atualizar dados de um depósito\n5 - Remover um depósito\n6 - Voltar ao menu principal\n");
        //printf("\n------------------------------------------\n");
        scanf("%d", &menuDeposito);

        if (menuDeposito == 1) {
            cadastrarDeposito(*numDepositos, deposito);
            (*numDepositos)++;
        }
        else if (menuDeposito == 2) {
            consultarDeposito(*numDepositos, deposito);
        }
        else if (menuDeposito == 3) {
            consultarTodosDepositos(*numDepositos, deposito);
        }
        else if (menuDeposito == 4) {
            atualizarDadosDeposito(*numDepositos, deposito);
        }
        else if (menuDeposito == 5) {
            deletarDeposito(numDepositos, deposito);
            (*numDepositos)--;
        }
    }
}

void exibirMenuProduto(Deposito deposito[], int numDepositos, Produto produto[], int* numProdutos) {
    int menuProduto = 7;

    while (menuProduto != 6) {
        printf("----  Menu Produto--------------\n");
        printf("\n1 - Cadastrar Produto\n2 - Consultar produto\n3 - Consultar todos os produtos\n4 - Alterar dados de um produto\n5 - Excluir produto\n6 - Voltar ao menu inicial\n");
        //printf("\n--------------------------------\n");
        scanf("%d", &menuProduto);

        if (menuProduto == 1 && *numProdutos < MAX_PRODUTOS) {
            cadastrarNovoProduto(numDepositos, *numProdutos, produto, deposito);
            (*numProdutos)++;
        }
        else if (menuProduto == 2) {
            consultarProduto(*numProdutos, produto);
        }
        else if (menuProduto == 3) {
            consultarTodosProdutos(*numProdutos, produto);
        }
        else if (menuProduto == 4) {
            atualizarDadosProduto(*numProdutos, produto, numDepositos, deposito);
        }
        else if (menuProduto == 5) {
            excluirProduto(*numProdutos, produto);
            (*numProdutos)--;
        }
    }
}
