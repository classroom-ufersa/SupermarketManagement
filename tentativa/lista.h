#include "listadepartamento.c"

ListaDepartamento* lstdep_cria();

ListaDepartamento* ler_departamento(char* linha);

void lst_imprime_txt(ListaDepartamento* l);

ListaDepartamento* lst_ler(void);

void lst_imprime(ListaDepartamento* l);

ListaProdutos* lstprod_cria();

ListaProdutos* ler_produto(char* linha);

Departamento* aloca_departamento(void);

Produto* aloca_produto(void);