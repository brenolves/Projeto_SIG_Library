// Módulo Livros


typedef struct livro Livro;


struct livro {
    char livroTitulo[81];
    char livroAutor[51];
    char livroGenero[21];
    char livroISBN[14];
    char status;
};

Livro* procuraLivro_Titulo(char*);
Livro* procuraLivro_ISBN(char*);
Livro* tela_CadLivros(Livro*);
void guardarLivro(Livro*);

char menuLivros(void);
    void cadastroLivros();
    char menu_pesqLivros(void);
        void pesquisaLivros_Titulo(void);
        void pesquisaLivros_ISBN(void);
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
