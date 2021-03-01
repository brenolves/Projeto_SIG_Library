#include <stdio.h>
#include <stdlib.h>
#include "siglibrary.h"

// Módulo Livros.
char menuLivros(void);
    void cadastroLivros(void);
    char pesquisaLivros(void);
        char pesquisaLivros_Titulo(void);
        char pesquisaLivros_Autor(void);
        char pesquisaLivros_Genero(void);
        int pesquisaLivros_Codigo(void);
    char atualizaLivros(void);
        char atualizaLivros_Titulo(void);
        char atualizaLivros_Autor(void);
        char atualizaLivros_Genero(void);
        int atualizaLivros_Codigo(void);
    char excluirLivros(void);
        char excluirLivros_Titulo(void);
        char excluirLivros_Autor(void);
        char excluirLivros_Genero(void);
        int excluirLivros_Codigo(void);


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

char pesquisaLivros_Titulo(void) {
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

char pesquisaLivros_Autor(void) {
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

char pesquisaLivros_Genero(void) {
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

int pesquisaLivros_Codigo(void) {
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

char atualizaLivros_Titulo(void) {
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

char atualizaLivros_Autor(void) {
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

char atualizaLivros_Genero(void) {
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

int atualizaLivros_Codigo(void) {
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

char excluirLivros_Titulo(void) {
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

char excluirLivros_Autor(void) {
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

char excluirLivros_Genero(void) {
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

int excluirLivros_Codigo(void) {
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