#include "sgc.h"

void mostrarMenu(){
     
     printf("--------------------------------------------\n");
     printf("   Bem-vindo(a) ao mercadinho Pura Preguiça\n");
     printf("--------------------------------------------\n");
     printf("   O que deseja fazer em nosso sistema?\n");
     printf("   1. Entrar como Administrador\n");
     printf("   2. Entrar como Usuário Cnvencional\n");
     printf("   3. Sair\n");
 }
 
 void interacao(){
    int opcao, tam_estoque, tam_lista, sair = 0, tentativas = 0, chances = 3;

    struct Produto produto[MAX_PRODUTOS];
    struct Usuario usuario;

    do{
        printf("Escolha uma opção:\n");
        printf("1 - Acesso como Administrador\n");
        printf("2 - Acesso como Usuário\n");
        printf("3 - Sair\n");

        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("Acesso como Administrador:\n");
                menuAdmin(&usuario, produto, tam_lista);
                break;
            case 2:
                printf("Acesso como Usuário:\n");
                menuUsuario(&usuario, produto, tam_estoque, &tam_lista);
                break;
            case 3:
                printf("Agradeço por acessar nosso sistema, até!\n");
                exit(1);
            default:
                printf("Opção inválida, verifique novamente o Menu de Acesso.\n");
                break;
        }

        mostrarMenu();

    }while(opcao != 3);
}

 void menuAdmin(struct Usuario *usuario, struct Produto *produto, int tentativas){
     
     int tam_lista=0, tam_estoque=0, chances=3;
     char senhaADM[35];
     int acesso = 0;
     
    while(tentativas < chances && !acesso) {
    
    printf("Senha: ");
    scanf("%s", senhaADM);

    for (int i = 0; i < chances; i++) {
        
        if (strcmp(senhaADM, usuario[i].senha) == 0) {
            acesso = 1;
            interacaoAdmin(produto, usuario, &tam_estoque, &tam_lista);
            break;
        }
    }
        
    }else{
        
        tentativas++;
        int possibilidades = chances - tentativas;
        
        if (possibilidades > 0) {
            printf("Senha inválida, tens %d tentativas restantes\n", possibilidades);
        } else {
            printf("Não foi possível realizar o Login. Você será redirecionado para Menu Principal\n");
            mostrarMenu();
            return 0; // Sair da função se todas as tentativas se esgotaram
        }
        }
    }
 }
 
 void menuUsuario(struct Usuario *usuario, struct Produto *produto, int tam_estoque, int tam_lista){
     
     int id, tentativas = 0, chances = 3, userLocalizado = 0, acesso = 0;
     int possibilidades = 0;
     char senhaConvencional[35];
      
     usuario = (struct Usuario *)malloc(sizeof(struct Usuario));
     
     if(*tam_lista > 0){
         
         printf("Informe seu ID: ");
         scanf("%d", &id);
         
         for(int i=0; i<*tam; i++){
             if(id == usuario[i].idUsuario){
                 printf("Usuário encontrado.\n");
                 userLocalizado = 1;
                 
    while(tentativas < chances && !acesso) {
    
    printf("Senha: ");
    scanf("%s", senhaConvencional);

    for (int i = 0; i < chances; i++) {
        
        if (strcmp(senhaConvencional, usuario[i].senha) == 0) {
            acesso = 1;
            interacaoAdmin(produto, usuario, &tam_estoque, &tam_lista);
            break;
        }
    }
        
    }else{
        
        tentativas++;
        int possibilidades = chances - tentativas;
        
        if (possibilidades > 0) {
            printf("Senha inválida, tens %d tentativas restantes\n", possibilidades);
        } else {
            printf("Não foi possível realizar o Login. Você será redirecionado para Menu Principal\n");
            mostrarMenu();
            return 0; // Sair da função se todas as tentativas se esgotaram
        }
                    }
                }
            }
        }
    }
 }
 int main(void)
{
    mostrarMenu(); 
    return 0;
}
