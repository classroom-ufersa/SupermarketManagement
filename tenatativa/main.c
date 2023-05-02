#include <stdio.h>
#include"listadepartamento.c"

int main(void) {
  
  ListaDepartamento* lista_departamentos = lst_ler();
  lst_imprime_txt(lista_departamentos);

  return 0;
}