#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "clearscr.h"
#include "moduloValida.h"
#include "telas.h"

// Módulo Livros.


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

//Cadastros

void cadastroLivros() {
    Livro* liv;
    int tentar = 0;
    
    // Checar se existe memória disponível.
    do{
        liv = (Livro*) malloc(sizeof(Livro));
        if (liv == NULL) {
            tentar = memoriaAlocada();
        }
    } while(tentar == 1);

    liv = tela_CadLivros(liv);
    guardarLivro(liv);
    free(liv);

}

Livro* tela_CadLivros(Livro* liv){
    time_t t = time(NULL);
    struct tm data = *localtime(&t);
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

        do {
            printf("                    |:| Título do livro: ");
            scanf(" %80[^\n]", liv->livroTitulo);
            getchar();
        }while (!testaTitulo(liv->livroTitulo));

        do {
            printf("                    |:| Autor do livro:  ");
            scanf(" %50[^\n]", liv->livroAutor);
            getchar();
        }while (!testaNome(liv->livroAutor));

        printf("                    |:| Gênero do livro: ");

        scanf(" %30[^\n]", liv->livroGenero);
        getchar();

        

        do {
            printf("                    |:| ISBN do livro: ");
            scanf(" %13[^\n]", liv->livroISBN);
            getchar();
        }while((!testaISBN(liv->livroISBN)) || (!procuraISBN_L(liv->livroISBN)));
        liv->livroDataCad[0] = data.tm_mday;
        liv->livroDataCad[1] = data.tm_mon + 1;
        liv->livroDataCad[2] = data.tm_year + 1900;

        liv->livroHoraCad[0] = data.tm_hour;
        liv->livroHoraCad[1] = data.tm_min;
        liv->livroHoraCad[2] = data.tm_sec;


        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        liv->status = '1';

        mcadastroLivro(liv);

        return liv;
}

Livro* tela_RecadLivros(Livro* liv){
    time_t t = time(NULL);
    struct tm data = *localtime(&t);
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

        do {
            printf("                    |:| Título do livro: ");
            scanf(" %80[^\n]", liv->livroTitulo);
            getchar();
        }while (!testaTitulo(liv->livroTitulo));

        do {
            printf("                    |:| Autor do livro:  ");
            scanf(" %50[^\n]", liv->livroAutor);
            getchar();
        }while (!testaNome(liv->livroAutor));

        printf("                    |:| Gênero do livro: ");

        scanf(" %30[^\n]", liv->livroGenero);
        getchar();

        liv->livroDataCad[0] = data.tm_mday;
        liv->livroDataCad[1] = data.tm_mon + 1;
        liv->livroDataCad[2] = data.tm_year + 1900;

        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        liv->status = '1';

        mcadastroLivro(liv);

        return liv;
}

// Pesquisas

char menu_pesqLivros(void) {
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
    printf("|||                    |:| 2 - ISBN do livro                                |||\n");
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

void pesquisaLivros_Titulo(void) {
    char* titulo;
    Livro* liv;

    titulo = insereTitulo();
    liv = procuraLivro_Titulo(titulo);

    if (liv == NULL) {
        clearscr();
        printf("                    Livro não consta no banco de dados...");
        getchar();
    }else{
        mcadastroLivro(liv);
    }
    free(titulo);
    free(liv);
}

void pesquisaLivros_ISBN(void) {
    char* isbnLivro;
    Livro* liv;

    isbnLivro = insereISBN();
    liv = procuraLivro_ISBN(isbnLivro);

    if (liv == NULL) {
        clearscr();
        printf("                    Livro não consta no banco de dados...");
        getchar();
    }else{
        mcadastroLivro(liv);
    }
    free(isbnLivro);
    free(liv);
}

// Atualizações


void atualizaLivros(void) {
    Livro* liv;
    char* isbn;

    isbn = insereISBN();
    liv = procuraLivro_ISBN(isbn);

    if (liv == NULL) {

        clearscr();
        printf("                    Livro não consta no banco de dados...");
        getchar();

    }else{
        mcadastroLivro(liv);
        liv = tela_RecadLivros(liv);
        strcpy(liv->livroISBN, isbn);
        recadastrarLivro(liv);
        free(liv);

    }
    free(isbn);
}

// Exclusões

void excluirLivros(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);

    Livro* liv;
    liv = (Livro*) malloc(sizeof(Livro));
	char* isbn;

	isbn = insereISBN();
	liv = procuraLivro_ISBN(isbn);

	if (liv == NULL) {

    	clearscr();
        printf("                    Livro não consta no banco de dados...");
        getchar();

  	}else{
        mcadastroLivro(liv);

        liv->livroDataCad[0] = data.tm_mday;
        liv->livroDataCad[1] = data.tm_mon + 1;
        liv->livroDataCad[2] = data.tm_year + 1900;

        liv->livroHoraCad[0] = data.tm_hour;
        liv->livroHoraCad[1] = data.tm_min;
        liv->livroHoraCad[2] = data.tm_sec;

        liv->status = '0';
        recadastrarLivro(liv);
        free(liv);
        clearscr();
        printf("                    Livro excluido com sucesso!");
        getchar();

	}
	free(isbn);
}



