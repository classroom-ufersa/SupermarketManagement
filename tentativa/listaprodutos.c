#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"listaprodutos.h"
#include "produto.c"
#include"listadepartamento.c"

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

ListaProdutos* ler_lista_produto(ListaDepartamento* lista_departamento){
  ListaDepartamento* lista_departamento_auxiliar = lista_departamento;
  ListaProdutos* lista_produtos;
  char linha[100];
  
  FILE* arquivo_produto = fopen("/workspaces/SupermarketManagement/tentativa/output/arquivoproduto.txt", "rt");
  if (arquivo_produto == NULL){
    printf("erro: arquivo produto!!");
    exit(1);
  }
  lista_departamento_auxiliar = lista_departamento;
   while(fgets(linha, 100, arquivo_produto) != NULL){
    lista_produtos =  ler_produto_txt(linha);

    while (lista_departamento_auxiliar != NULL){

      if (strcmp(lista_departamento_auxiliar->info_departamento->nome, lista_produtos->info_produto->nome_departamento) == 0){
        if (lista_departamento_auxiliar->info_departamento->quantidade_produtos == 0){

          lista_departamento_auxiliar->info_departamento->lista_produtos = lista_produtos;
          lista_departamento_auxiliar->info_departamento->quantidade_produtos++;
          
        }else{
          lista_produtos->proxima_lista_produto = lista_departamento_auxiliar->info_departamento->lista_produtos;
          lista_departamento_auxiliar->info_departamento->lista_produtos = lista_produtos;
          lista_departamento_auxiliar->info_departamento->quantidade_produtos++;
        }
      }
      lista_departamento_auxiliar = lista_departamento_auxiliar->proxima_lista_departamento;
    }
  }
  fclose(arquivo_produto);
}