#ifndef SGC_H
#define SGC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_USER 1500
#define MAX_TAM_PASS 100
#define MAX_USUARIOS 50
#define MAX_PRODUTOS 1100
#define MAX_NAME_PROD 1100

enum tipoUsuario {
    ADMINISTRADOR, CONVENCIONAL
};

struct Produto {
    char nomeProduto[MAX_NAME_PROD];
    int idProduto;
    int quantidade;
    float preco;
};

struct Pedido {
    int idPedido;
    float total;
};

struct Usuario {
    char nomeUsuario[MAX_NAME_USER];
    char senha[MAX_TAM_PASS];
    int idUser;
    enum tipoUsuario tipoUsuario;
};


struct ListaProdutos {
    struct Produto produtos[MAX_PRODUTOS];
    int tamEstoque;
};



//Funções da main
    void mostrarMenu();
    void interacao();
    void menuAdmin(struct Usuario *usuario, struct Produto *produto, int tentativas);
    void menuUsuario(struct Usuario *usuario, struct Produto *produto, int tam_estoque, int tam_lista);
    
//Funções do usuário Administrador

    void interacaoAdmin(struct Usuario *usuario, struct Produto *produto, int tam_estoque, int tam_lista);
    void adicionarProduto(struct Produto *produto, int *tamEstoque);
    void salvarProdutos(struct Produto *produto, int tamEstoque);
    void listarProdutos(struct Produto *produto, int tamEstoque);
    void cadastrarUsuario(struct Usuario *usuario, int *tam_lista);
    int numeroExistente(const int *numeros, int tamanho, int numero);
    void excluirUsuario(struct Usuario *usuario, int *tam_lista);
    void listarPedidos(struct Produto *produto, int *tam_estoque, struct Usuario *usuario, int *tam_lista);


//Funções do usuário Convencional 

    void interacaoUsuario(struct Produto *produto, struct Usuario *usuario, int *tam_estoque, int *tam_lista);
    void pedidos(struct Produto *produto, int *tamanho);
    void listarPedidos();

#endif
