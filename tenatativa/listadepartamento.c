#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "departamento.c"

typedef struct listadepartamento ListaDepartamento;

struct listadepartamento{
  Departamento* info;
  ListaDepartamento* prox;
};

ListaDepartamento* lstdep_cria(){
  ListaDepartamento* novo = (ListaDepartamento*)malloc(sizeof(ListaDepartamento));
  if(novo == NULL){
    printf("erro!!\n");
    exit(1);
  }
  novo->prox = NULL;
  novo->info = aloca_departamento();
  novo->info->qtd_prod = 0;
  novo->info->lista_produtos= NULL;
  return novo;
}

ListaDepartamento* ler_departamento(char* linha){
  ListaDepartamento* d = lstdep_cria(); 
  sscanf(linha, " %[^|]| %[^\n]s", d->info->nome, d->info->porte);
  return d;
}

void lst_imprime_txt(ListaDepartamento* l){
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

ListaDepartamento* lst_ler(void){
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
      
      d = ler_departamento(linha);
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
      p  = ler_produto(linha);
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

void lst_imprime(ListaDepartamento* l){
  ListaDepartamento* d=l;
  ListaProdutos* p;
  while(d!=NULL){
    printf("%s %s\n",d->info->nome,d->info->porte);
    for(p=d->info->lista_produtos;p!=NULL;p=p->prox_prod){
      printf(" %s %s %s %s %.2f\n",p->info->tipo,p->info->fabricacao,p->info->validade,p->info->estoque,p->info->preco);
    }
    printf("-----------------------------------------------------------\n");
    d=d->prox;
  }
}

void lst_insere(ListaDepartamento* l, char* tipo, char* validade, char* fabricacao, char* estoque, char* nome_departamento, float preco){
  ListaDepartamento* d = l;
  ListaProdutos* novo = lstprod_cria();
  if(novo == NULL){
    printf("erro!!!");
    exit(1);
  }

  strcpy(novo->info->tipo,tipo);
  strcpy(novo->info->fabricacao,fabricacao);
  strcpy(novo->info->nome_departamento,nome_departamento);
  strcpy(novo->info->validade,validade);
  strcpy(novo->info->estoque, estoque);
  novo->info->preco = preco;

  //printf(" %s %s %s %s %.2f\n",novo->info->tipo,novo->info->fabricacao,novo->info->validade,novo->info->estoque,novo->info->preco);
  
  while(d != NULL){
    
    if(strcmp(d->info->nome,nome_departamento) == 0){
      novo->prox_prod = d->info->lista_produtos;
      d->info->lista_produtos = novo;
    }
    d = d->prox;
  }
  l = d;
}