// Módulo Empréstimos

struct emprestimo {
    char empr_CPF[51];
    char empr_ISBN[14];
    int empr_Data[3];
    char status;
};

typedef struct emprestimo Emprestimo;


Emprestimo* procuraEmprestimo_CPF(char*);
Emprestimo* procuraEmprestimo_ISBN(char*);
void guardarEmprestimo(Emprestimo*);
Emprestimo* tela_CadEmpr(Emprestimo*);


char menuEmprestimos(void);

    void efetuarEmprestimos(void);

    char pesquisaEmprestimos(void);
        void pesquisaEmpr_ISBN(void);
        void pesquisaEmpr_CPF(void);

    char atualizaEmprestimos(void);
        char atualizaEmprestimos_Nome(void);

    char finalizaEmprestimos(void);
        char finalizaEmprestimos_Nome(void);