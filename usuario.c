#include "sgc.h"
    

    void interacaoUsuario(struct Produto *produto, struct Usuario *usuario, int *tamEstoque, int *tam_lista){
        int opcao;
        
        printf("Usuário, o que deseja fazer nesse humilde sistema?\n");
        printf("-----------------------------------------------------\n");
        
        do{
            
        printf(" 1 - Fazer pedidos\n");
        printf(" 2 - Listar estoque\n");
        printf(" 3 - Sair do sistema\n");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                pedidosProdutos(produto, tamEstoque);
                break;
                
            case 2:
                exibirProdutosEstoque();
                break;
                
            case 3:
                printf("Agradecemos pela sua preferência, até!\n");
                return;
                break;
                
            default:
            printf("Opção inválida, leia novamente as opções fornecidas.\n");
        }
            
        }while(opcao != 3);
        
    }
    

void pedidosProdutos(struct Produto *produto, int *tamEstoque){
    
    char nomePedido[MAX_NAME_PROD];
    int quantidadePedido;

    printf("Digite o nome do produto que deseja pedir: ");
    scanf(" %[^\n]", nomePedido);


    int encontrado = 0;
    int indice = -1;
    
    for (int i = 0; i < *tamEstoque; i++){
        
        if (strcmp(nomePedido, produto[i].nomeProduto) == 0) {
            encontrado = 1;
            indice = i;
            break;
        }
    }

    if(encontrado){
        
        printf("Digite a quantidade desejada: ");
        scanf("%d", &quantidadePedido);


        if (quantidadePedido <= produto[indice].quantidade) {

            printf("Pedido de %d unidades de %s realizado com sucesso.\n", quantidadePedido, nomePedido);

            listarCompras(nomePedido, quantidadePedido);
        } else {
            printf("Desculpe, não há quantidade suficiente em estoque.\n");
        }
    } else {
        printf("Produto não encontrado no estoque.\n");
    }
}

void listarCompras(const char *nomePedido, int quantidadePedido) {

    FILE *arquivo = fopen("compras.txt", "a"); 

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os pedidos.\n");
        return;
    }

    fprintf(arquivo, "Produto: %s | Quantidade: %d\n", nomePedido, quantidadePedido);


    fclose(arquivo);

    printf("Pedido armazenado com sucesso.\n");
}


void exibirProdutosEstoque(){
    FILE *arquivo = fopen("estoque.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo 'estoque.txt'.\n");
        return;
    }

    printf("Lista de produtos disponíveis no estoque:\n");

    char linha[MAX_NAME_PROD];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
}


int main(){
    
    struct Produto estoque[MAX_PRODUTOS];
    struct Usuario usuario[MAX_USUARIOS];
    int tamEstoque = 0;
    int tam_lista = 0;

    interacaoUsuario(estoque, usuario, &tamEstoque, &tam_lista);

    exibirProdutosEstoque();
    
    return 0;
}
