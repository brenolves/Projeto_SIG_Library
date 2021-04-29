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
        mcadastroLivro_Empr(liv);
    }

    user = procuraUsuario(empr->empr_CPF);
    if (user == NULL) {
        clearscr();
        printf("||| Usuário não consta no banco de dados...");
        getchar();
    }else{
        mcadastroUsuario_Empr(user);
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

void atualizaEmprestimos(void) {
    Emprestimo* empr;
    char* isbn;

    isbn = insereISBN();
    empr = procuraEmprestimo_ISBN(isbn);

    if (empr == NULL) {

        clearscr();
        printf("||| Empréstimo não consta no banco de dados...");
        getchar();

    }else{

        empr = tela_CadEmpr(empr);
        strcpy(empr->empr_ISBN, isbn);
        recadastrarEmpr(empr);
        free(empr);

    }
    free(isbn);
}



// Exclusões

void finalizaEmprestimos(void) {
    Emprestimo* empr;
    empr = (Emprestimo*) malloc(sizeof(Emprestimo));
	char* isbn;

	isbn = insereISBN();
	empr = procuraEmprestimo_ISBN(isbn);

	if (empr == NULL) {

    	clearscr();
        printf("||| Empréstimo não consta no banco de dados...");
        getchar();

  	}else{
        mcadastroEmprestimo(empr);
        empr->status = '0';
        recadastrarEmpr(empr);
        free(empr);
        clearscr();
        printf("||| Empréstimo excluido com sucesso!");
        getchar();

	}
	free(isbn);
}




// Funções gerais de amplo propósito(Podem ser usadas em outros módulos)


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

void recadastrarEmpr(Emprestimo* empr) {
	int existe;
	FILE* arq;
    
	Emprestimo* emprLido;
    emprLido = (Emprestimo*) malloc(sizeof(Emprestimo));
	
	arq = fopen("emprestimos.dat", "r+b");
	if (arq == NULL) {
		arq_msgErro();
	}

	existe = 0;

	while(fread(emprLido, sizeof(Emprestimo), 1, arq) && !existe) {
		if (strcmp(emprLido->empr_ISBN, empr->empr_ISBN) == 0) {
			existe = 1;
			fseek(arq, -1*sizeof(Emprestimo), SEEK_CUR);
        	fwrite(empr, sizeof(Emprestimo), 1, arq);
		}
	}
	fclose(arq);
	free(emprLido);
}