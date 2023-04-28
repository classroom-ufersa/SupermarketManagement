#include <stdio.h>
#include "lista.h"
#include "listadepartamento.c"
#include "listaprodutos.c"
#include "produto.c"
#include "departamento.c"


int main(void) {
  
  ListaDepartamento* lista_departamentos = lst_ler();
  lst_imprime_txt(lista_departamentos);
  return 0;
}