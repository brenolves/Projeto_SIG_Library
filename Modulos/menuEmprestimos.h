// Módulo Empréstimos

struct emprestimo {
    char empr_CPF[12];
    char empr_ISBN[14];
    int empr_Data[3];
    int empr_DataVal[3];
    int empr_Hora[3];
    char status;
};

typedef struct emprestimo Emprestimo;


Emprestimo* procuraEmprestimo_CPF(char*);
Emprestimo* procuraEmprestimo_ISBN(char*);
int procuraCadEmpr_ISBN(char*);
int procuraISBN_E(char*);
void guardarEmprestimo(Emprestimo*);
Emprestimo* tela_CadEmpr(Emprestimo*);
void recadastrarEmpr(Emprestimo*);
int procuraCPF_E(char*);

char menuEmprestimos(void);

    void efetuarEmprestimos(void);

    char pesquisaEmprestimos(void);
        void pesquisaEmpr_ISBN(void);
        void pesquisaEmpr_CPF(void);

    void atualizaEmprestimos(void);


    void finalizaEmprestimos(void);
