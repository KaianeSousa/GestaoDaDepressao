#include "sgc.h"

void interacaoAdmin(struct Usuario *usuario, struct ListaProdutos *produto, int tam_lista) {
    int opc;

    printf("Olá, administrador %s\n", usuario[0].nomeUsuario);
    printf("-------------------------------------------\n");
    do {
        printf("O que deseja fazer?\n");
        printf(" 1 - Adicionar produto\n");
        printf(" 2 - Listar produtos em estoque\n");
        printf(" 3 - Cadastrar usuário\n");
        printf(" 4 - Excluir usuário\n");
        printf(" 5 - Listar pedidos\n");
        printf(" 6 - Sair\n");

        scanf("%d", &opc);

        switch (opc) {
            case 1:
                adicionarProduto(produto, tamEstoque);
                break;
            case 2:
                listarProdutos(produto, *tamEstoque);
                break;
            case 3:
                cadastrarUsuario(usuario, &tam_lista);
                break;
            case 4:
                excluirUsuario(usuario, &tam_lista);
                break;
            case 5:
                listarPedidos(Pedido, &tam_pedidos);
                break;
            case 6:
                printf("Retornando ao Menu Principal\n");
                return;
                break;
            default:
                printf("Leia novamente as alternativas, sua escolha está fora dos nossos padrões.\n");
                break;
        }
    } while (opc != 6);
}


    void adicionarProduto(struct Produto *produto, int *tamEstoque){
        
        struct Produto produtoAdc;
    
        printf("Iniciando operação para adicionar um produto ao estoque.\n");
    
        printf("Digite o nome do produto: ");
        scanf(" %[^\n]", produtoAdc.nomeProduto);
    
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &produtoAdc.quantidade);
    
        printf("Digite o preço unitário: ");
        scanf("%f", &produtoAdc.preco);
    
        printf("Digite o ID do produto: ");
        scanf("%d", &produtoAdc.idProduto);
    
        produto[(*tamEstoque)++] = produtoAdc;
    
        printf("Produto adicionado a lista com sucesso!\n");
    
        salvarProdutos(produto, tamanho);
}
    
    
void salvarProdutos(struct Produto *produto, int tamEstoque) {

    FILE *arquivo = fopen("produtos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os produtos.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "Nome: %s\n", produto[i].nomeProduto);
        fprintf(arquivo, "Quantidade: %d\n", produto[i].quantidade);
        fprintf(arquivo, "Preço: %.2f\n", produto[i].preco);
        fprintf(arquivo, "ID: %d\n", produto[i].idProduto);
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);

    printf("Produtos salvos com sucesso em 'produtos.txt'.\n");
}

        void listarProdutos(struct Produto *produto, int tamEstoque) {
          
            if(tamEstoque > 0){    
                printf("Lista de produtos no estoque:\n");
                
                for(int i = 0; i < tamEstoque; i++){
                    
                    printf(" Id: %d \n", produto[i].idProduto);
                    printf(" Nome: %s \n", produto[i].nomeProduto);
                    printf(" Quantidade em estoque: %d\n", produto[i].quantidade);
                    printf(" Preço Uni.: R$ %.2f\n", produto[i].preco);
                    printf("\n");
                }
            }else{
                printf("Estoque vazio.\n");
            }
           
        }
        
        
     void cadastrarUsuario(struct Usuario *usuario, int *tam_lista){
          if(*tam_lista < MAX_USUARIOS){
              
                struct Usuario novoUsuario;
                
                printf("Digite o nome de usuário: ");
                scanf(" %s", novoUsuario.nomeUsuario);
        
                printf("Digite a senha: ");
                scanf(" %s", novoUsuario.senha);
        
                int escolhaTipo;
                
                printf("Escolha o tipo de usuário (0 para ADMINISTRADOR, 1 para CONVENCIONAL): ");
                scanf("%d", &escolhaTipo);

        if(escolhaTipo == ADMINISTRADOR || escolhaTipo == CONVENCIONAL){
            novoUsuario.tipoUsuario = (enum tipoUsuario)escolhaTipo;

            srand(time(NULL));
            
            do{
                
                novoUsuario.idUser = rand(); 
                
            }while(numeroExistente(numerosGerados, *numerosGeradosSize, novoUsuario.idUser));

            numerosGerados[(*numerosGeradosSize)++] = novoUsuario.idUser;
            usuarios[(*tam_lista)++] = novoUsuario;

            printf("Usuário cadastrado com sucesso. ID do usuário: %d\n", novoUsuario.idUser);
            
            }else{
                
                printf("Tipo de usuário inválido. Usuário não criado.\n");
            }
                }else{
                    
                    printf("Limite de usuários atingido. Não é possível adicionar mais usuários.\n");
                }
    }

int numeroExistente(const int *numeros, int tamanho, int numero) {
    for(int i = 0; i < tamanho; i++){
        if(numeros[i] == numero){
            return 1;
        }
    }
    return 0;
}



void excluirUsuario(struct Usuario *usuario, int *tam_lista, int idUsuario) {
    int indiceExcluir = -1;

    for(int i = 0; i < *tam_lista; i++){
        if(usuario[i].idUser == idUsuario){
            indiceExcluir = i;
            break; 
        }
    }

    if(indiceExcluir != -1){

        for(int i = indiceExcluir; i < (*tam_lista - 1); i++){
            usuario[i] = usuario[i + 1];
        }
        
        (*tam_lista)--;
        
        printf("Usuário com ID %d foi excluído com sucesso.\n", idUser);
        
    }else{
        printf("Usuário com ID %d não foi encontrado. Nenhuma conta foi excluída.\n", idUser);
    }
}

 void listarPedidos(struct Produto *produto, int *tamEstoque, struct Usuario *usuario, int *tam_lista){
     
    int idCliente;
    
    printf("Digite o ID do cliente para listar os pedidos: ");
    scanf("%d", &idCliente);

    printf("Pedidos do cliente ID %d:\n", idCliente);

    for(int i = 0; i < *tam_lista; i++){
        
        if(usuario[i].idUser == idCliente){
            printf("Pedidos do cliente %s:\n", usuario[i].nomeUsuario);

            for (int j = 0; j < *tamEstoque; j++) {

                if (produto[j].idProduto == idCliente) {
                    printf(" -- Produto: %s\n", produto[j].nomeProduto);
                    printf(" -- Quantidade: %d\n", produto[j].quantidade);
                    printf(" -- Preço: R$ %.2f\n", produto[j].preco);
                    printf("\n");
                }
            }
        }
    }
 }



int main() {
    
 

    return 0;
}


