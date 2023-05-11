
typedef struct departamento Departamento;
// recebe a linha que leu do aquivo departamento aloca um departamento e retorna o departamento preenchido;
Departamento* ler_linha_departamento(char* linha);

Departamento* ler_departamento_txt(void);

Departamento* ler_linha_departamento(char* linha);

// aloca um departamento
Departamento* aloca_departamento(void);

// chama as funções que lêem dos aquivo
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
// libera a memoria alocada 
void libera_memoria(Departamento* departamento);

// imprime o menu de ediçao do produto
void imprime_menu_edita();

// função para editar um produto que esteja cadastrado
void editar_produto(Departamento* departamento, char* nome_produto);

// imprime no departamento 
void imprime_no_arquivo_produto(Departamento* departamento);

void imprime_no_arquivo_departamento(Departamento* departamento);

int verifica_departamento_existe(Departamento* departamento, char* nome_departamento);