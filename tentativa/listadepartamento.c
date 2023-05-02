#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "departamento.c"

typedef struct listadepartamento ListaDepartamento;

struct listadepartamento{
  Departamento* info;
  ListaDepartamento* prox;
};

void menu(){
  printf("\n\t\tMenu\n");
  printf("1 - Adicionar produto;\n2 - Remover produto;\n3 - Listar produtos cadastrados;\n4 - Editar produto;\n5 - Buscar produto;\n6 - Consultar produtos disponíveis em um dado departamento.\n7 - Consultar quantitativo de produtos por departamento;\n8 - Sair.\n");
}

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

void busca_produto(ListaDepartamento* l, char* nome_produto){
  printf("antes do while");
  ListaDepartamento* auxiliar=l;
  printf("antes do while");
  while(auxiliar->info->lista_produtos->prox_prod!=NULL){
    printf("entrou no while");
    if(strcmp(nome_produto,auxiliar->info->lista_produtos->info->tipo)==0){
      printf("entrou no if");
      printf("nome do departamento que se encontra o produto: %s",auxiliar->info->lista_produtos->info->nome_departamento);
      printf("preço do produto: %s",auxiliar->info->lista_produtos->info->tipo);
      printf("data de fabricação do produto: %s",auxiliar->info->lista_produtos->info->fabricacao);
      printf("data de validade do produto: %s",auxiliar->info->lista_produtos->info->validade);
      printf("quantidade disponivel em estoque: %s",auxiliar->info->lista_produtos->info->estoque);
      //  return (auxiliar->info->lista_produtos->info);
    }else{
      printf("produto não encontrado");
    }
    auxiliar=auxiliar->prox;
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

  while(d != NULL){
    
    if(strcmp(d->info->nome,nome_departamento) == 0){
      novo->prox_prod = d->info->lista_produtos;
      d->info->lista_produtos = novo;
    }
    d = d->prox;
  }
  l = d;
}