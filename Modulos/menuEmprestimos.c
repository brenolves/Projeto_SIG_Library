#include <stdio.h>
#include <stdlib.h>
#include "clearscr.h"
#include "moduloValida.h"
#include "telas.h"

// Módulo Empréstimos


char menuEmprestimos(void) {
    char opMenu;
        
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
    printf("|||                             0 - Menu Anterior                           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
    scanf("%[0-9]", &opMenu);
    getchar();
        

    return opMenu;
}

// Cadastros

void efetuarEmprestimos(void) {
    Emprestimo* empr;
    int tentar;

    // Checar se existe memória disponível.
    do{
        empr = (Emprestimo*) malloc(sizeof(Emprestimo));
        if (empr == NULL) {
            tentar = memoriaAlocada();
        }
    } while(tentar == 1);

    empr = tela_CadEmpr(empr);
    guardarEmprestimo(empr);
    free(empr);
}

Emprestimo* tela_CadEmpr(Emprestimo* empr) {
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
        printf("|||                    |:| CPF do usuário: ");

        do {
            scanf(" %50[^\n]", empr->empr_CPF);
            getchar();
        }while (!testaCPF(empr->empr_CPF));
        
        printf("                                                                            |||\n");
        printf("|||                    |:| ISBN do livro: ");

        do {
            scanf(" %13[^\n]", empr->empr_ISBN);
            getchar(); 
        }while(!testaISBN(empr->empr_ISBN));
        
        printf("                                                                            |||\n");
        printf("|||                    |:| Período de empréstimo(Data de vencimento): ");
        
        do {
            scanf(" %10[^\n]", empr->empr_Data);
            getchar();
        }while (!testaDataNasc(empr->empr_Data));
        printf("                                                                            |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        empr->status = '1';

        mcadastroEmprestimo(empr);

        return empr;
}

// Pesquisas

char pesquisaEmprestimos(void) {
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
    printf("|||                             0 - Menu Anterior                           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
    scanf("%[0-9]", &opMenu);
    getchar();


    return opMenu;
}

char pesquisaEmprestimos_Nome(void) {
    char nomeUsuario[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Pesquisa de Empréstimos                       |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                      Pesquisa por nome:                                 |||\n");
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

       // return nomeUsuario;  
}

char pesquisaEmprestimos_Livro(void) {
    char tituloLivro[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Pesquisa de Empréstimos                       |||\n");
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

char pesquisaEmprestimos_Data(void) {
    char dataEmprestimo[11];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Pesquisa de Empréstimos                       |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                      Pesquisa por data do empréstimo:                   |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                |:| Data do empréstimo:                                  |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[^\n]", dataEmprestimo);
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

       // return dataEmprestimo;  
}

// Atualizações

char atualizaEmprestimos(void) {
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
    printf("|||                             0 - Menu Anterior                           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
    scanf("%[0-9]", &opMenu);
    getchar();


    return opMenu;
}

char atualizaEmprestimos_Nome(void) {
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

char atualizaEmprestimos_Livro(void) {
    char tituloLivro[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                          Atualizar Empréstimos                          |||\n");
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

char atualizaEmprestimos_Data(void) {
    char dataEmprestimo[11];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Atualizar Empréstimos                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                      Pesquisa por data do empréstimo:                   |||\n");
        printf("|||                                                                         |||\n");
        printf("|||               |:| Data do empréstimo:                                   |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[^\n]", dataEmprestimo);
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

       // return dataEmprestimo;  
}

// Exclusões

char finalizaEmprestimos(void) {
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
    printf("|||                             0 - Menu Anterior                           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
    scanf("%[0-9]", &opMenu);
    getchar();

    return opMenu;
}

char finalizaEmprestimos_Nome(void) {
    char nomeUsuario[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Finalizar Empréstimos                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                      Pesquisa por nome:                                 |||\n");
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

       // return nomeUsuario;  
}

char finalizaEmprestimos_Livro(void) {
    char tituloLivro[51];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Finalizar Empréstimos                         |||\n");
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

char finalizaEmprestimos_Data(void) {
    char dataEmprestimo[11];
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                           Finalizar Empréstimos                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                      Pesquisa por data do empréstimo:                   |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                |:| Data do empréstimo:                                  |||\n");
        printf("|||                                         ");
        printf("                                                                            |||\n");
        scanf("%[^\n]", dataEmprestimo);
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

       // return dataEmprestimo;  
}


void guardarEmprestimo(Emprestimo* empr) {
	FILE* arq;

	arq = fopen("emprestimos.dat", "ab");
	if (arq == NULL) {
		printf("||| Não foi possível abrir o arquivo de dados...\n");
        printf("||| Fechando programa...\n");
        exit(1);
	}
	fwrite(empr, sizeof(Emprestimo), 1, arq);
	fclose(arq);
}