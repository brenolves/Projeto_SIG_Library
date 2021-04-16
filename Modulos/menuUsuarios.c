#include <stdio.h>
#include <stdlib.h>
#include "clearscr.h"
#include "moduloValida.h"
#include "telas.h"

// Módulo Usuários

char menuUsuarios(void) {
    char opMenu;
        
    clearscr();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                             Menu Usuarios                               |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                    |#| 1 - Cadastrar um usuario                         |||\n");
    printf("|||                    |#| 2 - Pesquisar um usuario                         |||\n");
    printf("|||                    |#| 3 - Atualizar cadastro de um usuario             |||\n");
    printf("|||                    |#| 4 - Excluir cadastro de um usuario               |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                             0 - Menu Anterior                           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
    scanf("%[0-9]", &opMenu);
    getchar();


    return opMenu;
}

// Cadastros

void cadastroUsuarios(void) {
    Usuario* user;
    int tentar = 0;

    // Checar se existe memória disponível.
    do{
        user = (Usuario*) malloc(sizeof(Usuario));
        if (user == NULL) {
            tentar = memoriaAlocada();
        }
    } while(tentar == 1);

    user = tela_CadUsuario(user);
    guardarUsuario(user);
    free(user);
    
}

Usuario* tela_CadUsuario(Usuario* user) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                          Cadastrar Usuarios                             |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Nome do usuário: ");

        do {
            scanf(" %50[^\n]", user->usuarioNome);
            getchar();
        }while (!testaNome(user->usuarioNome));

        printf("                                                                            |||\n");
        printf("|||                    |:| Data de nascimento do usuário(dd/mm/aaaa): ");

        do {
            scanf(" %10[^\n]", user->usuarioDataNasc);
            getchar();
        }while (!testaDataNasc(user->usuarioDataNasc));

        printf("                                                                            |||\n");
        printf("|||                    |:| CPF do usuário (Somente números): ");

        do{
            scanf(" %11[^\n]", user->usuarioCPF);
            getchar();
        }while (!testaCPF(user->usuarioCPF));

        printf("                                                                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        user->status = '1';

        mcadastroUsuario(user);

        return user;
}

// Pesquisas

char pesquisaUsuarios(void) {
    char opMenu;
        
    clearscr();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                         Pesquisa de Usuários                            |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                     Deseja pesquisar por:                               |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                    |:| 1 - Nome do usuário                              |||\n");
    printf("|||                    |:| 2 - Data de nascimento do usuário                |||\n");
    printf("|||                    |:| 3 - Codigo do usuário                            |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                             0 - Menu Anterior                           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
    scanf("%[0-9]", &opMenu);
    getchar();
        

    return opMenu;
}

char pesquisaUsuarios_Nome(void) {
    Usuario* user;
    user = (Usuario*) malloc(sizeof(user->usuarioNome));
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Pesquisa de Usuários                          |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                      Pesquisa por nome:                                 |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Nome do usuário:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        do{
            scanf("%50[^\n]", user->usuarioNome);
            getchar();
        }while (!testaNome(user->usuarioNome));
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

       // return nomeUsuario;  
}

char pesquisaUsuarios_Nasc(void) {
    char nascUsuario[11];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Pesquisa de Usuários                          |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                      Pesquisa por data de nascimento:                   |||\n");
        printf("|||                                                                         |||\n");
        printf("|||      |:| Data de nascimento do usuário:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[^\n]", nascUsuario);
        getchar();
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

       // return nascUsuario;  
}

int pesquisaUsuarios_Codigo(void) {
    int codigoUsuario;
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Pesquisa de Usuários                          |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por código:                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                  |:| Código do usuário:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%i", &codigoUsuario);
        getchar();
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      //  return codigoUsuario;  
}

// Atualizações

char atualizaUsuarios(void) {
    char opMenu;
        
    clearscr();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                      Atualizar cadastro de Usuários                     |||\n");
    printf("|||                                                                         |||\n");
    printf("|||     Deseja pesquisar o usuário a ser atualizado por:                    |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                    |:| 1 - Nome do usuário                              |||\n");
    printf("|||                    |:| 2 - Data de nascimento do usuário                |||\n");
    printf("|||                    |:| 3 - Codigo do usuário                            |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                             0 - Menu Anterior                           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
    scanf("%[0-9]", &opMenu);
    getchar();
        

    return opMenu;
}

char atualizaUsuarios_Nome(void) {
    char nomeUsuario[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Atualizar Usuários                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por nome:                                  |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Nome do usuário:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[^\n]", nomeUsuario);
        getchar();
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      //  return nomeUsuario;  
}

char atualizaUsuarios_Nasc(void) {
    char nascUsuario[11];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Atualizar Usuários                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                  Pesquisa por data de nascimento:                       |||\n");
        printf("|||                                                                         |||\n");
        printf("|||      |:| Data de nascimento do usuário:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[^\n]", nascUsuario);
        getchar();
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      //  return nascUsuario;  
}

int atualizaUsuarios_Codigo(void) {
    int codigoUsuario;
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Atualizar Usuários                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por código:                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                  |:| Código do usuário:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%i", &codigoUsuario);
        getchar();
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

     //   return codigoUsuario;  
}

// Exclusões

char excluirUsuarios(void) {
    char opMenu;
        
    clearscr();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                      Excluir cadastro de Usuários                       |||\n");
    printf("|||                                                                         |||\n");
    printf("|||     Deseja pesquisar o usuário a ser excluido por:                      |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                    |:| 1 - Nome do usuário                              |||\n");
    printf("|||                    |:| 2 - Data de nascimento do usuário                |||\n");
    printf("|||                    |:| 3 - Codigo do usuário                            |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                             0 - Menu Anterior                           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
    scanf("%[0-9]", &opMenu);
    getchar();
        

    return opMenu;
}

char excluirUsuarios_Nome(void) {
    char nomeUsuario[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Excluir Usuários                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                       Pesquisa por nome:                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Nome do usuário:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[^\n]", nomeUsuario);
        getchar();
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      //  return nomeUsuario;  
}

char excluirUsuarios_Nasc(void) {
    char nascUsuario[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Excluir Usuários                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||         Pesquisa por data de nascimento:                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||      |:| Data de nascimento do usuário:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[^\n]", nascUsuario);
        getchar();
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      //  return nascUsuario;  
}

int excluirUsuarios_Codigo(void) {
    int codigoUsuario;
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Excluir Usuários                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                       Pesquisa por código:                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                  |:| Código do usuário:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%i", &codigoUsuario);
        getchar();
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      //  return codigoUsuario;  
}


void guardarUsuario(Usuario* user) {
	FILE* arq;

	arq = fopen("usuarios.dat", "ab");
	if (arq == NULL) {
		arq_msgErro();
	}
	fwrite(user, sizeof(Usuario), 1, arq);
	fclose(arq);
}