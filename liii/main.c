#include <stdio.h>
#include "lista.c"

int main(void) {
  
  LstDep* lista_departamentos = lst_ler();
  lst_imprime_txt(lista_departamentos);
  
  return 0;
}