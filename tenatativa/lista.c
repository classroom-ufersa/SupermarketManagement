#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadepartamento.c"
#include "listaprodutos.c"
#include "produto.c"
#include "departamento.c"

typedef struct listadepartamento ListaDepartamento;
typedef struct departamento Departamento;
typedef struct produto Produto;
typedef struct listaprodutos ListaProdutos;


// LstDep* lst_ler(){
//   LstDep* l;
//   LstDep* d;
//   LstProd* p;
//   int qtd_prod = 0;
//   int qtd_dep = 0;
//   int verifica_dep = 0;
//   char linha[100];
//   FILE* arq = fopen("lista.txt", "rt");

//   while(fgets(linha, 100, arq) != NULL){
//     if(strcmp(linha, "****\n") == 0){
//       verifica_dep = 0;
//     }else if(verifica_dep == 0){
//       d = lstdep_cria();
//       verifica_dep++;
//       qtd_dep++;
//       d->info->qtd_prod = qtd_prod;
//       qtd_prod = 0;
//       if(qtd_dep == 1){
//         l = d;
//       }else{
//         d->prox = l;
//         l = d;
//       }
//       sscanf(linha, " %[^|]| %[^\n]", d->info->nome, d->info->porte);
//     }else{
//       p  = lstprod_cria();
//       qtd_prod++;
//       strcpy(p->info->nome_departamento,d->info->nome);
//       sscanf(linha, " %[^|]|  %[^|]|  %[^|]|  %[^|]| %f", p->info->tipo,  p->info->fabricacao, p->info->validade, p->info->estoque,&p->info->preco);
//       if(qtd_prod == 1){
//         d->info->produtos = p;
//       }else{
//         p->prox_prod = d->info->produtos;
//         d->info->produtos = p;
//       }
//     }
//   }
  
//   fclose(arq);
//   return l;
// }





