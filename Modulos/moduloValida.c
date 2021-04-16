#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "moduloValida.h"
#include "clearscr.h"
#include "menuLivros.h"
#include "menuUsuarios.h"
#include "menuEmprestimos.h"
//////////////////////////////////////////////////////////////

// Feito por @flgorgonio
int testaData(int dd, int mm, int aa){
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (bissexto(aa)){
        maiorDia = 29;
    } 
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || 
             mm == 9 || mm == 11){
               maiorDia = 30;
  } else
    maiorDia = 31;

  if (dd < 1 || dd > maiorDia)
    return 0;

  return 1;
}
// Feito por @flgorgonio
int bissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)){
    return 1;
  } else if (aa % 400 == 0){
    return 1;
  } else {
    return 0;
  }
}

int testaHora(int hora, int minuto){
    if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59){
        return 0;
    }
    return 1;
}

int testaNome(char nome[]) {
  if (strlen(nome) == 0) {
    printf("|||                    Nome inválido!\n");
    printf("|||                    Tente novamente!\n");
    printf("|||                                         ");
    return 0;
  }
  for (int i = 0; i < strlen(nome); i++) {
    if (isalpha(nome[i])) {
      continue;
    } else if (!isdigit(nome[i])) {
      continue;
    } else {
      printf("|||                    Nome inválido!\n");
      printf("|||                    Tente novamente!\n");
      printf("|||                                         ");
      return 0;
   }
  } 
  return 1;
}

int testaCPF(char* codigo) {
  int tam = strlen(codigo);
  for (int i = 0;i < tam; i++) {
    if (codigo[i] >= 48 && codigo[i] <= 57) {
      continue;
    }
    else if (tam == 11){
      continue;
    }
    else {
      return 0;
    }
  }
  return 1;
}

int validaOpcao(char opcao) {
  if (opcao >= '0' && opcao <= '9') {
    return 1;
  } else {
    return 0;
  }
}

int memoriaAlocada(void) {
  char tentar;
  printf("Memória insuficiente!\n");
  printf("Deseja tentar denovo?\n");
  printf("1 = Sim       0 = Não\n");
  printf(">> ");
  scanf("%[0-1]", &tentar);
  printf("\n");
  return tentar;
}

int testaTitulo(char* titulo) {
  if (strlen(titulo) == 0) {
    printf("|||                    Título inválido!\n");
    printf("|||                    Tente novamente!\n");
    printf("|||                                         ");
    return 0;
  }
  for (int i = 0; i < strlen(titulo); i++) {
    if ((isalpha(titulo[i])) || (isdigit(titulo[i]))) {
      break;
   } else {
      printf("|||                    Título inválido!\n");
      printf("|||                    Tente novamente!\n");
      printf("|||                                         ");
      return 0;
   }
  } 
  return 1;
}

int testaISBN(char* isbn) {
  int tam = strlen(isbn);
  if (tam > 13 || tam < 13) {
    printf("|||                    ISBN inválido!\n");
    printf("|||                    Tente novamente!\n");
    printf("|||                                         ");
    return 0;
  }
  return 1;
}

int testaDataNasc(char* nasc) {
  int tam = strlen(nasc);
  if (tam > 10 || tam < 10) {
    printf("|||                    Data de nascimento inválida!\n");
    printf("|||                    Tente novamente!\n");
    printf("|||                                         ");
    return 0;
  }

  for (int i=0; i<=tam; i++) {
    if (nasc[i] >= 47 && nasc[i] <= 57) {
      continue;
    }else if ((nasc[2] == '/') && (nasc[5] == '/')) {
      break;
    }else {
      printf("|||                    Data de nascimento inválida!\n");
      printf("|||                    Tente novamente!\n");
      printf("|||                                         ");
      return 0;
    }
  }
  return 1;
}

void validaMenu(void) {
  printf("\n");
  clearscr();
  printf("Opção Inválida!\n");
  printf("Aperte ENTER para voltar para o menú.");
  getchar();
}