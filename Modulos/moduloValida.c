#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "moduloValida.h"
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
// Ainda em desenvolvimento
int testaNome(char nome[]) {
  int tamanho;
  if (strlen(nome) == 0) {
    return 0;
  }
  for (int i = 0; i < strlen(nome); i++) {
    if (isalpha(nome[i])) {
      continue;
   } else {
     return 0;
   }
  } 
  return 1;
}

int testaCodigo(int codigo) {
  if (codigo > 0) {
    return 0;
  } else if (!isdigit(codigo)) {
    return 0;
  }
  return 1;
}