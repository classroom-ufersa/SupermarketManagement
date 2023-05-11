
typedef struct departamento Departamento;

Departamento* ler_linha_departamento(char* linha);

Departamento* ler_departamento_txt(void);

Departamento* ler_linha_departamento(char* linha);

Departamento* aloca_departamento(void);

Departamento* ler_txt();

void lista_departamento_imprime(Departamento* departamento);

Departamento* ler_produto_txt(Departamento* departamento);

void insere_novo_produto(Departamento* departamento, char* tipo, char* validade, char* fabricacao, int estoque, char* nome_departamento, float preco);

Produto* busca_produto(Departamento* departamento, char* nome_produto);

int verifica_departamento_vazio(Departamento* departamento);

void verifica_produtos_estoque(Departamento* departamento, char*nome_departamento);

void remove_produto(Departamento* departamento, char* nome_produto);

void lista_imprime_txt(Departamento* departamentos);

void produtos_por_departamento(Departamento* departamento);

void libera_memoria(Departamento* departamento);

void imprime_menu_edita();

void editar_produto(Departamento* departamento, char* nome_produto);

void imprime_no_arquivo_produto(Departamento* departamento);

void imprime_no_arquivo_departamento(Departamento* departamento);

int verifica_departamento_existe(Departamento* departamento, char* nome_departamento);