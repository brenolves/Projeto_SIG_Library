#include <stdio.h>
#include <stdlib.h>

////  Assinatura de funções.

// Menú Principal e Tela Sobre.
char menuPrincipal(void);
void menuAbout(void);
// Módulo Livros.
char menuLivros(void);
    void cadastroLivros(void);
    char pesquisaLivros(void);
        void pesquisaLivros_Titulo(void);
        void pesquisaLivros_Autor(void);
        void pesquisaLivros_Genero(void);
        void pesquisaLivros_Codigo(void);
    char atualizaLivros(void);
        void atualizaLivros_Titulo(void);
        void atualizaLivros_Autor(void);
        void atualizaLivros_Genero(void);
        void atualizaLivros_Codigo(void);
    char excluirLivros(void);
        void excluirLivros_Titulo(void);
        void excluirLivros_Autor(void);
        void excluirLivros_Genero(void);
        void excluirLivros_Codigo(void);
// Módulo Usuários
char menuUsuarios(void);
    void cadastroUsuarios(void);
    void pesquisaUsuarios(void);
    void atualizaUsuarios(void);
    void excluirUsuarios(void);
// Módulo Empréstimos
char menuEmprestimos(void);
    void efetuarEmprestimos(void);
    void pesquisaEmprestimos(void);
    void atualizaEmprestimos(void);
    void finalizaEmprestimos(void);


void clearscr(void);

// Função principal.

int main(void) {
    char opMenuP, opMenu_Livros, opMenu_Usuarios, opMenu_Emprestimos;
    char opPesq_Livros, opPesq_Usuarios, opPesq_Emprestimos;
    char opAtul_Livros, opAtul_Usuarios, opAtul_Emprestimos;
    char opExclu_Livros, opExclu_Usuarios, opExclu_Emprestimos;

    do{
    opMenuP = menuPrincipal();
    switch (opMenuP){
        case '1':
            do{
            opMenu_Livros = menuLivros();
            switch(opMenu_Livros){
                case '1':
                    cadastroLivros();
                    break;
                case '2':
                    do{
                    opPesq_Livros = pesquisaLivros();
                    switch(opPesq_Livros){
                        case '1':
                            pesquisaLivros_Titulo();
                            break;
                        case '2':
                            pesquisaLivros_Autor();
                            break;
                        case '3':
                            pesquisaLivros_Genero();
                            break;
                        case '4':
                            pesquisaLivros_Codigo();
                            break;
                        case '5':
                            continue;
                        }
                    }
                    while (opPesq_Livros != '0');
                    return 0;
                    break;
                case '3':
                    do{
                    opAtul_Livros = atualizaLivros();
                    switch(opAtul_Livros){
                        case '1':
                            atualizaLivros_Titulo();
                            break;
                        case '2':
                            atualizaLivros_Autor();
                            break;
                        case '3':
                            atualizaLivros_Genero();
                            break;
                        case '4':
                            atualizaLivros_Codigo();
                            break;
                        case '5':
                            break;
                        }
                    }
                    while (opAtul_Livros != '0');
                    return 0;
                    break;
                case '4':
                    do{
                    opExclu_Livros = excluirLivros();
                    switch(opExclu_Livros){
                        case '1':
                            excluirLivros_Titulo();
                            break;
                        case '2':
                            excluirLivros_Autor();
                            break;
                        case '3':
                            excluirLivros_Genero();
                            break;
                        case '4':
                            excluirLivros_Codigo();
                            break;
                        case '5':
                            break;
                        }
                    }
                    while (opExclu_Livros != '0');
                    return 0;
                    break;
                case '5':
                    main();
                    break;
                }
            }
            while(opMenu_Livros != '0');
            return 0;
            break;
        case '2':
            do{
            opMenu_Usuarios = menuUsuarios();
            switch(opMenu_Usuarios){
                case '1':
                    cadastroUsuarios();
                    break;
                case '2':
                    pesquisaUsuarios();
                    break;
                case '3':
                    atualizaUsuarios();
                    break;
                case '4':
                    excluirUsuarios();
                    break;
                case '5':
                    main();
                    break;
                }
            }
            while(opMenu_Usuarios != '0');
            return 0;
            break;
        case '3':
            do{
            opMenu_Emprestimos = menuEmprestimos();
            switch(opMenu_Emprestimos){
                case '1':
                    efetuarEmprestimos();
                    break;
                case '2':
                    pesquisaEmprestimos();
                    break;
                case '3':
                    atualizaEmprestimos();
                    break;
                case '4':
                    finalizaEmprestimos();
                    break;
                case '5':
                    main();
                    break;
                }
            }
            while(opMenu_Emprestimos != '0');
            return 0;
            break;
        case '5':
            menuAbout();
            break;
        }
    }
    while (opMenuP != '0');
    printf("Programa Encerrado!\n");

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

char menuPrincipal(void) {
    char opMenuP;
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
        printf("||| Escolha sua opção:  \n");
        scanf("%[0-9]", &opMenuP);
        getchar();

        return opMenuP;
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
        printf("||| Aperte ENTER para voltar para o menu principal...\n");
        getchar();

        return main();
}

char menuLivros(void) {
    char opMenu_Livros;
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
        printf("||| Escolha sua opção:  \n");
        scanf("%[0-9]", &opMenu_Livros);
        getchar();

        return opMenu_Livros;
}

void cadastroLivros(void) {
    char livroTitulo[51];
    char livroAutor[51];
    char livroGenero[21];
    int livroCodigo[9];
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
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ0-9]", livroTitulo);
        getchar();
        printf("|||                    |:| Autor do livro:                                  |||\n");
        printf("|||                                        ");
        printf("                                                                            |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", livroAutor);
        getchar();
        printf("|||                    |:| Gênero do livro:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", livroGenero);
        getchar();
        printf("|||                    |:| Código do livro:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[0-9]", livroCodigo);
        getchar();
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");

        return;
}

