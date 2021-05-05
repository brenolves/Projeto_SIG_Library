#include <stdio.h>
#include <stdlib.h>
#include "Modulos/menuLivros.h"
#include "Modulos/menuUsuarios.h"
#include "Modulos/menuEmprestimos.h"
#include "Modulos/clearscr.h"
#include "Modulos/moduloRelatorios.h"
#include "Modulos/moduloValida.h"

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
int moduloUsuarios_Pesq(void);
int moduloUsuarios_Atual(void);
int moduloUsuarios_Exclu(void);
// Módulo Empréstimos
int moduloEmprestimos(void);
int moduloEmprestimos_Pesq(void);
int moduloEmprestimos_Atual(void);
int moduloEmprestimos_Exclu(void);
// Módulo Relatórios
int moduloRelatorios(void);
int moduloRelatoriosCad(void);
int moduloRelatoriosExc(void);

/////////////////////////////////////////////////

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

        case '4':
            moduloRelatorios();
            break;

        case '5':
            menuAbout();
            break;

        case '0':
            continue;

        default:
            validaMenu();
        }
    }
    while (opMenuP != '0');
    printf("Programa Encerrado!\n");

    return 0;

}

//  Interfaces e funcionalidades do programa.

char menuPrincipal(void) {
    char opMenu;

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
    printf("|||                    |#| 4 - Relatórios                                   |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||        5 - Sobre o programa         |:|          0 - Encerrar           |||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("||| Escolha sua opção: ");
    scanf("%[0-9]", &opMenu);
    getchar();


    return opMenu;
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
        printf("|||  -préstimo, prazos de devolução, livros e usuários cadastrados.         |||\n");
        printf("|||                                                                         |||\n");
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
                atualizaLivros();
                break;

            case '4':
                excluirLivros();
                break;

            case '0':
                continue;

            default:
                validaMenu();
            }
    }while (opModulo_L != '0');
    return 0;
}

int moduloLivros_Pesq(void){
    char opModulo_L;
    do{
        opModulo_L = menu_pesqLivros();
        switch(opModulo_L){
            case '1':
                pesquisaLivros_Titulo();
                break;

            case '2':
                pesquisaLivros_ISBN();
                break;

            case '0':
            continue;

            default:
                validaMenu();
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
                pesquisaUsuarios();
                break;

            case '3':
                atualizaUsuarios();
                break;

            case '4':
                excluirUsuarios();
                break;

            case '0':
                continue;

            default:
                validaMenu();
            }
    }while (opModulo_U != '0');
    return 0;
}


int moduloEmprestimos(void){
    char opModulo_E;
    do{
        opModulo_E = menuEmprestimos();
        switch(opModulo_E){
            case '1':
                efetuarEmprestimos();
                break;

            case '2':
                moduloEmprestimos_Pesq();
                break;

            case '3':
                atualizaEmprestimos();
                break;

            case '4':
                finalizaEmprestimos();
                break;

            case '0':
            continue;

            default:
                validaMenu();
            }   
    }while (opModulo_E != '0');
    return 0;
}

int moduloEmprestimos_Pesq(void){
    char opModulo_E;
    do{
        opModulo_E = pesquisaEmprestimos();
        switch(opModulo_E){
            case '1':
                pesquisaEmpr_CPF();
                break;

            case '2':
                pesquisaEmpr_ISBN();
                break;

            case '0':
                continue;
            
            default:
                validaMenu();
            }
    }while (opModulo_E != '0');
    return 0;
}


int moduloRelatorios(void) {
    char opModulo_R;
    do{
        opModulo_R = menuRelatorios();
        switch(opModulo_R){
            case '1':
                moduloRelatoriosCad();
                break;
            case '2':
                moduloRelatoriosExc();
                break;
            case '3':
                telaEmpr_Vencidos();
                break;
            case '0':
                continue;
            
            default:
                validaMenu();
            }
    }while (opModulo_R != '0');
    return 0;
}

int moduloRelatoriosCad(void) {
    char opModulo_R;
    do{
        opModulo_R = menuRelatoriosCad();
        switch(opModulo_R){
            case '1':
                telaCadastros_Livros();
                break;
            case '2':
                telaCadastros_Usuarios();
                break;
            case '3':
                telaCadastros_Emprestimos();
                break;
            case '0':
                continue;
            
            default:
                validaMenu();
            }
    }while (opModulo_R != '0');
    return 0;
}

int moduloRelatoriosExc(void) {
    char opModulo_R;
    do{
        opModulo_R = menuRelatoriosExc();
        switch(opModulo_R){
            case '1':
                telaExclu_Livros();
                break;
            case '2':
                telaExclu_Usuarios();
                break;
            case '3':
                telaExclu_Emprestimos();
                break;
            case '0':
                continue;
            
            default:
                validaMenu();
            }
    }while (opModulo_R != '0');
    return 0;
}