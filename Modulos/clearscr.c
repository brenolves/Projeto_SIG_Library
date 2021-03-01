#include <stdio.h>
#include <stdlib.h>

void clearscr(void);

// Função pra limpar a tela que funciona em vários SO's. Encontrei neste site >> https://stackoverflow.com/questions/18154579/how-do-i-clear-the-screen-in-c/18154598

void clearscr(void) {

#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
    #error "Sistema operacional não suportado."
#endif

}