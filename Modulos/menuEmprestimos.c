#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
    Livro* liv;
    Usuario* user;
    int tentar;

    // Checar se existe memória disponível.
    do{
        empr = (Emprestimo*) malloc(sizeof(Emprestimo));
        if (empr == NULL) {
            tentar = memoriaAlocada();
        }
    } while(tentar == 1);

    empr = tela_CadEmpr(empr);

    liv = procuraLivro_ISBN(empr->empr_ISBN);
    if (liv == NULL) {
        clearscr();
        printf("||| Livro não consta no banco de dados...");
        getchar();
    }else{
        mcadastroLivro(liv);
    }

    user = procuraUsuario(empr->empr_CPF);
    if (user == NULL) {
        clearscr();
        printf("||| Usuário não consta no banco de dados...");
        getchar();
    }else{
        mcadastroUsuario(user);
    }

    guardarEmprestimo(empr);
    free(empr);
    free(liv);
    free(user);
}

Emprestimo* tela_CadEmpr(Emprestimo* empr) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);
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
            scanf(" %11[^\n]", empr->empr_CPF);
            getchar();
        }while(!testaCPF(empr->empr_CPF));
        
        printf("                                                                            |||\n");
        printf("|||                    |:| ISBN do Emprestimo: ");

        do {
            scanf("%13[^\n]", empr->empr_ISBN);
            getchar(); 
        }while(!testaISBN(empr->empr_ISBN));

        empr->empr_Data[0] = data.tm_mday;
        empr->empr_Data[1] = data.tm_mon + 1;
        empr->empr_Data[2] = data.tm_year + 1900;

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

void pesquisaEmpr_CPF(void) {
    char* cpf;
    Emprestimo* empr;

    cpf = insereCPF();
    empr = procuraEmprestimo_CPF(cpf);

    if (empr == NULL) {
        clearscr();
        printf("||| Empréstimo não consta no banco de dados...");
        getchar();
    }else{
        mcadastroEmprestimo(empr);
    }
    free(cpf);
    free(empr);
}

void pesquisaEmpr_ISBN(void) {
    char* isbn;
    Emprestimo* empr;

    isbn = insereISBN();
    empr = procuraEmprestimo_ISBN(isbn);

    if (empr == NULL) {
        clearscr();
        printf("||| Empréstimo não consta no banco de dados...");
        getchar();
    }else{
        mcadastroEmprestimo(empr);
    }
    free(isbn);
    free(empr);
}

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
    printf("|||                    |:| 1 - CPF do usuário                               |||\n");
    printf("|||                    |:| 2 - ISBN do livro emprestado                     |||\n");
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
    printf("|||                    |:| 2 - Emprestimos em empréstimos                        |||\n");
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
    printf("|||                    |:| 2 - Emprestimos em empréstimos                        |||\n");
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

Emprestimo* procuraEmprestimo_CPF(char* cpf) {
    Emprestimo* empr;
    FILE* arq;

    empr = (Emprestimo*) malloc(sizeof(Emprestimo));
    arq = fopen("emprestimos.dat", "rb");

    if (arq == NULL) {

        arq_msgErro();

    }

	while(fread(empr, sizeof(Emprestimo), 1, arq)) {
		if ((strcmp(empr->empr_CPF, cpf) == 0) && (empr->status == '1')) {

			fclose(arq);
			return empr;

		}
	}

	fclose(arq);
	return NULL;
}

Emprestimo* procuraEmprestimo_ISBN(char* isbn) {
    Emprestimo* empr;
    FILE* arq;

    empr = (Emprestimo*) malloc(sizeof(Emprestimo));
    arq = fopen("emprestimos.dat", "rb");

    if (arq == NULL) {

        arq_msgErro();

    }

	while(fread(empr, sizeof(Emprestimo), 1, arq)) {
		if ((strcmp(empr->empr_ISBN, isbn) == 0) && (empr->status == '1')) {

			fclose(arq);
			return empr;

		}
	}

	fclose(arq);
	return NULL;
}