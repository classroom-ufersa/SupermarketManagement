#include "produto.h"

typedef struct departamento Departamento;

//essa função lê uma linha do departamento e retorna o departamento preenchido com os dados, a linha atual é passada como parametro
Departamento* ler_linha_departamento(char* linha);

//função que lê os dados no arquivo departamentos armazena em um departamento e retorna esse departamento
Departamento* ler_departamento_txt(void);

//aloca um departamento, inicializa ele e retorna
Departamento* aloca_departamento(void);

//lê os arquivos produtos e departamento e armazena os dados no departamento que será retornado
Departamento* ler_txt();

//função responsavel por imprimir todos os prodtos e departamentos que estão no sistema, para isso ela utiliza um departamento que é passado como parametro
void lista_departamento_imprime(Departamento* departamento);

//função que lê os dados do arquivo produtos,o departamento é passado como parametro
Departamento* ler_produto_txt(Departamento* departamento);

//função responsavel por receber todos os dados do produto e inserir ele no sistema
void insere_novo_produto(Departamento* departamento, char* tipo, char* validade, char* fabricacao, int estoque, char* nome_departamento, float preco);

//função responsavel por buscar um produto pelo nome, para isso ela recebe um departamento e o nome do produto que queremos buscar
Produto* busca_produto(Departamento* departamento, char* nome_produto);

//função responsável por verificar se um departamento está vazio ou não
int verifica_departamento_vazio(Departamento* departamento);

//função que verifica a quantidade de produtos que estão em estoque de um determinado departamento, para isso ela recebe o departamento e o nome do departamento que estão os produtos que deseja listar
void verifica_produtos_estoque(Departamento* departamento, char*nome_departamento);

// remove um produto utilizando o nome do produto, essa função recebe um departamento e o nome do produto que deseja retirar 
void remove_produto(Departamento* departamento, char* nome_produto);

//essa função é responsavel por escrever nos arquivos departamentos e produtos, para isso ela recebe o departamento
void imprime_txt(Departamento* departamentos);

//função responsavel por listar a quantidade de produtos de cada departamento, para isso ela recebe um departamento como exemplo
void produtos_por_departamento(Departamento* departamento);

// essa função é responsavel libera memoria alocada, para isso o departamento é passado como parametro
void libera_memoria(Departamento* departamento);

// essa função imprime o menu que auxilia na edição do produto 
void imprime_menu_edita();

// função responsavel por editar um produto, ela recebe um departamento e o nome do produto que deseja editar
void editar_produto(Departamento* departamento, char* nome_produto);

// essa função imprime os dados dos produtos no arquivo produtos.txt, para isso o departamento é passado como parametro
void imprime_no_arquivo_produto(Departamento* departamento);

// essa função imprime os dados dos departamentos no arquivo departamentos.txt, para isso o departamento é passado como parametro
void imprime_no_arquivo_departamento(Departamento* departamento);

//essa função verifica se um departamento especifico existe, para isso ela recebe um departamento e o nome do departamento que deseja verificar se existir
int verifica_departamento_existe(Departamento* departamento, char* nome_departamento);