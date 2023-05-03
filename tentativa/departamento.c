#include<stdio.h>
#include<stdlib.h>
#include "listaprodutos.c"

typedef struct departamento Departamento;

struct departamento{
  char nome[50];
  char porte[20];
  int quantidade_produtos;
  ListaProdutos* lista_produtos;
};

Departamento* aloca_departamento(void){
  Departamento* novo_departamento = (Departamento*)malloc(sizeof(Departamento));
  if(novo_departamento == NULL){
    printf("erro!!\n");
    exit(1);
  }
  novo_departamento->lista_produtos = NULL;
  return novo_departamento;
}

int verifica_departamento_vazio(Departamento* departamento){
    return (departamento->quantidade_produtos == 0);
}

int verifica_quantidade_produto(Departamento* departamento){
  return departamento->quantidade_produtos;
}


