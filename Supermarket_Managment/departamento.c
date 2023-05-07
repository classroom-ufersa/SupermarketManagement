#include <stdio.h>
#include <stdlib.h>
#include "departamento.h"
#include "produto.c"

// typedef struct departamento Departamento;

struct departamento{
   char nome[50]; 
   char porte[20]; 
   int quantidade_produtos;
   Produto* lista_produtos;
   Departamento* proximo_departamento;
   Departamento* departamento_anterior;
};

Departamento* ler_departamento_txt(void){ 
  Departamento* departamento;  
  Departamento* departamento_auxiliar;   
   int verifica_departamento = 0; 
   char linha[100]; 
  
   FILE* arquivo_departamento = fopen("/workspaces/SupermarketManagement/Supermarket_Managment/departamentos.txt", "rt");     
   if (arquivo_departamento == NULL){ 
     printf("erro no arquivo departamento!"); 
     exit(1); 
   } 
    
   while(fgets(linha, 100, arquivo_departamento) != NULL){ 
  
  departamento_auxiliar =  ler_linha_departamento(linha);
     if (verifica_departamento == 0){  
       departamento = departamento_auxiliar;
       verifica_departamento++; 
     }else{ 
       departamento_auxiliar->proximo_departamento = departamento;
       departamento->departamento_anterior = departamento_auxiliar;
       departamento = departamento_auxiliar;
       verifica_departamento++; 
     } 
   } 
   fclose(arquivo_departamento);
  return departamento;
}

Departamento* ler_linha_departamento(char* linha){
   Departamento* departamento = aloca_departamento();  
   sscanf(linha, " %[^|]| %[^\n]", departamento->nome, departamento->porte); 
   // printf("%s\t%s\n",departamento->info_departamento->nome, departamento->info_departamento->porte); 
   // printf("%s",linha); 
   return departamento;
}

Departamento* aloca_departamento(void){ 
   Departamento* novo_departamento = (Departamento*)malloc(sizeof(Departamento)); 
   if(novo_departamento == NULL){ 
     printf("erro na alocação do departamento!\n"); 
     exit(1); 
   } 
   novo_departamento->quantidade_produtos=0;
   novo_departamento->lista_produtos=NULL;
   novo_departamento->departamento_anterior=NULL;
   novo_departamento->proximo_departamento=NULL;
   return novo_departamento;
    
}


Departamento* ler_txt(){
  Departamento* departamento = ler_departamento_txt();
  departamento = ler_produto_txt(departamento);
  return departamento;
}


void lista_departamento_imprime(Departamento* departamento){
  Departamento* departamento_auxiliar=departamento; 
  Produto* lista_produtos;
  while(departamento_auxiliar != NULL){
    printf("%s %s\n", departamento_auxiliar->nome, departamento_auxiliar->porte);
    lista_produtos = departamento_auxiliar->lista_produtos;
    while (lista_produtos != NULL){
      printf("%s %s %s %s %f\n",lista_produtos->tipo, lista_produtos->validade,lista_produtos->fabricacao,lista_produtos->estoque, lista_produtos->preco);
      lista_produtos = lista_produtos->proximo_produto;
    }
    printf("-----------------------------------------------------------\n");
    departamento_auxiliar = departamento_auxiliar->proximo_departamento;
  }
}


Departamento* ler_produto_txt(Departamento* departamento){
    Produto* produto;
    Departamento* departamento_auxiliar=departamento;
    char linha[100];

    FILE* arquivo_produto = fopen("/workspaces/SupermarketManagement/Supermarket_Managment/produtos.txt","rt");
  if (arquivo_produto == NULL){
    printf("erro: arquivo produto!");
    exit(1);
  }

   while(fgets(linha, 100, arquivo_produto) != NULL){
    produto =  ler_linha_produto(linha);
    while (departamento_auxiliar != NULL){
      
      if (strcmp(departamento_auxiliar->nome,produto->nome_departamento) == 0){
        
        if (departamento_auxiliar->quantidade_produtos == 0){
          
          departamento_auxiliar->lista_produtos = produto;
          departamento_auxiliar->quantidade_produtos++;
          
        }else{
          produto->proximo_produto = departamento_auxiliar->lista_produtos;
          departamento_auxiliar->lista_produtos = produto;
          departamento_auxiliar->quantidade_produtos++;
        }
      }
      departamento_auxiliar = departamento_auxiliar->proximo_departamento;
    }
  }

  fclose(arquivo_produto);
  return (departamento);
  
}
