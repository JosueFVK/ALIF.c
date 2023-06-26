#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "produtos.h"
#include "deposito.h"


#define MAX_PRODUTOS 100
#define MAX_DEPOSITO 5


void clearInputBufferProduto() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int validaData(char data[9]){
    int tamanho = strlen(data);

    if(tamanho != 8){
        return 1;
    }

    for(int i = 0; i<tamanho-1;i++){
        if(i == 2){
            if(data[i] == '/'){
                    if(data[i+3]=='/'){
                    return 0;
                        } else{
                            if(!isdigit(data[i])){
                            return 1;
                    }
                }
            }else{
                if(!isdigit(data[i])){
                    puts("entrou");
                    return 1;
                }
            }
        }
    }
    return 1;
}

void cadastrarNovoProduto(int numDepositos,int numProdutos,Produto produto[],Deposito deposito[]){
     if(numDepositos == 0){
           printf("Nenhum depósito cadastrado. Cadastre um depósito primeiro!\n");
           return;
       }

       if(numProdutos == MAX_PRODUTOS){
           printf("Limite máximo de produtos cadastrado atingido!\n");
           return;
       }

    Produto Novoproduto;

    printf("Nome do produto: ");
    scanf(" %[^\n]s", Novoproduto.nome);
    getchar();


     printf("Código de barras (12 dígitos): ");
    scanf(" %[^\n]s", Novoproduto.codigoBarras);
    getchar();

    printf("Categoria de produto: \n");
    printf("1. Eletrônicos\n");
    printf("2. Moda e Vestuário\n");
    printf("3. Casa e Decoração\n");
    printf("4. Beleza e Cuidados Pessoais\n");
    printf("5. Esportes e Lazer\n");
    printf("6. Livros e Música\n");
    printf("7. Automotivo\n");
    printf("8. Saúde e Bem-estar\n");
    printf("9. Brinquedos e Jogos\n");
    printf("10. Alimentos e Bebidas\n");
    printf("Opção: ");
    scanf(" %d",&(Novoproduto.opcao));
    getchar();

    int verifica =1;
    printf("O produto é perecivel ? 1-sim||0-Não\n");
    scanf(" %d", &Novoproduto.validade);
    getchar();
    if (Novoproduto.validade == 1){
        
        printf("Data de Fabricação(xx/xx/xx):  \n");
        scanf(" %s", Novoproduto.validade_info.perecivel_info.dataFabricacao);
        getchar();
         while (verifica != 0) {
        verifica = validaData(Novoproduto.validade_info.perecivel_info.dataFabricacao);
        if (verifica == 0) {
            break;
        }

        printf("Data Invalida digite novamenete:  ");
        scanf("%s", Novoproduto.validade_info.perecivel_info.dataFabricacao);
        clearInputBufferProduto();
    }


        printf("Data de Vencimento:(xx/xx/xx): \n");
        scanf(" %s", Novoproduto.validade_info.perecivel_info.dataValidade);
        getchar();
         while (verifica != 0) {
        verifica = validaData(Novoproduto.validade_info.perecivel_info.dataValidade);
        if (verifica == 0) {
            verifica=1;
            break;
        }

        printf("Data Invalida digite novamenete:  ");
        scanf("%s", Novoproduto.validade_info.perecivel_info.dataValidade);
        clearInputBufferProduto();
    }

    }else {
                printf("Data de Fabricação:(xx/xx/xx): \n");
        scanf(" %s", Novoproduto.validade_info.nao_perecivel_info.dataFabricacao);
        getchar();
         while (verifica != 0) {
        verifica = validaData(Novoproduto.validade_info.nao_perecivel_info.dataFabricacao);
        if (verifica == 0) {
            break;
        }

        printf("Data Invalida digite novamenete:  ");
        scanf("%s", Novoproduto.validade_info.nao_perecivel_info.dataFabricacao);
        clearInputBufferProduto();
    }


    }
    

printf("Volume (em metros cúbicos): ");
    scanf(" %f", &Novoproduto.volume);
    getchar();
    

    printf("Quantidade: ");
    scanf(" %d", &Novoproduto.quantidade);
    getchar();
   

    printf("Valor Unitário: ");
    scanf(" %f", &Novoproduto.valorUnitario);
    getchar();
  

    printf("CEP do depósito: ");
    scanf(" %s", Novoproduto.cepDepositado);
    getchar();

       int i;
      for (i = 0; i < numDepositos; i++) {
          if (strcmp(deposito[i].cep, Novoproduto.cepDepositado) == 0) {
              if (deposito[i].estoque + Novoproduto.volume <= deposito[i].capacidade) {
                  produto[numProdutos] = Novoproduto;
                  numProdutos++;
                  deposito[i].estoque += Novoproduto.volume;

                  printf("Novoproduto cadastrado com sucesso.\n\n");
              } else {
                  printf("Não há espaço suficiente no depósito para armazenar o Novoproduto.\n\n");
              }
              return;
          }
      }

      printf("Depósito não encontrado.\n\n");
}

