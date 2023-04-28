typedef struct lstdep LstDep;
typedef struct produto Produto;
typedef struct departamento Dep;
typedef struct lstprod LstProd;

LstDep* lstdep_cria();

LstProd* lstprod_cria();

LstDep* lst_ler();

Dep* aloca_dep();

Produto* aloca_prod();

void lst_imprime_txt(LstDep* l);

LstProd* ler_prod(char* linha);

LstDep* ler_dep(char* linha);