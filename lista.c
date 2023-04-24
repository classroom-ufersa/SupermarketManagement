#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lstdep LstDep;
typedef struct produto Produto;
typedef struct departamento Dep;
typedef struct lstprod LstProd;

#define N 20
#define QD 1

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
  int estoque;
};

struct departamento{
   char nome[N];
   LstProd* produtos;
   char porte[N];
   LstDep* prox_dep;
   int qtd_prod;
   int qtd_dep;
};

void menu(){
  printf("\n\t\tMenu\n");
  printf("1 - Adicionar produto;\n2 - Remover produto;\n3 - Listar produtos cadastrados;\n4 - Editar produto;\n5 - Buscar produto;\n6 - Consultar produtos disponíveis em um dado departamento.\n7 - Consultar quantitativo de produtos por departamento;\n8 - Sair.\n");
}

LstDep* lstdep_cria(){
  return NULL;
}

void lst_ler(LstDep* l){
     
}

void lst_insere(LstDep* l, char* tipo, char* validade, char* fabricacao, int estoque, char* nome_departamento, float preco){
  LstProd* novo = (LstProd*)malloc(sizeof(LstProd));
  if(novo){
    
    strcpy(novo->info->tipo,tipo);
    strcpy(novo->info->fabricacao,fabricacao);
    strcpy(novo->info->nome_departamento,nome_departamento);
    strcpy(novo->info->validade,validade);
    novo->info->estoque = estoque;
    novo->info->preco = preco;
    
    if(l->info->nome == novo->info->nome_departamento){
      novo->prox_prod = l->info->produtos;
      l->info->produtos = novo;
    }

  }else{
    printf("erro!!!");
    exit(1);
  }
}

void lst_imprime(LstDep* l){
  LstDep* d = l;
  LstProd* p;
  
  while(d != NULL){
    
    printf("depatamento : %s", d->info->nome);
    
    for(p = l->info->produtos; p != NULL; p = p->prox_prod){
      printf("%s",p->info->tipo);
    }
    
    d = d->prox;
  }
}


void libera(LstDep* l){

  LstDep* d = l;
  LstDep* aux_d;
  LstProd* p;
  LstProd* aux_p;
  
  while(d->prox != NULL){
    aux_d = d;
    p->prox_prod = aux_d->info->produtos;  
    
    while(p->prox_prod != NULL){
      aux_p = p;
      p = p->prox_prod;
      free(aux_p);
    }
    
    free(p);
    
    d = d->prox;
    free(aux_d);
  }
  free(d);
}