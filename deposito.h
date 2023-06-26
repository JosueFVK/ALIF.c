#ifndef deposito_h
#define deposito_h

#include "estrutura.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarDeposito(int numDepositos, Deposito deposito[]);
void consultarDeposito(int numDepositos,Deposito deposito[]);
void consultarTodosDepositos(int numDepositos,Deposito deposito[]);
void atualizarDadosDeposito(int numDepositos,Deposito deposito[]);
void deletarDeposito(int* numDepositos, Deposito deposito[]);

#endif
