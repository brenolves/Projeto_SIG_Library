// Função pra limpar a tela que funciona em vários SO's. Encontrei neste site >> https://stackoverflow.com/questions/18154579/how-do-i-clear-the-screen-in-c/18154598
void clearscr(void);

// Módulo Livros
char menuLivros(void);
    void cadastroLivros(void);
    char pesquisaLivros(void);
        char pesquisaLivros_Titulo(void);
        char pesquisaLivros_Autor(void);
        char pesquisaLivros_Genero(void);
        int pesquisaLivros_Codigo(void);
    char atualizaLivros(void);
        char atualizaLivros_Titulo(void);
        char atualizaLivros_Autor(void);
        char atualizaLivros_Genero(void);
        int atualizaLivros_Codigo(void);
    char excluirLivros(void);
        char excluirLivros_Titulo(void);
        char excluirLivros_Autor(void);
        char excluirLivros_Genero(void);
        int excluirLivros_Codigo(void);

// Módulo Usuários
char menuUsuarios(void);
    void cadastroUsuarios(void);
    void pesquisaUsuarios(void);
    void atualizaUsuarios(void);
    void excluirUsuarios(void);

// Módulo Empréstimos
char menuEmprestimos(void);
    void efetuarEmprestimos(void);
    void pesquisaEmprestimos(void);
    void atualizaEmprestimos(void);
    void finalizaEmprestimos(void);