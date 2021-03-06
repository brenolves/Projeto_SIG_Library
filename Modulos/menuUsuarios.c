#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "clearscr.h"
#include "moduloValida.h"
#include "telas.h"

// Módulo Usuários

char menuUsuarios(void) {
    char opMenu;
        
    clearscr();
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||                                                                         |||\n");
    printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                             Menu Usuarios                               |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                                                                         |||\n");
    printf("|||                    |#| 1 - Cadastrar um usuario                         |||\n");
    printf("|||                    |#| 2 - Pesquisar um usuario                         |||\n");
    printf("|||                    |#| 3 - Atualizar cadastro de um usuario             |||\n");
    printf("|||                    |#| 4 - Excluir cadastro de um usuario               |||\n");
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

void cadastroUsuarios(void) {
    Usuario* user;
    int tentar = 0;

    // Checar se existe memória disponível.
    do{
        user = (Usuario*) malloc(sizeof(Usuario));
        if (user == NULL) {
            tentar = memoriaAlocada();
        }
    } while(tentar == 1);

    user = tela_CadUsuario(user);
    guardarUsuario(user);
    free(user);
    
}

Usuario* tela_CadUsuario(Usuario* user) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                          Cadastrar Usuarios                             |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        
        do {
            printf("                    |:| Nome do usuário: ");
            scanf(" %50[^\n]", user->usuarioNome);
            getchar();
        }while (!testaNome(user->usuarioNome));

        do {
            printf("                    |:| Data de nascimento do usuário: \n");
            printf("                    |:| Dia: ");
            scanf(" %d", &user->usuarioDataNasc[0]);
            getchar();

            printf("                    |:| Mês: ");
            scanf(" %d", &user->usuarioDataNasc[1]);
            getchar();

            printf("                    |:| Ano: ");
            scanf(" %d", &user->usuarioDataNasc[2]);
            getchar();
        }while (!testaData(user->usuarioDataNasc[0],user->usuarioDataNasc[1],user->usuarioDataNasc[2]));

        do{
            printf("                    |:| CPF do usuário (Somente números): ");
            scanf(" %11[^\n]", user->usuarioCPF);
            getchar();
        }while ((!testaCPF(user->usuarioCPF)) || (!procuraCPF(user->usuarioCPF)));

        user->usuarioDataCad[0] = data.tm_mday;
        user->usuarioDataCad[1] = data.tm_mon + 1;
        user->usuarioDataCad[2] = data.tm_year + 1900;

        user->usuarioHoraCad[0] = data.tm_hour;
        user->usuarioHoraCad[1] = data.tm_min;
        user->usuarioHoraCad[2] = data.tm_sec;

        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        user->status = '1';

        mcadastroUsuario(user);

        return user;
}

Usuario* tela_RecadUsuario(Usuario* user) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);
    clearscr();
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||                                                                         |||\n");
        printf("|||              =||=||=||=||=|| SIG-Library ||=||=||=||=||=                |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                          Cadastrar Usuarios                             |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        
        do {
            printf("                    |:| Nome do usuário: ");
            scanf(" %50[^\n]", user->usuarioNome);
            getchar();
        }while (!testaNome(user->usuarioNome));

        do {
            printf("                    |:| Data de nascimento do usuário: \n");
            printf("                    |:| Dia: ");
            scanf(" %d", &user->usuarioDataNasc[0]);
            getchar();

            printf("                    |:| Mês: ");
            scanf(" %d", &user->usuarioDataNasc[1]);
            getchar();

            printf("                    |:| Ano: ");
            scanf(" %d", &user->usuarioDataNasc[2]);
            getchar();
        }while (!testaData(user->usuarioDataNasc[0],user->usuarioDataNasc[1],user->usuarioDataNasc[2]));

        user->usuarioDataCad[0] = data.tm_mday;
        user->usuarioDataCad[1] = data.tm_mon + 1;
        user->usuarioDataCad[2] = data.tm_year + 1900;

        user->usuarioHoraCad[0] = data.tm_hour;
        user->usuarioHoraCad[1] = data.tm_min;
        user->usuarioHoraCad[2] = data.tm_sec;


        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||                                                                         |||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n");
        user->status = '1';

        mcadastroUsuario(user);

        return user;
}

