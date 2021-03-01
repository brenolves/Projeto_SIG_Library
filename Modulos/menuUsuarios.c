#include <stdio.h>
#include <stdlib.h>
#include "siglibrary.h"

// Módulo Usuários
char menuUsuarios(void);
    void cadastroUsuarios(void);
    void pesquisaUsuarios(void);
    void atualizaUsuarios(void);
    void excluirUsuarios(void);

char menuUsuarios(void) {
    char opMenu2;
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
        printf("|||        5 - Menu Principal           |:|          0 - Encerrar           |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        scanf("%[0-9]", &opMenu2);
        getchar();

        return opMenu2;
}

void cadastroUsuarios(void) {
    char usuarioNome[51];
    char usuarioDataNasc[11];
    char usuarioCodigo[9];
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
        printf("|||                    |:| Nome do usuário:                                 |||\n");
        printf("|||                                         ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", usuarioNome);
        getchar();
        printf("|||                    |:| Data de nascimento do usuário:                   |||\n");
        printf("|||                                                       ");
        scanf("%[0-9/]", usuarioDataNasc);
        getchar();
        printf("|||                    |:| Codigo do usuário:                               |||\n");
        printf("|||                                           ");
        scanf("%[0-9]", usuarioCodigo);
        getchar();
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void pesquisaUsuarios(void) {
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
        printf("|||        5 - Menu Usuários          |:|          0 - Encerrar             |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Escolha sua opção:  \n");
        scanf("%[0-9]", &opMenu);
        getchar();
}

void atualizaUsuarios(void) {
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
        printf("|||        5 - Menu Usuários          |:|          0 - Encerrar             |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Escolha sua opção:  \n");
        scanf("%[0-9]", &opMenu);
        getchar();
}

void excluirUsuarios(void) {
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
        printf("|||        5 - Menu Usuários          |:|          0 - Encerrar             |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Escolha sua opção:  \n");
        scanf("%[0-9]", &opMenu);
        getchar();
}

char menuEmprestimos(void) {
    char opMenu3;
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Menu Empréstimos                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |#| 1 - Efetuar um empréstimo                        |||\n");
        printf("|||                    |#| 2 - Pesquisar um empréstimo                      |||\n");
        printf("|||                    |#| 3 - Atualizar dados de um empréstimo             |||\n");
        printf("|||                    |#| 4 - Finalizar um empréstimo                      |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Principal           |:|          0 - Encerrar           |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        scanf("%[0-9]", &opMenu3);
        getchar();

        return opMenu3;
}

void efetuarEmprestimos(void) {
    char emprestimoNome[51];
    char emprestimoLivro[30];
    char emprestimoData[11];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                          Efetuar Empréstimo                             |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Nome do usuário:                                 |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", emprestimoNome);
        getchar();
        printf("|||                    |:| Livro do empréstimo:                             |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ0-9]", emprestimoLivro);
        getchar();
        printf("|||                    |:| Período de empréstimo(Data de vencimento):       |||\n");
        scanf("%[0-9/]", emprestimoData);
        getchar();
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void pesquisaEmprestimos(void) {
    char opMenu;
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                        Pesquisa de Empréstimos                          |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Deseja pesquisar por:                               |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| 1 - Nome do usuário                              |||\n");
        printf("|||                    |:| 2 - Livros em empréstimos                        |||\n");
        printf("|||                    |:| 3 - Período de empréstimo                        |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Empréstimos         |:|         0 - Encerrar            |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Escolha sua opção:  \n");
        scanf("%[0-9]", &opMenu);
        getchar();
}

void atualizaEmprestimos(void) {
    char opMenu;
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                         Atualizar Empréstimos                           |||\n");
        printf("|||                                                                         |||\n");
        printf("|||     Deseja pesquisar o usuário a ser atualizado por:                    |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| 1 - Nome do usuário                              |||\n");
        printf("|||                    |:| 2 - Livros em empréstimos                        |||\n");
        printf("|||                    |:| 3 - Período de empréstimo                        |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Empréstimos         |:|         0 - Encerrar            |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Escolha sua opção:  \n");
        scanf("%[0-9]", &opMenu);
        getchar();
}

void finalizaEmprestimos(void) {
    char opMenu;
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                          Finalizar Empréstimos                          |||\n");
        printf("|||                                                                         |||\n");
        printf("|||     Deseja pesquisar o empréstimo a ser efinalizado por:                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| 1 - Nome do usuário                              |||\n");
        printf("|||                    |:| 2 - Livros em empréstimos                        |||\n");
        printf("|||                    |:| 3 - Período de empréstimo                        |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Empréstimos         |:|         0 - Encerrar            |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Escolha sua opção:  \n");
        scanf("%[0-9]", &opMenu);
        getchar();
}