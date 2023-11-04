#ifndef SGC_H
#define SGC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_USER 1500
#define MAX_USUARIOS 50
#define MAX_TAM_PASS 100
#define MAX_PRODUTOS 50
#define MAX_NAME_PROD 1100

    enum tipoUsuario{
        ADMINISTRADOR, USER_CONVENCIONAL
    };
    
    struct Produto{
        char nomeProduto[MAX_NAME_PROD];
        int idProduto;
        int quantidade;
        float preco;
        
    };

    struct Pedido{
        int idPedido;
        int quantidade;
        float total;
    };
    
    struct Usuario{
        char nomeUsuario[MAX_NAME_USER];
        int idUsuario;
        char senhaUsuario[MAX_TAM_PASS];
        enum tipoUsuario tipoUsuario;
    };

    struct Administrador{
        char nomeAdm[MAX_NAME_USER];
        int idUAdm;
        char senhaAdm[MAX_TAM_PASS];
        enum tipoUsuario tipoUsuario;
    };

//Funções da main
    void mostrarMenu();
    void interacao();
    void menuAdmin(struct Usuario *usuario, struct Produto *produto, int tentativas);
    void menuUsuario(struct Usuario *usuario, struct Produto *produto, int tam_estoque, int tam_lista);
    
//Funções do usuário Administrador

    void interacaoAdmin(struct Usuario *usuario, struct Produto *produto, int tam_estoque, int tam_lista);
    void adicionarProduto(struct Produto *produto, int *tam_estoque);
    void listarProdutos(struct Produto *produto, int tam_estoque);
    void cadastrarUsuario(struct Usuario *usuario, int *tam_lista);
    void excluirUsuario(struct Usuario *usuario, int *tam_lista);
    void mostrarDados(struct Produto *produto, int *tam_estoque, struct Usuario *usuario, int *tam_lista);


//Funções do usuário Convencional 

    void interacaoUsuario(struct Produto *produto, struct Usuario *usuario, int *tam_estoque, int *tam_lista);
    void pedidos(struct Produto *produto, int *tamanho);
    void listarPedidos();

#endif
