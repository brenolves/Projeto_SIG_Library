#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "clearscr.h"
#include "moduloValida.h"
#include "telas.h"

void imprimeRelatorio_CLM(void);
void imprimeRelatorio_ELM(void);
void imprimeRelatorio_CUM(void);
void imprimeRelatorio_EUM(void);
void imprimeRelatorio_CEM(void);
void imprimeRelatorio_EEM(void);
void imprimeRelatorio_EV(void);

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
    printf("|||                |#| 1 - Cadastros e Empréstimos Neste Mês (%02d/%d)      |||\n", data.tm_mon + 1, data.tm_year + 1900);
    printf("|||                |#| 2 - Exclusões Neste Mês (%02d/%d)                    |||\n", data.tm_mon + 1, data.tm_year + 1900);
    printf("|||                |#| 3 - Empréstimos Vencidos                             |||\n");
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

char menuRelatoriosExc(void) {
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
    printf("|||                |#| 1 - Exclusões de Livros Neste Mês (%02d/%d)          |||\n", data.tm_mon + 1, data.tm_year + 1900);
    printf("|||                |#| 2 - Exclusões de Usuários Neste Mês (%02d/%d)        |||\n", data.tm_mon + 1, data.tm_year + 1900);
    printf("|||                |#| 3 - Exclusões de Empréstimos Neste Mês (%02d/%d)     |||\n", data.tm_mon + 1, data.tm_year + 1900);
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

void telaExclu_Livros(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Relatório de Exclusões de Livros                    |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||            ISBN            ||   %02d/%d   ||      Título do Livro       |||\n",data.tm_mon + 1, data.tm_year + 1900);
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                            ||             ||                            |||\n");
        imprimeRelatorio_ELM();
        printf("|||                            ||             ||                            |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||| Pressione ENTER para continuar...\n");
        getchar();
}

void imprimeRelatorio_CLM(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);

    int tam;
    char nome[81];

    FILE* arq;
    Livro* liv;

    liv = (Livro*) malloc(sizeof(Livro));
    arq = fopen("livros.dat", "rb");

    if (arq == NULL) {
        arq = fopen("livros.dat", "wb");
    }

    while(fread(liv, sizeof(Livro), 1, arq)) {
        if((liv->livroDataCad[1] == data.tm_mon + 1) && (liv->livroDataCad[2] == data.tm_year + 1900) && (liv->status != '0')) {
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

void imprimeRelatorio_ELM(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);

    int tam;
    char nome[81];

    FILE* arq;
    Livro* liv;

    liv = (Livro*) malloc(sizeof(Livro));
    arq = fopen("livros.dat", "rb");

    if (arq == NULL) {
        arq = fopen("livros.dat", "wb");
    }

    while(fread(liv, sizeof(Livro), 1, arq)) {
        if((liv->livroDataCad[1] == data.tm_mon + 1) && (liv->livroDataCad[2] == data.tm_year + 1900) && (liv->status == '0')) {
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

void telaExclu_Usuarios(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Relatório de Exclusões de Usuários                  |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||            CPF             ||   %02d/%d   ||      Nome do Usuário       |||\n",data.tm_mon + 1, data.tm_year + 1900);
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                            ||             ||                            |||\n");
        imprimeRelatorio_EUM();
        printf("|||                            ||             ||                            |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||| Pressione ENTER para continuar...\n");
        getchar();
}

void imprimeRelatorio_CUM(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);

    int tam;
    char nome[51];

    FILE* arq;
    Usuario* user;

    user = (Usuario*) malloc(sizeof(Usuario));
    arq = fopen("usuarios.dat", "rb");

    if (arq == NULL) {
        arq = fopen("usuarios.dat", "wb");
    }

    while(fread(user, sizeof(Usuario), 1, arq)) {
        if((user->usuarioDataCad[1] == data.tm_mon + 1) && (user->usuarioDataCad[2] == data.tm_year + 1900) && (user->status != '0')) {
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

void imprimeRelatorio_EUM(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);

    int tam;
    char nome[51];

    FILE* arq;
    Usuario* user;

    user = (Usuario*) malloc(sizeof(Usuario));
    arq = fopen("usuarios.dat", "rb");

    if (arq == NULL) {
        arq = fopen("usuarios.dat", "wb");
    }

    while(fread(user, sizeof(Usuario), 1, arq)) {
        if((user->usuarioDataCad[1] == data.tm_mon + 1) && (user->usuarioDataCad[2] == data.tm_year + 1900) && (user->status == '0')) {
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

void telaExclu_Emprestimos(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Relatório de Exclusões de Empréstimos               |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||      CPF do Responsável    ||   %02d/%d   ||  ISBN do Livro Emprestado  |||\n",data.tm_mon + 1, data.tm_year + 1900);
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                            ||             ||                            |||\n");
        imprimeRelatorio_EEM();
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

    if (arq == NULL) {
        arq = fopen("emprestimos.dat", "wb");
    }

    while(fread(empr, sizeof(Emprestimo), 1, arq)) {
        if((empr->empr_Data[1] == data.tm_mon + 1) && (empr->empr_Data[2] == data.tm_year + 1900) && (empr->status != '0')) {

            printf("|||        %-11s         ||  %02d | %02d:%02d ||       %-13s        |||\n", empr->empr_CPF, empr->empr_Data[0], empr->empr_Hora[0], empr->empr_Hora[1], empr->empr_ISBN);
        }
    }

    fclose(arq);
    free(empr);
}

void imprimeRelatorio_EEM(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);

    FILE* arq;
    Emprestimo* empr;

    empr = (Emprestimo*) malloc(sizeof(Emprestimo));
    arq = fopen("emprestimos.dat", "rb");

    if (arq == NULL) {
        arq = fopen("emprestimos.dat", "wb");
    }

    while(fread(empr, sizeof(Emprestimo), 1, arq)) {
        if((empr->empr_Data[1] == data.tm_mon + 1) && (empr->empr_Data[2] == data.tm_year + 1900) && (empr->status == '0')) {

            printf("|||        %-11s         ||  %02d | %02d:%02d ||       %-13s        |||\n", empr->empr_CPF, empr->empr_Data[0], empr->empr_Hora[0], empr->empr_Hora[1], empr->empr_ISBN);
        }
    }

    fclose(arq);
    free(empr);
}

void telaEmpr_Vencidos(void) {
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                     Relatório de Empréstimos Vencidos                   |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||      CPF do Responsável    || Válido Até  ||  ISBN do Livro Emprestado  |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                            ||             ||                            |||\n");
        imprimeRelatorio_EV();
        printf("|||                            ||             ||                            |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||| Pressione ENTER para continuar...\n");
        getchar();
}

void imprimeRelatorio_EV(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);

    FILE* arq;
    Emprestimo* empr;

    empr = (Emprestimo*) malloc(sizeof(Emprestimo));
    arq = fopen("emprestimos.dat", "rb");

    if (arq == NULL) {
        arq = fopen("emprestimos.dat", "wb");
    }

    while(fread(empr, sizeof(Emprestimo), 1, arq)) {
        if((((empr->empr_DataVal[0] < data.tm_mday) && (empr->empr_DataVal[1] <= data.tm_mon + 1)) || (empr->empr_DataVal[1] < data.tm_mon + 1)) && (empr->empr_DataVal[2] <= data.tm_year + 1900) && (empr->status != '0')) {

            printf("|||        %-11s         ||  %02d/%02d/%d ||       %-13s        |||\n", empr->empr_CPF, empr->empr_DataVal[0], empr->empr_DataVal[1], empr->empr_DataVal[2], empr->empr_ISBN);
        }
    }

    fclose(arq);
    free(empr);
}