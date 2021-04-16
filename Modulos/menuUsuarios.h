// Módulo Usuários

struct usuario {
    char usuarioNome[51];
    char usuarioDataNasc[11];
    char usuarioCPF[12];
    char status;
};

typedef struct usuario Usuario;


void guardarUsuario(Usuario*);
Usuario* tela_CadUsuario(Usuario*);



char menuUsuarios(void);
    void cadastroUsuarios(void);
    char pesquisaUsuarios(void);
        char pesquisaUsuarios_Nome(void);
        char pesquisaUsuarios_Nasc(void);
        int pesquisaUsuarios_Codigo(void);
    char atualizaUsuarios(void);
        char atualizaUsuarios_Nome(void);
        char atualizaUsuarios_Nasc(void);
        int atualizaUsuarios_Codigo(void);
    char excluirUsuarios(void);
        char excluirUsuarios_Nome(void);
        char excluirUsuarios_Nasc(void);
        int excluirUsuarios_Codigo(void);