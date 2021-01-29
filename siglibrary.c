#include <stdio.h>
#include <stdlib.h>

////  Assinatura de funções.

// Menú Principal e Tela Sobre.
void menuPrincipal(void);
void menuAbout(void);
// Módulo Livros.
void menuLivros(void);
void cadastroLivros(void);
void pesquisaLivros(void);
void atualizaLivros(void);
void excluirLivros(void);
// Módulo Usuários
void menuUsuarios(void);
void cadastroUsuarios(void);
void pesquisaUsuarios(void);
void atualizaUsuarios(void);
void excluirUsuarios(void);
// Módulo Empréstimos
void menuEmprestimos(void);
void efetuarEmprestimos(void);
void pesquisaEmprestimos(void);
void atualizaEmprestimos(void);
void finalizaEmprestimos(void);


void clearscr(void);

// Função principal.

int main(void) {
    menuPrincipal();
    menuAbout();

    menuLivros();
    cadastroLivros();
    pesquisaLivros();
    atualizaLivros();
    excluirLivros();

    menuUsuarios();
    cadastroUsuarios();
    pesquisaUsuarios();
    atualizaUsuarios();
    excluirUsuarios();

    menuEmprestimos();
    efetuarEmprestimos();
    pesquisaEmprestimos();
    atualizaEmprestimos();
    finalizaEmprestimos();

    return 0;

}

// Função pra limpar a tela que funciona em vários SO's. Encontrei neste site >> https://stackoverflow.com/questions/18154579/how-do-i-clear-the-screen-in-c/18154598

void clearscr(void) {

#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
    #error "Sistema operacional não suportado."
#endif

}

//  Interfaces e funcionalidades do programa.

void menuPrincipal(void) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                            Menu Principal                               |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |#| 1 - Livros                                       |||\n");
        printf("|||                    |#| 2 - Usuários                                     |||\n");
        printf("|||                    |#| 3 - Empréstimos                                  |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Sobre o programa         |:|          0 - Encerrar           |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void menuAbout(void) {
    clearscr();
        printf("\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||               =||=||=||=||=|| SIG-Library ||=||=||=||=||=               |||\n");
        printf("|||                                                                         |||\n");
        printf("|||  Projeto criado no intuito de prover um melhor gerenciamento de         |||\n");
        printf("|||  bibliotecas, gerindo o cadastro de novos livros, empréstimos de livros,|||\n");
        printf("|||  e os usuários da biblioteca, podendo também navegar pelas datas de em- |||\n");
        printf("|||  -préstimo, prazos de devolução, livros disponíveis e usuários          |||\n");
        printf("|||  cadastrados.                                                           |||\n");
        printf("|||                                                                         |||\n");
        printf("|||     Desenvolvido por @brenolves                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();

}

void menuLivros(void) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                              Menu Livros                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |#| 1 - Cadastrar um livro                           |||\n");
        printf("|||                    |#| 2 - Pesquisar um livro                           |||\n");
        printf("|||                    |#| 3 - Atualizar cadastro de um livro               |||\n");
        printf("|||                    |#| 4 - Excluir cadastro de um livro                 |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Principal           |:|          0 - Encerrar           |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void cadastroLivros(void) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Cadastro de Livros                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Título do livro:                                 |||\n");
        printf("|||                    |:| Autor do livro:                                  |||\n");
        printf("|||                    |:| Gêneros do livro:                                |||\n");
        printf("|||                    |:| Código do livro:                                 |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Livros            |:|          0 - Encerrar             |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void pesquisaLivros(void) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Pesquisa de Livros                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Deseja pesquisar por:                               |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| 1 - Título do livro                              |||\n");
        printf("|||                    |:| 2 - Autor do livro                               |||\n");
        printf("|||                    |:| 3 - Gêneros do livro                             |||\n");
        printf("|||                    |:| 4 - Código do livro                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Livros            |:|          0 - Encerrar             |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void atualizaLivros(void) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                      Atualizar cadastro de Livros                       |||\n");
        printf("|||                                                                         |||\n");
        printf("|||     Deseja pesquisar o livro a ser atualizado por:                      |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| 1 - Título do livro                              |||\n");
        printf("|||                    |:| 2 - Autor do livro                               |||\n");
        printf("|||                    |:| 3 - Gêneros do livro                             |||\n");
        printf("|||                    |:| 4 - Código do livro                              |||\n");
        printf("|||                    |:| R - Recadastrar livro                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Livros            |:|          0 - Encerrar             |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void excluirLivros(void) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                      Excluir cadastro de Livros                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||     Deseja pesquisar o livro a ser excluido por:                        |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| 1 - Título do livro                              |||\n");
        printf("|||                    |:| 2 - Autor do livro                               |||\n");
        printf("|||                    |:| 3 - Gêneros do livro                             |||\n");
        printf("|||                    |:| 4 - Código do livro                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Livros            |:|          0 - Encerrar             |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void menuUsuarios(void) {
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
        getchar();
}

void cadastroUsuarios(void) {
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
        printf("|||                    |:| Data de nascimento do usuário:                   |||\n");
        printf("|||                    |:| Sexo do usuário:                                 |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Principal           |:|          0 - Encerrar           |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void pesquisaUsuarios(void) {
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
        printf("|||                    |:| 3 - Sexo do usuário                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Usuários          |:|          0 - Encerrar             |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void atualizaUsuarios(void) {
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
        printf("|||                    |:| 3 - Sexo do usuário                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Usuários          |:|          0 - Encerrar             |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void excluirUsuarios(void) {
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
        printf("|||                    |:| 3 - Sexo do usuário                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Usuários          |:|          0 - Encerrar             |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void menuEmprestimos(void) {
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
        getchar();
}

void efetuarEmprestimos(void) {
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
        printf("|||                    |:| Livros do empréstimo:                            |||\n");
        printf("|||                    |:| Período de empréstimo:                           |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Empréstimos          |:|          0 - Encerrar          |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void pesquisaEmprestimos(void) {
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
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void atualizaEmprestimos(void) {
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
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}

void finalizaEmprestimos(void) {
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
        printf("||| Aperte ENTER para continuar...\n");
        getchar();
}