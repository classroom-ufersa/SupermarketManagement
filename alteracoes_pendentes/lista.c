#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lstdep LstDep;
typedef struct produto Produto;
typedef struct departamento Dep;
typedef struct lstprod LstProd;

#define N 20

struct lstdep{
  Dep* info;
  LstDep* prox;
};

struct lstprod{
   Produto* info;
   LstProd* prox_prod;
};

struct produto{
  char tipo[N];
  float preco;
  char fabricacao[N];
  char validade[N];
  char nome_departamento[N];
  char estoque[N];
};

struct departamento{
  char nome[N];
  char porte[N];
  int qtd_prod;
  LstProd* produtos;
};

Dep* aloca_dep(){
  return ((Dep*)malloc(sizeof(Dep)));
}

LstDep* lstdep_cria(){
  LstDep* novo = (LstDep*)malloc(sizeof(LstDep));
  if(novo == NULL){
    printf("erro!!\n");
    exit(1);
  }
  novo->prox = NULL;
  novo->info = aloca_dep();
  novo->info->qtd_prod = 0;
  novo->info->produtos = NULL;
  return novo;
}


Produto* aloca_prod(){
  return ((Produto*)malloc(sizeof(Produto)));
}

LstProd* lstprod_cria(){
  LstProd* novo = (LstProd*)malloc(sizeof(LstProd));
  if(novo == NULL){
    printf("erro!!\n");
    exit(1);
  }
  novo->prox_prod = NULL;
  novo->info = aloca_prod();
  return novo;
}
