// Módulo Usuários

struct usuario {
    char usuarioNome[51];
    char usuarioDataNasc[11];
    char usuarioCPF[12];
    char status;
};

typedef struct usuario Usuario;

Usuario* procuraUsuario(char*);
void guardarUsuario(Usuario*);
Usuario* tela_CadUsuario(Usuario*);
void recadastrarUsuario(Usuario*);



char menuUsuarios(void);
    void cadastroUsuarios(void);
    void pesquisaUsuarios(void);
    void atualizaUsuarios(void);
    void excluirUsuarios(void);
