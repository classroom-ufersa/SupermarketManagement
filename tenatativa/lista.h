#include "listadepartamento.c"
#include "listaprodutos.c"
#include "produto.c"
#include "departamento.c"

ListaDepartamento* lstdep_cria();

ListaProdutos* lstprod_cria();

ListaDepartamento* lst_ler();

Departamento* aloca_dep();

Produto* aloca_prod();

void lst_imprime_txt(ListaDepartamento* l);

ListaProdutos* ler_prod(char* linha);

ListaDepartamento* ler_dep(char* linha);