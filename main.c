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
    struct Usuario *usuario = (struct Usuario *)malloc(sizeof(struct Usuario) * tam_lista);
    
    strcpy(usuario[0].nomeUsuario, "Kaiane");
    strcpy(usuario[0].senha, "3333");
    usuario[0].tipoUsuario = ADMINISTRADOR;
    
        do {
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuAdmin(usuario, produto, tentativas);
                break;
            case 2:
                menuUsuario(usuario, produto, tam_estoque, &tam_lista);
                break;
            case 3:
                printf("Agradeço por acessar nosso sistema, até!\n");
                exit(1);
            default:
                printf("Opção inválida, as opções disponíveis são apenas 1, 2 e 3.\n");
                break;
        }
        
        mostrarMenu();
        
    }while (opcao != 3);
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
            return 0;
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
            return 0;
        }
                    }
                }
            }
        }
    }
 }
 
int main()
{

    return 0;
}

