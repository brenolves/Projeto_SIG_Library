#include <stdio.h>
#include <stdlib.h>
#include "Modulos\siglibrary.h"

////  Assinatura de funções.

// Menú Principal e Tela Sobre.
char menuPrincipal(void);
void menuAbout(void);
// Módulo Livros.
int moduloLivros(void);
int moduloLivros_Pesq(void);
int moduloLivros_Atual(void);
int moduloLivros_Exclu(void);
// Módulo Usuários
int moduloUsuarios(void);
void moduloUsuarios_Pesq(void);
void moduloUsuarios_Atual(void);
void moduloUsuarios_Exclu(void);
// Módulo Empréstimos
int moduloEmprestimos(void);
void moduloEmprestimos_Pesq(void);
void moduloEmprestimos_Atual(void);
void moduloEmprestimos_Exclu(void);


void clearscr(void);

// Função principal.

int main(void) {
    char opMenuP;

    do{
    opMenuP = menuPrincipal();
    switch (opMenuP){
        case '1':
            moduloLivros();
            break;
        case '2':
            moduloUsuarios();
            break;
        case '3':
            moduloEmprestimos();
            break;
        case '5':
            menuAbout();
            break;
        }
    }
    while (opMenuP != '0');
    printf("Programa Encerrado!\n");

    return 0;

}

//  Interfaces e funcionalidades do programa.

char menuPrincipal(void) {
    char opMenuP;
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                            Menu Principal                               |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                    |#| 1 - Livros                                       |||\n");
        printf("|||                    |#| 2 - Usuários                                     |||\n");
        printf("|||                    |#| 3 - Empréstimos                                  |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||        5 - Sobre o programa         |:|          0 - Encerrar           |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Escolha sua opção:  \n");
        scanf("%[0-9]", &opMenuP);
        getchar();

        return opMenuP;
}

void menuAbout(void) {
    clearscr();
        printf("\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||               =||=||=||=||=|| SIG-Library ||=||=||=||=||=               |||\n");
        printf("|||                                                                         |||\n");
        printf("|||  Projeto criado no intuito de prover um melhor gerenciamento de         |||\n");
        printf("|||  bibliotecas, gerindo o cadastro de novos livros, empréstimos de livros,|||\n");
        printf("|||  e os usuários da biblioteca, podendo também navegar pelas datas de em- |||\n");
        printf("|||  -préstimo, prazos de devolução, livros disponíveis e usuários          |||\n");
        printf("|||  cadastrados.                                                           |||\n");
        printf("|||                                                                         |||\n");
        printf("|||     Desenvolvido por @brenolves                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        printf("||| Aperte ENTER para voltar para o menu principal...\n");
        getchar();
}

int moduloLivros(void){
    char opModulo_L;
    do{
        opModulo_L = menuLivros();
        switch(opModulo_L){
            case '1':
            cadastroLivros();
            break;
            case '2':
            moduloLivros_Pesq();
            break;
            case '3':
            moduloLivros_Atual();
            break;
            case '4':
            moduloLivros_Exclu();
            break;
            case '5':
            main();
            break;
        }
    }while (opModulo_L != '0');
    return 0;
}

int moduloLivros_Pesq(void){
    char opModulo_L;
    do{
        opModulo_L = pesquisaLivros();
        switch(opModulo_L){
            case '1':
            pesquisaLivros_Titulo();
            break;
            case '2':
            pesquisaLivros_Autor();
            break;
            case '3':
            pesquisaLivros_Genero();
            break;
            case '4':
            pesquisaLivros_Codigo();
            break;
            case '5':
            break;
        }
    }while (opModulo_L != '0');
    return 0;
}

int moduloLivros_Atual(void){
    char opModulo_L;
    do{
        opModulo_L = atualizaLivros();
        switch(opModulo_L){
            case '1':
            atualizaLivros_Titulo();
            break;
            case '2':
            atualizaLivros_Autor();
            break;
            case '3':
            atualizaLivros_Genero();
            break;
            case '4':
            atualizaLivros_Codigo();
            break;
            case '5':
            break;
        }
    }while (opModulo_L != '0');
    return 0;
}

int moduloLivros_Exclu(void){
    char opModulo_L;
    do{
        opModulo_L = excluirLivros();
        switch(opModulo_L){
            case '1':
            excluirLivros_Titulo();
            break;
            case '2':
            excluirLivros_Autor();
            break;
            case '3':
            excluirLivros_Genero();
            break;
            case '4':
            excluirLivros_Codigo();
            break;
            case '5':
            break;
        }
    }while (opModulo_L != '0');
    return 0;
}

int moduloUsuarios(void){
    char opModulo_U;
    do{
        opModulo_U = menuUsuarios();
        switch(opModulo_U){
            case '1':
            cadastroUsuarios();
            break;
            case '2':
            moduloUsuarios_Pesq();
            break;
            case '3':
            moduloUsuarios_Atual();
            break;
            case '4':
            moduloUsuarios_Exclu();
            break;
            case '5':
            main();
            break;
        }
    }while (opModulo_U != '0');
    return 0;
}

int moduloEmprestimos(void){
    char opModulo_L;
    do{
        opModulo_L = menuEmprestimos();
        switch(opModulo_L){
            case '1':
            efetuarEmprestimos();
            break;
            case '2':
            moduloEmprestimos_Pesq();
            break;
            case '3':
            moduloEmprestimos_Atual();
            break;
            case '4':
            moduloEmprestimos_Exclu();
            break;
            case '5':
            main();
            break;
        }
    }while (opModulo_L != '0');
    return 0;
}