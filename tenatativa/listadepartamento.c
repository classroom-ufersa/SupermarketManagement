#include "departamento.c"

typedef struct listadepartamento ListaDepartamento;

struct listadepartamento{
  Departamento* info;
  ListaDepartamento* prox;
};