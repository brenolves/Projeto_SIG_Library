// Módulo Usuários

struct usuario {
    char usuarioNome[51];
    int usuarioDataNasc[3];
    int usuarioDataCad[3];
    int usuarioHoraCad[3];
    char usuarioCPF[12];
    char status;
};

typedef struct usuario Usuario;

Usuario* procuraUsuario(char*);
int procuraCPF(char*);
void guardarUsuario(Usuario*);
Usuario* tela_CadUsuario(Usuario*);
Usuario* tela_RecadUsuario(Usuario*);
void recadastrarUsuario(Usuario*);




char menuUsuarios(void);
    void cadastroUsuarios(void);
    void pesquisaUsuarios(void);
    void atualizaUsuarios(void);
    void excluirUsuarios(void);
