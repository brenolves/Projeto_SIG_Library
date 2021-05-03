#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "clearscr.h"
#include "moduloValida.h"
#include "telas.h"

char menuRelatorios(void) {
    char opMenu;
    time_t t = time(NULL);
    struct tm data = *localtime(&t);
        
    clearscr();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                           Menu Relatórios                               |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                |#| 1 - Cadastro de Livros Neste Mês (%02d/%d)           |||\n", data.tm_mon + 1, data.tm_year + 1900);
    printf("|||                |#| 2 - Cadastro de Usuários Neste Mês (%02d/%d)         |||\n", data.tm_mon + 1, data.tm_year + 1900);
    printf("|||                |#| 3 - Empréstimos de Livros Neste Mês (%02d/%d)        |||\n", data.tm_mon + 1, data.tm_year + 1900);
    printf("|||                |#| 4 - Empréstimos Vencidos                             |||\n");
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


void listaCadastros_Livros(char *titulo, char *autor, char *genero, int codigo, int n) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Relatório de Cadastro de Livros                     |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        for (int i = 0; i < n; i++) {
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                Cadastro N°%d                                            |||\n", i+1);
        printf("|||                                                                         |||\n");
        printf("|||                Título: %s                                               |||\n", titulo);
        printf("|||                Autor: %s                                                |||\n", autor);
        printf("|||                Gênero: %s                                               |||\n", genero);
        printf("|||                Código: %d                                               |||\n", codigo);
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        }
    getchar();
}

void listaCadastros_Usuarios(char *nome, char *datanasc, int codigo, int n) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Relatório de Cadastro de Usuarios                   |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        for (int i = 0; i < n; i++) {
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                Cadastro N°%d                                            |||\n", i+1);
        printf("|||                                                                         |||\n");
        printf("|||                  Nome: %s                                               |||\n", nome);
        printf("|||    Data de Nascimento: %s                                               |||\n", datanasc);
        printf("|||                Título: %d                                               |||\n", codigo);
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        }
    getchar();
}

void listaEmprestimos(char *nome, char *livro, char *dataemprestimo, int n) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Relatório de Cadastro de Usuarios                   |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        for (int i = 0; i < n; i++) {
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                Cadastro N°%d                                            |||\n", i+1);
        printf("|||                                                                         |||\n");
        printf("|||                  Nome: %s                                               |||\n", nome);
        printf("|||    Data de Empréstimo: %s                                               |||\n", dataemprestimo);
        printf("|||       Título do Livro: %s                                               |||\n", livro);
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        }
    getchar();
}