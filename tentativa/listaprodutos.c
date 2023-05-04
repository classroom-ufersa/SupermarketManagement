#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "produto.c"

typedef struct listaprodutos ListaProdutos;

struct listaprodutos{
   Produto* info_produto;
   ListaProdutos* proxima_lista_produto;
};

ListaProdutos* cria_lista_produto(){
  ListaProdutos* nova_lista_produto = (ListaProdutos*)malloc(sizeof(ListaProdutos));
  if(nova_lista_produto == NULL){
    printf("erro!!\n");
    exit(1);
  }
  nova_lista_produto->info_produto = aloca_produto(); 
  return nova_lista_produto;
}

ListaProdutos* ler_produto_txt(char* linha){
  ListaProdutos* nova_lista_produto = cria_lista_produto();
  if(nova_lista_produto == NULL){
    printf("Erro!!!\n");
    exit(1);
  }
  sscanf(linha, " %[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%f\n",nova_lista_produto->info_produto->nome_departamento ,nova_lista_produto->info_produto->tipo, nova_lista_produto->info_produto->fabricacao, nova_lista_produto->info_produto->validade, nova_lista_produto->info_produto->estoque, &nova_lista_produto->info_produto->preco);
  printf("%s",linha);
  return nova_lista_produto;
}