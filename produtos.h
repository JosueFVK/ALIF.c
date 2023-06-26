#ifndef produtos_h
#define produtos_h

#include "estrutura.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearInputBufferProduto();
void cadastrarNovoProduto(int numDepositos,int numProdutos,Produto produto[],Deposito deposito[]);
void consultarProduto(int numProdutos,Produto produto[]);
void consultarTodosProdutos(int numProdutos,Produto produto[]);
void atualizarDadosProduto(int numProdutos,Produto produto[],int numDepositos,Deposito deposito[]);
void excluirProduto(int numProdutos,Produto produto[]);

#endif
