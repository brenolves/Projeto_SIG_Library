#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "clearscr.h"
#include "moduloValida.h"
#include "telas.h"

void imprimeRelatorio_CLM(void);
void imprimeRelatorio_CUM(void);
void imprimeRelatorio_CEM(void);

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
    printf("|||                |#| 1 - Cadastro e Empréstimos Neste Mês (%02d/%d)       |||\n", data.tm_mon + 1, data.tm_year + 1900);
    printf("|||                |#| 2 - Empréstimos Vencidos                             |||\n");
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

char menuRelatoriosCad(void) {
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


void telaCadastros_Livros(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Relatório de Cadastro de Livros                     |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||            ISBN            ||   %02d/%d   ||      Título do Livro       |||\n",data.tm_mon + 1, data.tm_year + 1900);
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                            ||             ||                            |||\n");
        imprimeRelatorio_CLM();
        printf("|||                            ||             ||                            |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||| Pressione ENTER para continuar...\n");
        getchar();
}

void imprimeRelatorio_CLM(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);

    int tam;
    char nome[20];

    FILE* arq;
    Livro* liv;

    liv = (Livro*) malloc(sizeof(Livro));
    arq = fopen("livros.dat", "rb");

    while(fread(liv, sizeof(Livro), 1, arq)) {
        if((liv->livroDataCad[1] == data.tm_mon + 1) && (liv->livroDataCad[2] == data.tm_year + 1900)) {
            tam = strlen(liv->livroTitulo);
            strncpy(nome, liv->livroTitulo, tam);
            for (int i = tam; i < 19; i++) {
                nome[i] = ' ';
            }
            nome[19] = '\0';
            printf("|||       %-13s        ||  %02d | %02d:%02d ||       %-20s |||\n", liv->livroISBN, liv->livroDataCad[0], liv->livroHoraCad[0], liv->livroHoraCad[1],nome);
        }
    }

    fclose(arq);
    free(liv);
}

void telaCadastros_Usuarios(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Relatório de Cadastro de Usuários                   |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||            CPF             ||   %02d/%d   ||      Nome do Usuário       |||\n",data.tm_mon + 1, data.tm_year + 1900);
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                            ||             ||                            |||\n");
        imprimeRelatorio_CUM();
        printf("|||                            ||             ||                            |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||| Pressione ENTER para continuar...\n");
        getchar();
}

void imprimeRelatorio_CUM(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);

    int tam;
    char nome[20];

    FILE* arq;
    Usuario* user;

    user = (Usuario*) malloc(sizeof(Usuario));
    arq = fopen("usuarios.dat", "rb");

    while(fread(user, sizeof(Usuario), 1, arq)) {
        if((user->usuarioDataCad[1] == data.tm_mon + 1) && (user->usuarioDataCad[2] == data.tm_year + 1900)) {
            tam = strlen(user->usuarioNome);
            strncpy(nome, user->usuarioNome, tam);
            for (int i = tam; i < 19; i++) {
                nome[i] = ' ';
            }
            nome[19] = '\0';
            printf("|||        %-11s         ||  %02d | %02d:%02d ||       %-20s |||\n", user->usuarioCPF, user->usuarioDataCad[0], user->usuarioHoraCad[0], user->usuarioHoraCad[1], nome);
        }
    }

    fclose(arq);
    free(user);
}

void telaCadastros_Emprestimos(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Relatório de Cadastro de Empréstimos                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||      CPF do Responsável    ||   %02d/%d   ||  ISBN do Livro Emprestado  |||\n",data.tm_mon + 1, data.tm_year + 1900);
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                            ||             ||                            |||\n");
        imprimeRelatorio_CEM();
        printf("|||                            ||             ||                            |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||| Pressione ENTER para continuar...\n");
        getchar();
}

void imprimeRelatorio_CEM(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);

    FILE* arq;
    Emprestimo* empr;

    empr = (Emprestimo*) malloc(sizeof(Emprestimo));
    arq = fopen("emprestimos.dat", "rb");

    while(fread(empr, sizeof(Emprestimo), 1, arq)) {
        if((empr->empr_Data[1] == data.tm_mon + 1) && (empr->empr_Data[2] == data.tm_year + 1900)) {

            printf("|||        %-11s         ||  %02d | %02d:%02d ||       %-13s        |||\n", empr->empr_CPF, empr->empr_Data[0], empr->empr_Hora[0], empr->empr_Hora[1], empr->empr_ISBN);
        }
    }

    fclose(arq);
    free(empr);
}