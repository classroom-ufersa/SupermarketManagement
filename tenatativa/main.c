#include <stdio.h>
#include"listadepartamento.c"

int main(void) {
  ListaDepartamento* lista_departamentos = lst_ler();
  // lst_imprime_txt(lista_departamentos);
  lst_imprime(lista_departamentos);

  printf("\n\nteste\n\n");
  lst_insere(lista_departamentos, "manga", "02/03/2023fab ", "30/05/2023val","5 disp","medicamento", 5.5);
  lst_imprime_txt(lista_departamentos);
  lst_imprime(lista_departamentos);
  return 0;
}