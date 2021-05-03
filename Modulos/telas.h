#include <time.h>
#include "menuLivros.h"
#include "menuUsuarios.h"
#include "menuEmprestimos.h"


char* insereISBN(void);
char* insereTitulo(void);
char* insereCPF(void);
void mcadastroLivro (const Livro*);
void mcadastroLivro_Empr (const Livro*);
void mcadastroUsuario_Empr (const Usuario*);
void mcadastroUsuario (const Usuario*);
void mcadastroEmprestimo (const Emprestimo*);
void arq_msgErro(void);


