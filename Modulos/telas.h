#include <time.h>
#include "menuLivros.h"
#include "menuUsuarios.h"
#include "menuEmprestimos.h"


char* insereISBN(void);
char* insereTitulo(void);
char* insereCPF(void);
void mcadastroLivro (Livro*);
void mcadastroLivro_Empr (Livro*);
void mcadastroUsuario_Empr (Usuario*);
void mcadastroUsuario (Usuario*);
void mcadastroEmprestimo (Emprestimo*);
void arq_msgErro(void);