void guardarLivro(Livro* liv) {
	FILE* arq;

	arq = fopen("livros.dat", "ab");
	if (arq == NULL) {

		arq_msgErro();

	}
	fwrite(liv, sizeof(Livro), 1, arq);
	fclose(arq);
}

// Funções gerais de amplo propósito(Podem ser usadas em outros módulos)

Livro* procuraLivro_Titulo(char* titulo) {
    Livro* liv;
    FILE* arq;

    liv = (Livro*) malloc(sizeof(Livro));
    arq = fopen("livros.dat", "rb");

    if (arq == NULL) {

        arq_msgErro();

    }

	while(fread(liv, sizeof(Livro), 1, arq)) {
		if ((strcmp(liv->livroTitulo, titulo) == 0) && (liv->status != '0')) {

			fclose(arq);
			return liv;

		}
	}

	fclose(arq);
	return NULL;
}

Livro* procuraLivro_ISBN(char* isbn) {
    Livro* liv;
    FILE* arq;

    liv = (Livro*) malloc(sizeof(Livro));
    arq = fopen("livros.dat", "rb");

    if (arq == NULL) {
        arq_msgErro();
    }

	while(fread(liv, sizeof(Livro), 1, arq)) {
		if ((strcmp(liv->livroISBN, isbn) == 0) && (liv->status != '0')) {
			fclose(arq);
			return liv;
		}
	}
    
	fclose(arq);
	return NULL;
}

int procuraISBN_L(char* isbn) {
    Livro* liv;
    FILE* arq;

    liv = (Livro*) malloc(sizeof(Livro));
    arq = fopen("livros.dat", "rb");

    if (arq == NULL) {
        arq = fopen("livros.dat", "wb");
    }

	while(fread(liv, sizeof(Livro), 1, arq)) {
		if ((strcmp(liv->livroISBN, isbn) == 0) && (liv->status != '0')) {
			fclose(arq);
            printf("                    Já existe um cadastro com este ISBN!\n");
            printf("                    Insira outro ISBN! \n");
			return 0;
		}
	}
    
	fclose(arq);
	return 1;
}

void recadastrarLivro(Livro* liv) {
	int existe;
	FILE* arq;
    
	Livro* livLido;
    livLido = (Livro*) malloc(sizeof(Livro));
	
	arq = fopen("livros.dat", "r+b");
	if (arq == NULL) {
		arq_msgErro();
	}

	existe = 0;

	while(fread(livLido, sizeof(Livro), 1, arq) && !existe) {
		if (strcmp(livLido->livroISBN, liv->livroISBN) == 0) {
			existe = 1;
			fseek(arq, -1*sizeof(Livro), SEEK_CUR);
        	fwrite(liv, sizeof(Livro), 1, arq);
		}
	}
	fclose(arq);
	free(livLido);
}

