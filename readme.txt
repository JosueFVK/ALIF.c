# Sistema de Estoque - ALIFB

Este projeto consiste no desenvolvimento de um sistema de estoque para o aplicativo de compras ALIFB. O sistema permite armazenar informações sobre os produtos disponíveis para venda e os depósitos onde esses itens são armazenados. O sistema é capaz de realizar operações de criação, leitura, atualização e exclusão de produtos e depósitos, fornecendo um conjunto de funcionalidades para gerenciar o estoque.

## Funcionalidades do Sistema

O sistema oferece as seguintes funcionalidades:

### Menu Inicial

- Depósitos: Permite acessar as funcionalidades relacionadas aos depósitos.
- Produtos: Permite acessar as funcionalidades relacionadas aos produtos.
- Sair: Encerra o sistema.

### Menu Depósitos

- Cadastrar novo depósito: Permite cadastrar um novo depósito, fornecendo informações como nome, CEP, endereço, telefone e capacidade máxima.
- Consultar informações sobre um depósito: Exibe informações detalhadas sobre um depósito específico, como nome, CEP, endereço, telefone, capacidade total e a lista de produtos armazenados no depósito.
- Consultar informações sobre todos os depósitos: Exibe informações detalhadas sobre todos os depósitos cadastrados, incluindo os produtos armazenados em cada um deles.
- Atualizar dados de um depósito: Permite atualizar as informações de um depósito, como nome, CEP, endereço, telefone e capacidade máxima.
- Remover um depósito: Remove um depósito do sistema, desde que não possua nenhum item em estoque.

### Menu Produtos

- Cadastrar novo produto: Permite cadastrar um novo produto, fornecendo informações como nome, código de barras, categoria, data de fabricação, data de validade (se perecível), volume, quantidade e valor unitário. Também é necessário selecionar o depósito onde o produto será armazenado.
- Consultar produto: Permite consultar informações detalhadas sobre um produto específico, incluindo o depósito onde ele está armazenado, nome, código de barras, categoria, datas, volume, quantidade e valor unitário.
- Atualizar dados de um produto: Permite atualizar as informações de um produto, como nome, código de barras, categoria, datas, volume, quantidade e valor unitário.
- Remover produto: Remove um produto do sistema, atualizando a quantidade de itens no depósito correspondente.
- Transferir produto para outro depósito: Permite transferir um produto de um depósito para outro, fornecendo a quantidade de itens a serem transferidos e selecionando o depósito de destino.

## Estrutura Modular

O sistema está dividido em três módulos principais:

1. Módulo Principal: Este módulo contém a função `main` e é responsável por iniciar o sistema, exibir os menus iniciais e gerenciar as interações com o usuário. Ele chama os módulos de depósito e produtos quando necessário.

2. Módulo Depósito: Este módulo contém as funções relacionadas aos depósitos, incluindo a criação, consulta, atualização e remoção de depósitos. Também permite obter informações detalhadas sobre os depósitos e seus produtos armazenados.

3. Módulo Produtos: Este módulo contém as funções relacionadas aos produtos, incluindo a

 criação, consulta, atualização e remoção de produtos. Permite também transferir produtos entre depósitos.

O sistema utiliza a modularidade para facilitar a manutenção, extensibilidade e reutilização de código, tornando-o mais organizado e flexível.

## Observações

O sistema possui algumas regras e restrições importantes a serem observadas:

- O ALIFB pode ter no máximo 5 depósitos.
- O nome do depósito e o endereço devem ter no máximo 50 caracteres.
- O CEP deve seguir o formato XXXXX-XXX, com cinco números seguidos de um traço e mais três números.
- A capacidade máxima de um depósito deve ser maior que o estoque atual.
- O sistema impede o registro de produtos com data de fabricação anterior à sua própria data de uso.
- Um depósito pode armazenar no máximo 100 produtos diferentes.
- Antes de cadastrar um produto, é necessário ter pelo menos um depósito cadastrado.

O sistema de estoque ALIFB oferece um conjunto abrangente de funcionalidades para gerenciar produtos e depósitos de forma eficiente.

#Compilar

Para compilar o codigo abra o terminal Linux e digite "make all' , em seguido execute o arquivo executavel "main".

##Requisitos
-Sistema operacional Linux com um compilador GCC

##Autores
Ingrid Cristina Pereira da Silva
Josue Felipe Vieira Klich