// Pesquisas

void pesquisaUsuarios(void) {
    char* cpf;
    Usuario* user;

    cpf = insereCPF();
    user = procuraUsuario(cpf);

    if (user == NULL) {
        clearscr();
        printf("                    Usuário não consta no banco de dados...");
        getchar();
    }else{
        mcadastroUsuario(user);
    }
    free(cpf);
    free(user);
}

// Atualizações

void atualizaUsuarios(void) {
    Usuario* user;
    char* cpf;

    cpf = insereCPF();
    user = procuraUsuario(cpf);

    if (user == NULL) {

        clearscr();
        printf("                    Usuario não consta no banco de dados...");
        getchar();

    }else{

        mcadastroUsuario(user);
        user = tela_RecadUsuario(user);
        strcpy(user->usuarioCPF, cpf);
        recadastrarUsuario(user);
        free(user);

    }
    free(cpf);
}
// Exclusões

void excluirUsuarios(void) {
    time_t t = time(NULL);
    struct tm data = *localtime(&t);

    Usuario* user;
    user = (Usuario*) malloc(sizeof(Usuario));
	char* cpf;

	cpf = insereCPF();
	user = procuraUsuario(cpf);

	if (user == NULL) {

    	clearscr();
        printf("                    Usuário não consta no banco de dados...");
        getchar();

  	}else{
        mcadastroUsuario(user);    

        user->usuarioDataCad[0] = data.tm_mday;
        user->usuarioDataCad[1] = data.tm_mon + 1;
        user->usuarioDataCad[2] = data.tm_year + 1900;

        user->usuarioHoraCad[0] = data.tm_hour;
        user->usuarioHoraCad[1] = data.tm_min;
        user->usuarioHoraCad[2] = data.tm_sec;

        user->status = '0';
        recadastrarUsuario(user);
        free(user);
        clearscr();
        printf("                    Usuário excluido com sucesso!");
        getchar();

	}
	free(cpf);
}

// Funções gerais de amplo propósito(Podem ser usadas em outros módulos)

void guardarUsuario(Usuario* user) {
	FILE* arq;

	arq = fopen("usuarios.dat", "ab");
	if (arq == NULL) {
		arq_msgErro();
	}
	fwrite(user, sizeof(Usuario), 1, arq);
	fclose(arq);
}


Usuario* procuraUsuario(char* cpf) {
    Usuario* user;
    FILE* arq;

    user = (Usuario*) malloc(sizeof(Usuario));
    arq = fopen("usuarios.dat", "rb");

    if (arq == NULL) {
        arq_msgErro();
    }

	while(fread(user, sizeof(Usuario), 1, arq)) {
		if ((strcmp(user->usuarioCPF, cpf) == 0) && (user->status == '1')) {
			fclose(arq);
			return user;
		}
	}
    
	fclose(arq);
	return NULL;
}

int procuraCPF(char* cpf) {
    Usuario* user;
    FILE* arq;

    user = (Usuario*) malloc(sizeof(Usuario));
    arq = fopen("usuarios.dat", "rb");

    if (arq == NULL) {
        arq = fopen("usuarios.dat", "wb");
    }

	while(fread(user, sizeof(Usuario), 1, arq)) {
		if ((strcmp(user->usuarioCPF, cpf) == 0) && (user->status == '1')) {
			fclose(arq);
            printf("                    Já existe um cadastro com este CPF!\n");
            printf("                    Insira outro CPF! \n");
			return 0;
		}
	}
    
	fclose(arq);
	return 1;
}

void recadastrarUsuario(Usuario* user) {
	int existe;
	FILE* arq;
    
	Usuario* userLido;
    userLido = (Usuario*) malloc(sizeof(Usuario));
	
	arq = fopen("usuarios.dat", "r+b");
	if (arq == NULL) {
		arq_msgErro();
	}

	existe = 0;

	while(fread(userLido, sizeof(Usuario), 1, arq) && !existe) {
		if (strcmp(userLido->usuarioCPF, user->usuarioCPF) == 0) {
			existe = 1;
			fseek(arq, -1*sizeof(Usuario), SEEK_CUR);
        	fwrite(user, sizeof(Usuario), 1, arq);
		}
	}
	fclose(arq);
	free(userLido);
}