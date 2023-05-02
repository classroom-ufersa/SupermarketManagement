#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "produto.c"

typedef struct listaprodutos ListaProdutos;

struct listaprodutos{
   Produto* info;
   ListaProdutos* prox_prod;
};

ListaProdutos* lstprod_cria(){
  ListaProdutos* novo = (ListaProdutos*)malloc(sizeof(ListaProdutos));
  if(novo == NULL){
    printf("erro!!\n");
    exit(1);
  }
  novo->prox_prod = NULL;
  novo->info = aloca_produto(); 
  return novo;
}

ListaProdutos* ler_produto(char* linha){
  ListaProdutos* p = lstprod_cria();
  if(p == NULL){
    printf("Erro!!!\n");
    exit(1);
  }
  sscanf(linha," %[^|]| %[^|]| %[^|]| %[^|]| %f", p->info->tipo, p->info->fabricacao, p->info->validade, p->info->estoque, &p->info->preco);
  return p;
}