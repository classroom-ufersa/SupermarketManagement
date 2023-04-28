#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.c"

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

LstDep* lst_ler(){
  LstDep* l;
  LstDep* d;
  LstProd* p;
  int qtd_prod = 0;
  int qtd_dep = 0;
  int verifica_dep = 0;
  char linha[100];
  FILE* arq = fopen("estoque.txt", "rt");

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



void lst_imprime_txt(LstDep* l){
  LstDep* d=l;
  LstProd* p;
  FILE* arq=fopen("estoque_teste.txt","wt");
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