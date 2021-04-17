#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

        do {
            scanf(" %80[^\n]", liv->livroTitulo);
            getchar();
        }while (!testaTitulo(liv->livroTitulo));

        printf("                                                                            |||\n");                                               
        printf("|||                    |:| Autor do livro:  ");

        do {
            scanf(" %50[^\n]", liv->livroAutor);
            getchar();
        }while (!testaNome(liv->livroAutor));

        printf("                                                                            |||\n");
        printf("|||                    |:| Gênero do livro: ");

        scanf(" %20[^\n]", liv->livroGenero);
        getchar();

        printf("                                                                            |||\n");
        printf("|||                    |:| ISBN do livro: ");

        do {
            scanf(" %13[^\n]", liv->livroISBN);
            getchar();
        }while(!testaISBN(liv->livroISBN));

        printf("                                                                            |||\n");
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
        printf("||| Livro não consta no banco de dados...");
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
        printf("||| Livro não consta no banco de dados...");
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
        printf("||| Livro não consta no banco de dados...");
        getchar();

    }else{

        liv = tela_CadLivros(liv);
        strcpy(liv->livroISBN, isbn);
        recadastrarLivro(liv);
        free(liv);

    }
    free(isbn);
}

// Exclusões

void excluirLivros(void) {
    Livro* liv;
    liv = (Livro*) malloc(sizeof(Livro));
	char* isbn;

	isbn = insereISBN();
	liv = procuraLivro_ISBN(isbn);

	if (liv == NULL) {

    	clearscr();
        printf("||| Livro não consta no banco de dados...");
        getchar();

  	}else{

        liv->status = '0';
        recadastrarLivro(liv);
        free(liv);
        clearscr();
        printf("||| Livro excluido com sucesso!");
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
		if ((strcmp(liv->livroTitulo, titulo) == 0) && (liv->status == '1')) {

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
		if ((strcmp(liv->livroISBN, isbn) == 0) && (liv->status == '1')) {
			fclose(arq);
			return liv;
		}
	}
    
	fclose(arq);
	return NULL;
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

