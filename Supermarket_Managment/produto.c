#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"produto.h"
// #include"departamento.h"

// typedef struct produto Produto; 
  
 struct produto{ 
  char tipo[50]; 
  float preco; 
  char fabricacao[20]; 
  char validade[20]; 
  char nome_departamento[50]; 
  int estoque;
  Produto* proximo_produto;
  Produto* produto_anterior;
 };

Produto* aloca_produto(void){ 
   Produto* novo_produto = (Produto*)malloc(sizeof(Produto)); 
   if (novo_produto == NULL){ 
     printf("erro na alocaçâo do produto!\n"); 
     exit(1); 
   } 
   novo_produto->produto_anterior = NULL;
   novo_produto->proximo_produto = NULL;
   novo_produto->estoque = 0;
   novo_produto->preco = 0;
   return novo_produto; 
}


Produto* ler_linha_produto(char* linha){
  Produto* novo_produto = aloca_produto();
  sscanf(linha, " %[^|]|%[^|]|%[^|]|%[^|]|%d|%f\n",novo_produto->nome_departamento ,novo_produto->tipo, novo_produto->fabricacao, novo_produto->validade, &novo_produto->estoque, &novo_produto->preco);
  printf("%s %s %s %s %d %.2f\n",novo_produto->nome_departamento ,novo_produto->tipo, novo_produto->fabricacao, novo_produto->validade, novo_produto->estoque, novo_produto->preco);
  return novo_produto;
}