void consultarProduto(int numProdutos,Produto produto[]){
    //não esta encontrando o produto
    char codigo[12];
    printf("Digite o código de barras do produto: ");
    scanf(" %s", codigo);
    getchar();
  

    for(int i=0;i<numProdutos;i++){
        if(strcmp(produto[i].codigoBarras,codigo)==0){
           printf("\n----- Produto %d -----\n",i+1);
        printf("Nome: %s\n",produto[i].nome);
        printf("Código de barras: %s\n",produto[i].codigoBarras);
        
    if(produto[i].opcao==1){
        printf("CATEGORIA: ELETRONICOS\n");
    }
     if(produto[i].opcao==2){
        printf("CATEGORIA: Moda e Vestuário\n");
    }
     if(produto[i].opcao==3){
        printf("CATEGORIA: Casa e Decoração");
    }
     if(produto[i].opcao==4){
        printf("CATEGORIA: Beleza e Cuidados Pessoais");
    }
     if(produto[i].opcao==5){
        printf("CATEGORIA: Esportes e Lazer");
    }
     if(produto[i].opcao==6){
        printf("CATEGORIA: Livros e Música");
    }
     if(produto[i].opcao==7){
        printf("CATEGORIA: Automotivo");
    }
     if(produto[i].opcao==8){
        printf("CATEGORIA: Saúde e Bem-estar");
    }
     if(produto[i].opcao==9){
        printf("CATEGORIA: Brinquedos e Jogos");
    }
     if(produto[i].opcao==10){
        printf("CATEGORIA: Alimentos e Bebidas");
    } //CATEGORIA NÃO ESTA IMPRIMINDO O TIPO DA CATEGORIA 
        if (produto[i].validade==1)
        {
            printf("Fabricado: %s\n",produto[i].validade_info.perecivel_info.dataFabricacao);
            printf("Validade: %s\n",produto[i].validade_info.perecivel_info.dataValidade);
        }else {printf("Fabricado: %s\n",produto[i].validade_info.nao_perecivel_info.dataFabricacao);}
        
        printf("Volume: %.2f\n",produto[i].volume);
        printf("Quantidade: %d\n",produto[i].quantidade);
        printf("Valor: %.2f\n",produto[i].valorUnitario); 
        printf("CEP do depósito: %s\n\n",produto[i].cepDepositado);
            return;
        }
    }

    printf("Produto não encontrado!\n\n");
}

void consultarTodosProdutos(int numProdutos,Produto produto[]){
    if(numProdutos == 0){
        printf("\nNenhum produto cadastrado!\n\n");
        return;
    }

    for(int i=0;i<numProdutos;i++){
        printf("\n----- Produto %d -----\n",i+1);
        printf("Nome: %s\n",produto[i].nome);

    if(produto[i].opcao==1){
        printf("CATEGORIA: ELETRONICOS\n");
    }
     if(produto[i].opcao==2){
        printf("CATEGORIA: Moda e Vestuário\n");
    }
     if(produto[i].opcao==3){
        printf("CATEGORIA: Casa e Decoração");
    }
     if(produto[i].opcao==4){
        printf("CATEGORIA: Beleza e Cuidados Pessoais");
    }
     if(produto[i].opcao==5){
        printf("CATEGORIA: Esportes e Lazer");
    }
     if(produto[i].opcao==6){
        printf("CATEGORIA: Livros e Música");
    }
     if(produto[i].opcao==7){
        printf("CATEGORIA: Automotivo");
    }
     if(produto[i].opcao==8){
        printf("CATEGORIA: Saúde e Bem-estar");
    }
     if(produto[i].opcao==9){
        printf("CATEGORIA: Brinquedos e Jogos");
    }
     if(produto[i].opcao==10){
        printf("CATEGORIA: Alimentos e Bebidas");
    }
        
    
        if (produto[i].validade==1)
        {
            printf("Fabricado: %s\n",produto[i].validade_info.perecivel_info.dataFabricacao);
            printf("Validade: %s\n",produto[i].validade_info.perecivel_info.dataValidade);
        }else {printf("Fabricado:  %s\n",produto[i].validade_info.nao_perecivel_info.dataFabricacao);}
        
        printf("Volume: %.2f\n",produto[i].volume);
        printf("Quantidade: %d\n",produto[i].quantidade);
        printf("Valor: %.2f\n",produto[i].valorUnitario);
        printf("CEP do depósito: %s\n\n",produto[i].cepDepositado);
    }
}