char pesquisaLivros(void) {
    char opMenu;
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
        printf("||| Escolha sua opção:  \n");
        scanf("%[0-9]", &opMenu); 
        getchar();

        return opMenu;
}

void pesquisaLivros_Titulo(void) {
    char tituloLivro[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Pesquisa de Livros                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por titulo:                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Título do livro:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ0-9]", &tituloLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

        return tituloLivro;  
}

void pesquisaLivros_Autor(void) {
    char autorLivro[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Pesquisa de Livros                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por autor:                                 |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Autor do livro:                                  |||\n");
        printf("|||                                        ");
        printf("                                                                            |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", &autorLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

        return autorLivro;  
}

void pesquisaLivros_Genero(void) {
    char generoLivro[21];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Pesquisa de Livros                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por gênero:                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Gênero do livro:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", &generoLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

        return generoLivro;  
}

void pesquisaLivros_Codigo(void) {
    int codigoLivro;
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Pesquisa de Livros                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por código:                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Código do livro:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%i", &codigoLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

        return codigoLivro;  
}

char atualizaLivros(void) {
    char opMenu;
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
        printf("|||                    |:| 3 - Gênero do livro                              |||\n");
        printf("|||                    |:| 4 - Código do livro                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Menu Livros            |:|          0 - Encerrar             |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Escolha sua opção:  \n");
        scanf("%[0-9]", opMenu);
        getchar();
}

void atualizaLivros_Titulo(void) {
    char tituloLivro[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Atualizar Livros                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por título:                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Título do livro:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ0-9]", &tituloLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

        return tituloLivro;  
}

void atualizaLivros_Autor(void) {
    char autorLivro[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Atualizar Livros                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por autor:                                 |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Autor do livro:                                  |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ0-9]", &autorLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

        return autorLivro;  
}

void atualizaLivros_Genero(void) {
    char generoLivro[21];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Atualizar Livros                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por gênero:                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Gênero do livro:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ0-9]", &generoLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

        return generoLivro;  
}

void atualizaLivros_Codigo(void) {
    int codigoLivro;
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Atualizar Livros                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por código:                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Código do livro:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%i", &codigoLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

        return codigoLivro;  
}

char excluirLivros(void) {
    char opMenu;
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
        printf("||| Escolha sua opção:  \n");
        scanf("%[0-9]", opMenu);
        getchar();
}

void excluirLivros_Titulo(void) {
    char tituloLivro[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Excluir Livros                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                       Pesquisa por título:                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Título do livro:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ0-9]", &tituloLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

        return tituloLivro;  
}

void excluirLivros_Autor(void) {
    char autorLivro[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Excluir Livros                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                       Pesquisa por autor:                               |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Autor do livro:                                  |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ0-9]", &autorLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

        return autorLivro;  
}

void excluirLivros_Genero(void) {
    char generoLivro[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Excluir Livros                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                       Pesquisa por gênero:                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Gênero do livro:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ0-9]", &generoLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

        return generoLivro;
}

void excluirLivros_Codigo(void) {
    int codigoLivro;
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Excluir Livros                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                       Pesquisa por código:                              |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Código do livro:                                 |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%i", &codigoLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

        return codigoLivro;  
}

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