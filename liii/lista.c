#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lstdep LstDep;
typedef struct produto Produto;
typedef struct departamento Dep;
typedef struct lstprod LstProd;

#define N 20

struct lstdep{
  Dep* info;
  LstDep* prox;
};

struct lstprod{
   Produto* info;
   LstProd* prox_prod;
};

struct produto{
  char tipo[N];
  float preco;
  char fabricacao[N];
  char validade[N];
  char nome_departamento[N];
  char estoque[N];
};

struct departamento{
  char nome[N];
  char porte[N];
  int qtd_prod;
  LstProd* produtos;
};

Dep* aloca_dep(){
  return ((Dep*)malloc(sizeof(Dep)));
}

Produto* aloca_prod(){
  return ((Produto*)malloc(sizeof(Produto)));
}


LstDep* lstdep_cria(){
  LstDep* novo = (LstDep*)malloc(sizeof(LstDep));
  if(novo == NULL){
    printf("erro!!\n");
    exit(1);
  }
  novo->prox = NULL;
  novo->info = aloca_dep();
  novo->info->qtd_prod = 0;
  novo->info->produtos = NULL;
  return novo;
}

LstProd* lstprod_cria(){
  LstProd* novo = (LstProd*)malloc(sizeof(LstProd));
  if(novo == NULL){
    printf("erro!!\n");
    exit(1);
  }
  novo->prox_prod = NULL;
  novo->info = aloca_prod();
  return novo;
}


LstDep* lst_ler(){
  LstDep* l;
  LstDep* d;
  LstProd* p;
  int qtd_prod = 0;
  int qtd_dep = 0;
  int verifica_dep = 0;
  char linha[100];
  FILE* arq = fopen("lista.txt", "rt");

  while(fgets(linha, 100, arq) != NULL){
    if(strcmp(linha, "****\n") == 0){
      verifica_dep = 0;
    }else if(verifica_dep == 0){
      d = lstdep_cria();
      verifica_dep++;
      qtd_dep++;
      d->info->qtd_prod = qtd_prod;
      qtd_prod = 0;
      if(qtd_dep == 1){
        l = d;
      }else{
        d->prox = l;
        l = d;
      }
      sscanf(linha, " %[^|]| %[^\n]", d->info->nome, d->info->porte);
    }else{
      p  = lstprod_cria();
      qtd_prod++;
      strcpy(p->info->nome_departamento,d->info->nome);
      sscanf(linha, " %[^|]|  %[^|]|  %[^|]|  %[^|]| %f", p->info->tipo,  p->info->fabricacao, p->info->validade, p->info->estoque,&p->info->preco);
      if(qtd_prod == 1){
        d->info->produtos = p;
      }else{
        p->prox_prod = d->info->produtos;
        d->info->produtos = p;
      }
    }
  }
  
  fclose(arq);
  return l;
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
//       d->info->qtd_prod = qtd_prod;
//     }else if(verifica_dep == 0){
//       d = ler_dep(linha);
//       verifica_dep++;
//       qtd_dep++;
//       qtd_prod = 0;
//       if(qtd_dep == 1){
//         l = d;
//       }else{
//         d->prox = l;
//         l = d;
//       }
//     }else{
//       p  = ler_prod(linha);
//       qtd_prod++;
//       strcpy(p->info->nome_departamento,d->info->nome);
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



void lst_imprime_txt(LstDep* l){
  LstDep* d=l;
  LstProd* p;
  FILE* arq=fopen("lista_teste.txt","at");
  while(d!=NULL){
    fprintf(arq,"%s| %s\n",d->info->nome,d->info->porte);
    for(p=d->info->produtos;p!=NULL;p=p->prox_prod){
      fprintf(arq," %s| %s| %s| %s|%.2f\n",p->info->tipo,p->info->fabricacao,p->info->validade,p->info->estoque,p->info->preco);
    }
    fprintf(arq,"****\n");
    d=d->prox;
  }
  fclose(arq);
}

LstDep* ler_dep(char* linha){
  LstDep* d =lstdep_cria(); 
  sscanf(linha, " %[^|]| %[^\n]s", d->info->nome, d->info->porte);
  return d;
}

LstProd* ler_prod(char* linha){
  if(strcmp(linha, "****\n") == 0){
    return NULL;
  }
  LstProd* p = lstprod_cria();
  if(p == NULL){
    printf("Erro!!!\n");
    exit(1);
  }
  sscanf(linha," %[^|]| %[^|]| %[^|]| %[^|]| %f", p->info->tipo, p->info->fabricacao, p->info->validade, p->info->estoque, &p->info->preco);
  return p;
}