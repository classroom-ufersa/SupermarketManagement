typedef struct lstdep LstDep;
typedef struct produto Produto;
typedef struct departamento Dep;
typedef struct lstprod LstProd;

#define N 20
#define QD 1

void menu();

LstDep* lstdep_cria();

void lst_ler(LstDep* l);

void lst_insere(LstDep* l, char* tipo, char* validade, char* fabricacao, int estoque, char* nome_departamento, float preco);

void lst_imprime(LstDep* l);

void libera(LstDep* l);