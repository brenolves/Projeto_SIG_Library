#include <stdio.h>
#include <stdlib.h>
#include "Modulos/menuLivros.h"
#include "Modulos/menuUsuarios.h"
#include "Modulos/menuEmprestimos.h"
#include "Modulos/clearscr.h"
#include "Modulos/moduloRelatorios.h"

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

// Variáveis
char livroTitulo[] = "Neuromancer: 1", livroAutor[] = "William Gibson", livroGenero[] = "Ficção Científica";
int livroCodigo = 124123124, n = 5;

char nome[] = "Breno", datanasc[] = "30/04/1999";
int usuarioCodigo = 245325435;

char dataemprestimo[] = "24/03/2021";




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
        printf("|||                    |#| 4 - Relatórios                                   |||\n");
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

int moduloUsuarios_Pesq(void){
    char opModulo_U;
    do{
        opModulo_U = pesquisaUsuarios();
        switch(opModulo_U){
            case '1':
            pesquisaUsuarios_Nome();
            break;
            case '2':
            pesquisaUsuarios_Nasc();
            break;
            case '3':
            pesquisaUsuarios_Codigo();
            break;
            case '5':
            break;
        }
    }while (opModulo_U != '0');
    return 0;
}

int moduloUsuarios_Atual(void){
    char opModulo_U;
    do{
        opModulo_U = atualizaUsuarios();
        switch(opModulo_U){
            case '1':
            atualizaUsuarios_Nome();
            break;
            case '2':
            pesquisaUsuarios_Nasc();
            break;
            case '3':
            pesquisaUsuarios_Codigo();
            break;
            case '5':
            break;
        }
    }while (opModulo_U != '0');
    return 0;
}

int moduloUsuarios_Exclu(void){
    char opModulo_U;
    do{
        opModulo_U = excluirUsuarios();
        switch(opModulo_U){
            case '1':
            excluirUsuarios_Nome();
            break;
            case '2':
            excluirUsuarios_Nasc();
            break;
            case '3':
            excluirUsuarios_Codigo();
            break;
            case '5':
            break;
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
            moduloEmprestimos_Atual();
            break;
            case '4':
            moduloEmprestimos_Exclu();
            break;
            case '5':
            main();
            break;
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
            pesquisaEmprestimos_Nome();
            break;
            case '2':
            pesquisaEmprestimos_Livro();
            break;
            case '3':
            pesquisaEmprestimos_Data();
            break;
            case '5':
            break;
        }
    }while (opModulo_E != '0');
    return 0;
}

int moduloEmprestimos_Atual(void){
    char opModulo_E;
    do{
        opModulo_E = atualizaEmprestimos();
        switch(opModulo_E){
            case '1':
            atualizaEmprestimos_Nome();
            break;
            case '2':
            atualizaEmprestimos_Livro();
            break;
            case '3':
            atualizaEmprestimos_Data();
            break;
            case '5':
            break;
        }
    }while (opModulo_E != '0');
    return 0;
}

int moduloEmprestimos_Exclu(void){
    char opModulo_E;
    do{
        opModulo_E = finalizaEmprestimos();
        switch(opModulo_E){
            case '1':
            finalizaEmprestimos_Nome();
            break;
            case '2':
            finalizaEmprestimos_Livro();
            break;
            case '3':
            finalizaEmprestimos_Data();
            break;
            case '5':
            break;
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
            listaCadastros_Livros(livroTitulo, livroAutor, livroGenero, livroCodigo, n);
            break;
            case '2':
            listaCadastros_Usuarios(nome, datanasc, usuarioCodigo, n);
            break;
            case '3':
            listaEmprestimos(nome, livroTitulo, dataemprestimo, n);
            break;
        }
    }while (opModulo_R != '0');
    return 0;
}