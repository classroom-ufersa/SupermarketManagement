#include<stdio.h>
#include<stdlib.h>

typedef struct produto Produto;

struct produto{
  char tipo[50];
  float preco;
  char fabricacao[20];
  char validade[20];
  char nome_departamento[50];
  char estoque[20];
};

Produto* aloca_produto(void){
  Produto* novo_produto = (Produto*)malloc(sizeof(Produto));
  if (novo_produto == NULL){
    printf("erro!!\n");
    exit(1);
  }
  return novo_produto;
}


