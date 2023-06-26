#ifndef estrutura_h
#define estrutura_h


#define MAX_NOME 50
#define MAX_CEP 9
#define MAX_CODIGO_BARRAS 13
#define MAX_DATAS 11


 struct perecivel{
    char dataFabricacao[MAX_DATAS];
    char dataValidade[MAX_DATAS];
};

struct nao_perecivel{
    char dataFabricacao[MAX_DATAS];
};

typedef struct Deposito{
    char nome[MAX_NOME];
    char cep[9];
    char bug[10];
    char telefone[MAX_NOME];
    float capacidade;
    float estoque;
    char endereco[50];
}Deposito;

typedef struct Produto{
        char nome[MAX_NOME];
        char codigoBarras[MAX_CODIGO_BARRAS];
        int categoria;
        int opcao;
        int validade;  //0- NÃO PERECIVEL || 1- PERCIVEL
        float volume;
        int quantidade;
        float valorUnitario;
        char cepDepositado[MAX_CEP];

    union{ 
        struct nao_perecivel nao_perecivel_info;
        struct perecivel perecivel_info;

    }validade_info;

}Produto;



 
#endif