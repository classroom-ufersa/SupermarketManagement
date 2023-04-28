#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadepartamento.c"
#include "listaprodutos.c"
#include "produto.c"
#include "departamento.c"

// typedef struct listadepartamento ListaDepartamento;
// typedef struct departamento Departamento;
// typedef struct produto Produto;
// typedef struct listaprodutos ListaProdutos;



ListaDepartamento* lstdep_cria(){
  ListaDepartamento* novo = (ListaDepartamento*)malloc(sizeof(ListaDepartamento));
  if(novo == NULL){
    printf("erro!!\n");
    exit(1);
  }
  novo->prox = NULL;
  novo->info = aloca_dep();
  novo->info->qtd_prod = 0;
  novo->info->lista_produtos= NULL;
  return novo;
}

ListaProdutos* lstprod_cria(){
  ListaProdutos* novo = (ListaProdutos*)malloc(sizeof(ListaProdutos));
  if(novo == NULL){
    printf("erro!!\n");
    exit(1);
  }
  novo->prox_prod = NULL;
  novo->info = aloca_prod();
  return novo;
}

Departamento* aloca_dep(){
  return ((Departamento*)malloc(sizeof(Departamento)));
}

Produto* aloca_prod(){
  return ((Produto*)malloc(sizeof(Produto)));
}

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

ListaDepartamento* lst_ler(){
  ListaDepartamento* l;
  ListaDepartamento* d;
  ListaProdutos* p;
  int qtd_prod = 0;
  int qtd_dep = 0;
  int verifica_dep = 0;
  char linha[100];
  FILE* arq = fopen("lista.txt", "rt");

  while(fgets(linha, 100, arq) != NULL){
    if(strcmp(linha, "****\n") == 0){
      verifica_dep = 0;
      d->info->qtd_prod = qtd_prod;
    }else if(verifica_dep == 0){
      d = ler_dep(linha);
      verifica_dep++;
      qtd_dep++;
      qtd_prod = 0;
      if(qtd_dep == 1){
        l = d;
      }else{
        d->prox = l;
        l = d;
      }
    }else{
      p  = ler_prod(linha);
      qtd_prod++;
      strcpy(p->info->nome_departamento,d->info->nome);
      if(qtd_prod == 1){
        d->info->lista_produtos = p;
      }else{
        p->prox_prod = d->info->lista_produtos;
        d->info->lista_produtos = p;
      }
    }
  }
  
  fclose(arq);
  return l;
}



void lst_imprime_txt(ListaProdutos* l){
  ListaDepartamento* d=l;
  ListaProdutos* p;
  FILE* arq=fopen("lista_teste.txt","wt");
  while(d!=NULL){
    fprintf(arq,"%s| %s\n",d->info->nome,d->info->porte);
    for(p=d->info->lista_produtos;p!=NULL;p=p->prox_prod){
      fprintf(arq," %s| %s| %s| %s|%.2f\n",p->info->tipo,p->info->fabricacao,p->info->validade,p->info->estoque,p->info->preco);
    }
    fprintf(arq,"****\n");
    d=d->prox;
  }
  fclose(arq);
}

ListaDepartamento* ler_dep(char* linha){
  ListaDepartamento* d =lstdep_cria(); 
  sscanf(linha, " %[^|]| %[^\n]s", d->info->nome, d->info->porte);
  return d;
}

ListaProdutos* ler_prod(char* linha){
  if(strcmp(linha, "****\n") == 0){
    return NULL;
  }
  ListaProdutos* p = lstprod_cria();
  if(p == NULL){
    printf("Erro!!!\n");
    exit(1);
  }
  sscanf(linha," %[^|]| %[^|]| %[^|]| %[^|]| %f", p->info->tipo, p->info->fabricacao, p->info->validade, p->info->estoque, &p->info->preco);
  return p;
}