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
    liv = procuraLivro_ISBN(titulo);

    if (liv == NULL) {
        printf("||| Livro não consta no banco de dados...");
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
        printf("||| Livro não consta no banco de dados...");
    }else{
        mcadastroLivro(liv);
    }
    free(isbnLivro);
    free(liv);
}

// Atualizações

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

// Exclusões

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
    printf("|||                    |:| 2 - Código do livro                              |||\n");
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
        printf("|||                    |:| ISBN do livro:                                   |||\n");
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

void guardarLivro(Livro* liv) {
	FILE* arq;

	arq = fopen("livros.dat", "ab");
	if (arq == NULL) {
		printf("||| Não foi possível abrir o arquivo de dados...\n");
        printf("||| Fechando programa...\n");
        exit(1);
	}
	fwrite(liv, sizeof(Livro), 1, arq);
	fclose(arq);
}

// Funções gerais de amplo propósito(Usar em outros módulos)

Livro* procuraLivro_Titulo(char* titulo) {
    Livro* liv;
    FILE* arq;

    liv = (Livro*) malloc(sizeof(Livro));
    arq = fopen("livros.dat", "rb");

    if (arq == NULL) {
        printf("||| Não foi possível abrir o arquivo de dados...\n");
        printf("||| Fechando programa...\n");
        exit(1);
    }

	while(fread(arq, sizeof(Livro), 1, arq)) {
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
        printf("||| Não foi possível abrir o arquivo de dados...\n");
        printf("||| Fechando programa...\n");
        exit(1);
    }

	while(fread(arq, sizeof(Livro), 1, arq)) {
		if ((strcmp(liv->livroISBN, isbn) == 0) && (liv->status == '1')) {
			fclose(arq);
			return liv;
		}
	}
    
	fclose(arq);
	return NULL;
}

