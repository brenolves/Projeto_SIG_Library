// Módulo Livros


typedef struct livro Livro;


struct livro {
    char livroTitulo[81];
    char livroAutor[51];
    char livroGenero[31];
    char livroISBN[14];
    int  livroDataCad[3];
    int  livroHoraCad[3];
    char status;
};

Livro* procuraLivro_Titulo(char*);
Livro* procuraLivro_ISBN(char*);
int procuraISBN(char*);
Livro* tela_CadLivros(Livro*);
Livro* tela_RecadLivros(Livro*);

void guardarLivro(Livro*);
void recadastrarLivro(Livro*);

char menuLivros(void);
    void cadastroLivros();
    char menu_pesqLivros(void);
        void pesquisaLivros_Titulo(void);
        void pesquisaLivros_ISBN(void);

    void atualizaLivros(void);

    void excluirLivros(void);


