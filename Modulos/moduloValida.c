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

// Adaptado de @flgorgonio
int testaData(int dd, int mm, int aa){
  int maiorDia;
  if (aa <= 0 || mm < 1 || mm > 12) {
    printf("|||                    Data inválida!\n");
    printf("|||                    Tente novamente!\n");
    printf("|||                                         \n");
    return 0;
  }
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

  if (dd < 1 || dd > maiorDia){
    printf("|||                    Data inválida!\n");
    printf("|||                    Tente novamente!\n");
    printf("|||                                         \n");
    return 0;
  }
  return 1;
}
// Adaptado de @flgorgonio
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
    printf("|||                                         \n");
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
      printf("|||                                         \n");
      return 0;
   }
  } 
  return 1;
}

//Função de validar CPF; Créditos: https://gist.github.com/eduardoedson/8f991b6d234a9ebdcbe3?fbclid=IwAR3OBKAv5jI9yHu4BgGcuTTZeNzdiPBTaobZIHXBX-BtWJX_xnXT2jEGiXc
int testaCPF(char* cpf) {
  int i, j, digito1 = 0, digito2 = 0;

  if(strlen(cpf) != 11)
      return 0;
  else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
          (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
          (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
          (strcmp(cpf,"99999999999") == 0))
      return 0; ///se o CPF tiver todos os números iguais ele é inválido.
  else
  {
      ///digito 1---------------------------------------------------
      for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
          digito1 += (cpf[i]-48) * j;
      digito1 %= 11;
      if(digito1 < 2)
          digito1 = 0;
      else
          digito1 = 11 - digito1;
      if((cpf[9]-48) != digito1)
          return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
      else
      ///digito 2--------------------------------------------------
      {
          for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                  digito2 += (cpf[i]-48) * j;
      digito2 %= 11;
      if(digito2 < 2)
          digito2 = 0;
      else
          digito2 = 11 - digito2;
      if((cpf[10]-48) != digito2)
          return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
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

