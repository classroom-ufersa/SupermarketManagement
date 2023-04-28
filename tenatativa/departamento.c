#include "listaprodutos.c"

typedef struct departamento Departamento;

struct departamento{
  char nome[50];
  char porte[20];
  int qtd_prod;
  ListaProdutos* lista_produtos;
};