#include "produto.c"
typedef struct listaprodutos ListaProdutos;

struct listaprodutos{
   Produto* info;
   ListaProdutos* prox_prod;
};