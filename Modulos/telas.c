#include <stdio.h>
#include <stdlib.h>
#include "menuEmprestimos.h"
#include "menuLivros.h"
#include "menuUsuarios.h"
#include "moduloValida.h"
#include "clearscr.h"
////////////////////////////////////////
// Telas

char* insereISBN(void) {
    char* isbnLivro;
    isbnLivro = (char*) malloc(14*sizeof(char));

    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por ISBN:                                  |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| ISBN do livro: ");
        
        do {
            scanf("%13[^\n]", isbnLivro);
            getchar();
        }while(!testaISBN(isbnLivro));
        
        printf("                                                                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");

        return isbnLivro;  
}

char* insereCPF(void) {
    char* cpf;
    cpf = (char*) malloc(12*sizeof(char));
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por CPF:                                   |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                  |:| CPF do usuário: ");

        do{
            scanf("%11[^\n]", cpf);
            getchar();
        }while(!testaCPF(cpf));
        
        printf("                                                                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");

        return cpf;  
}


char* insereTitulo(void) {
    char* tituloLivro;
    tituloLivro = (char*) malloc(81*sizeof(char));

    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Pesquisa por titulo:                                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |:| Título do livro: ");

        do{
            scanf(" %80[^\n]", tituloLivro);
            getchar();
        }while(!testaTitulo(tituloLivro));

        printf("                                                                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");

        return tituloLivro;  
}



void mcadastroLivro (Livro* liv) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||                            Livro Cadastrado                             |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                            \n");
        printf("|||                    Título:%s                                               \n", liv->livroTitulo);
        printf("|||                    Autor:%s                                                \n", liv->livroAutor);
        printf("|||                    Gênero:%s                                               \n", liv->livroGenero);
        printf("|||                    ISBN:%s                                                 \n", liv->livroISBN);
        printf("|||                                                                            \n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||| Pressione ENTER para voltar ao menu...\n");
        getchar();
}

void mcadastroUsuario (Usuario* user) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||                            Usuário Cadastrado                           |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                            \n");
        printf("|||                    Nome:%s                                                 \n", user->usuarioNome);
        printf("|||                    Data de nascimento:%s                                   \n", user->usuarioDataNasc);
        printf("|||                    CPF:%s                                                  \n", user->usuarioCPF);
        printf("|||                                                                            \n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||| Pressione ENTER para voltar ao menu...\n");
        getchar();
}

void mcadastroEmprestimo (Emprestimo* empr) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||                            Empréstimo Efetuado                          |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    CPF do usuário:%s                                    |||\n", empr->empr_CPF);
        printf("|||                    ISBN do livro emprestado:%s                          |||\n", empr->empr_ISBN);
        printf("|||                    Vencimento:%s                                        |||\n", empr->empr_Data);
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||| Pressione ENTER para voltar ao menu...\n");
        getchar();
}

void arq_msgErro(void) {
    printf("||| Não foi possível abrir o arquivo de dados...\n");
    printf("||| Fechando programa...\n");
    exit(1);
}