#include<stdio.h>
#include<stdlib.h>
#include "listaprodutos.c"

typedef struct departamento Departamento;

struct departamento{
  char nome[50];
  char porte[20];
  int qtd_prod;
  struct listaprodutos* lista_produtos;
};

Departamento* aloca_departamento(void){
  Departamento* d = (Departamento*)malloc(sizeof(Departamento));
  if(d == NULL){
    printf("erro!!\n");
    exit(1);
  }
  d->lista_produtos = NULL;
  return d;
}

int verifica_departamento_vazio(Departamento* departamento){
    return (departamento->qtd_prod == 0);
}

int verifica_quantidade