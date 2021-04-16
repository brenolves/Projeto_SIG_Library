// Módulo Empréstimos

struct emprestimo {
    char empr_CPF[51];
    char empr_ISBN[14];
    char empr_Data[11];
    char status;
};

typedef struct emprestimo Emprestimo;

void guardarEmprestimo(Emprestimo*);
Emprestimo* tela_CadEmpr(Emprestimo*);

char menuEmprestimos(void);
    void efetuarEmprestimos(void);
    char pesquisaEmprestimos(void);
        char pesquisaEmprestimos_Nome(void);
        char pesquisaEmprestimos_Livro(void);
        char pesquisaEmprestimos_Data(void);
    char atualizaEmprestimos(void);
        char atualizaEmprestimos_Nome(void);
        char atualizaEmprestimos_Livro(void);
        char atualizaEmprestimos_Data(void);
    char finalizaEmprestimos(void);
        char finalizaEmprestimos_Nome(void);
        char finalizaEmprestimos_Livro(void);
        char finalizaEmprestimos_Data(void);