
typedef struct departamento Departamento;

Departamento* ler_linha_departamento(char* linha);

Departamento* ler_departamento_txt(void);

Departamento* ler_linha_departamento(char* linha);

Departamento* aloca_departamento(void);

void lista_departamento_imprime(Departamento* departamento);

void insere_novo_produto(Departamento* departamento, char* tipo, char* validade, char* fabricacao, int estoque, char* nome_departamento, float preco);

void lista_imprime_txt(Departamento* departamentos);

void produtos_por_departamento(Departamento* departamento);