void atualizarDadosProduto(int numProdutos,Produto produto[],int numDepositos,Deposito deposito[]){
    char codigoBarras[MAX_CODIGO_BARRAS];
    int opcao;
    printf("Digite o código de barras do produto: ");
    scanf("%s", codigoBarras);
    getchar();

    int i;
    for (i = 0; i < numProdutos; i++) {
        if (strcmp(produto[i].codigoBarras, codigoBarras) == 0) {

            do {
                printf("Selecione o dado a ser atualizado:\n");
                printf("1. Nome do Produto\n");
                printf("2. Código de Barras\n");
                printf("3. Categoria\n");
                printf("4. Data de Fabricação/validade\n");
                printf("5. Volume\n");
                printf("6. Quantidade\n");
                printf("7. Valor Unitário\n");
                printf("8. CEP do Depósito\n");
                printf("9. Voltar ao menu Produto\n");
                printf("Opção: ");
                scanf("%d", &opcao);
                clearInputBufferProduto();

            
                    if(opcao==1){
                        printf("Novo nome do Produto: ");
                        scanf("%s", produto[i].nome);
                        getchar();
                        printf("Nome do Produto atualizado com sucesso.\n");
                        break;
                    }
                    if(opcao==2){
                        printf("Novo Código de Barras: ");
                        scanf("%s", produto[i].codigoBarras);
                        getchar();
                        printf("Código de Barras atualizado com sucesso.\n");
                        break;
                    }
                    if(opcao==3){
                        printf("Nova Categoria de produto: \n");
                        printf("1. Eletrônicos\n");
                        printf("2. Moda e Vestuário\n");
                        printf("3. Casa e Decoração\n");
                        printf("4. Beleza e Cuidados Pessoais\n");
                        printf("5. Esportes e Lazer\n");
                        printf("6. Livros e Música\n");
                        printf("7. Automotivo\n");
                        printf("8. Saúde e Bem-estar\n");
                        printf("9. Brinquedos e Jogos\n");
                        printf("10. Alimentos e Bebidas\n");
                        printf("Opção: ");
                        int opcaoCategoria;
                        scanf(" %d", &opcaoCategoria);
                        produto[i].opcao=opcaoCategoria;
                        getchar();
                       
                        printf("Categoria de produto atualizada com sucesso.\n");
                        break;
                    }
                    if(opcao==4) {
                        if (produto[i].validade==1){
                            printf("Nova Data de Fabricação (dd/mm/aaaa): ");
                            scanf("%s", produto[i].validade_info.perecivel_info.dataFabricacao);
                            getchar();
                            printf("Nova Data de validade (dd/mm/aaaa): ");
                            scanf("%s", produto[i].validade_info.perecivel_info.dataValidade);
                            getchar();
                            printf("Data de Fabricação atualizada com sucesso.\n");
                            break;

                    } 
                        
                        printf("Nova Data de Fabricação (dd/mm/aaaa): ");
                        scanf("%s", produto[i].validade_info.nao_perecivel_info.dataFabricacao);
                        getchar();
                        printf("Data de Fabricação atualizada com sucesso.\n");
                        break;
                    }
                    if(opcao==5){
                        printf("Novo Volume (em metros cúbicos): ");
                        scanf("%f", &produto[i].volume);
                        getchar();
                        printf("Volume atualizado com sucesso.\n");
                        break;
                    }
                    if(opcao==6){
                        printf("Nova Quantidade: ");
                        scanf("%d", &produto[i].quantidade);
                        getchar();
                        printf("Quantidade atualizada com sucesso.\n");
                        break;
                    }
                    if(opcao==7) {
                        printf("Novo Valor Unitário: ");
                        scanf("%f", &produto[i].valorUnitario);
                        getchar();
                        printf("Valor Unitário atualizado com sucesso.\n");
                        break;
                    }
                    if(opcao==8){
                        printf("Novo CEP do depósito: ");
                        scanf("%s", produto[i].cepDepositado);
                        getchar();
                         int j;
                            for (j = 0; j < numDepositos; j++) {
                                    if (strcmp(deposito[j].cep,produto[i].cepDepositado) == 0) {
                                         if (deposito[j].estoque + produto[i].volume <= deposito[j].capacidade) {
                                                deposito[j].estoque += produto[i].volume;

                                         printf("CEP do depósito atualizado com sucesso.\n\n");
                                         return;
              } else {
                  printf("Não há espaço suficiente no depósito para armazenar o Novoproduto.\n\n");
              }
              return;
          }
      }
       printf("Depósito não encontrado.\n\n");
                    }
                    if(opcao==9){
                        printf("Opção inválida. Tente novamente.\n");
                        break;
                    }

            } while (opcao != 10);

            return;
        }
    }

    printf("\nProduto não encontrado.\n");
}

void excluirProduto(int numProdutos,Produto produto[]){
    char codigoBarras[MAX_CODIGO_BARRAS];
    printf("Digite o código de barras do produto: ");
    scanf(" %s", codigoBarras);
    getchar();

    int i;
    for (i = 0; i < numProdutos; i++) {
        if (strcmp(produto[i].codigoBarras, codigoBarras) == 0) {
            int j;
            for (j = i; j < numProdutos - 1; j++) {
                produto[j] = produto[j + 1];
            }
            numProdutos--;
            printf("Produto excluído com sucesso.\n");
            return;
        }
    }

    printf("Produto não encontrado.\n");
}