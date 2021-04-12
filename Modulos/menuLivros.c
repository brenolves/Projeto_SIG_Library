#include <stdio.h>
#include <stdlib.h>
#include "clearscr.h"
#include "moduloValida.h"

// Módulo Livros.

struct livro {
    char livroTitulo[81];
    char livroAutor[51];
    char livroGenero[21];
    char livroISBN[14];
    char status;
};

typedef struct livro Livro;

char menuLivros(void) {
    char opMenu;
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
    printf("|||                             0 - Menu Anterior                           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
    scanf("%[0-9]", &opMenu);
    getchar();

        

    return opMenu;
}

void cadastroLivros() {
    Livro* liv;
    
    do{
        liv = (Livro*) malloc(sizeof(Livro));
        if (liv == NULL) {
            char tentar;
            printf("Memória insuficiente!\n");
            printf("Deseja tentar denovo?\n");
            printf("1 = Sim       0 = Não\n");
            printf(">> ");
            scanf("%[0-1]", &tentar);
            printf("\n");
            if (tentar == '1') {
                continue;
            }
            continue;
        }
    } while(liv == NULL);

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
        printf("|||                    |:| Título do livro: ");
        scanf("%80[^\n]", liv->livroTitulo);
        getchar();
        printf("                                                                            |||\n");                                               
        printf("|||                    |:| Autor do livro:  ");
        scanf("%50[^\n]", liv->livroAutor);
        getchar();
        printf("                                                                            |||\n");
        printf("|||                    |:| Gênero do livro: ");
        scanf("%20[^\n]", liv->livroGenero);
        getchar();
        printf("                                                                            |||\n");
        printf("|||                    |:| Código do livro: ");
        scanf("%13[^\n]", liv->livroISBN);
        getchar();
        printf("                                                                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        liv->status = '1';
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
    printf("|||                             0 - Menu Anterior                           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
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
        scanf("%[^\n]", tituloLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

       // return tituloLivro;  
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
        scanf("%[^\n]", autorLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      //  return autorLivro;  
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
        scanf("%[^\n]", generoLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      // return generoLivro;  
}

int pesquisaLivros_Codigo(void) {
    char codigoLivro[10];
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
        scanf("%[^\n]", codigoLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      //  return codigoLivro;  
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
    printf("|||                             0 - Menu Anterior                           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
    scanf("%[0-9]", &opMenu);
    getchar();

    return opMenu;
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
        scanf("%[^\n]", tituloLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      //  return tituloLivro;  
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
        scanf("%[^\n]", autorLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      //  return autorLivro;  
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
        scanf("%[^\n]", generoLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

     //   return generoLivro;  
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

     //   return codigoLivro;  
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
    printf("|||                             0 - Menu Anterior                           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
    scanf("%[0-9]", &opMenu);
    getchar();

    return opMenu;
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
        scanf("%[^\n]", tituloLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      //  return tituloLivro;  
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
        scanf("%[^\n]", autorLivro);
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        getchar();

      //  return autorLivro;  
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
    scanf("%[^\n]", generoLivro);
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    getchar();

  //  return generoLivro;
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

      //  return codigoLivro;  
}