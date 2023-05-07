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
  char estoque[20];
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
   return novo_produto; 
}


Produto* ler_linha_produto(char* linha){
  Produto* novo_produto = aloca_produto();
  sscanf(linha, " %[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%f\n",novo_produto->nome_departamento ,novo_produto->tipo, novo_produto->fabricacao, novo_produto->validade, novo_produto->estoque, &novo_produto->preco);
  printf("%s",linha);
  return novo_produto;
}


// Departamento* ler_produto_txt(Departamento* departamento){
//     Produto* produto;
//     Departamento* departamento_auxiliar=departamento;
//     char linha[100];

//     FILE* arquivo_produto = fopen("/workspaces/SupermarketManagement/Supermarket_Managment/produtos.txt","rt");
//   if (arquivo_produto == NULL){
//     printf("erro: arquivo produto!");
//     exit(1);
//   }

//    while(fgets(linha, 100, arquivo_produto) != NULL){
//     produto =  ler_linha_produto(linha);
//     while (departamento_auxiliar != NULL){
      
//       if (strcmp(departamento_auxiliar->nome,produto->nome_departamento) == 0){
        
//         if (departamento_auxiliar->quantidade_produtos == 0){
          
//           departamento_auxiliar->lista_produtos = produto;
//           departamento_auxiliar->quantidade_produtos++;
          
//         }else{
//           produto->proximo_produto = departamento_auxiliar->lista_produtos;
//           departamento_auxiliar->lista_produtos = produto;
//           departamento_auxiliar->quantidade_produtos++;
//         }
//       }
//       departamento_auxiliar = departamento_auxiliar->proximo_departamento;
//     }
//   }

//   fclose(arquivo_produto);
//   return (departamento);
  
// }
