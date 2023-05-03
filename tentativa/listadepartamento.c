#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "departamento.c"

typedef struct listadepartamento ListaDepartamento;

struct listadepartamento{
  Departamento* info_departamento;
  ListaDepartamento* proxima_lista_departamento;
};

void imprime_menu(){
  printf("\n\t\tMenu\n");
  printf("1 - Adicionar produto;\n2 - Remover produto;\n3 - Listar produtos cadastrados;\n4 - Editar produto;\n5 - Buscar produto;\n6 - Consultar produtos disponíveis em um dado departamento.\n7 - Consultar quantitativo de produtos por departamento;\n8 - Sair.\n");
}

ListaDepartamento* cria_lista_departamento(){
  ListaDepartamento* novo_departamento = (ListaDepartamento*)malloc(sizeof(ListaDepartamento));
  if(novo_departamento == NULL){
    printf("erro!!\n");
    exit(1);
  }
  novo_departamento->proxima_lista_departamento = NULL;
  novo_departamento->info_departamento = aloca_departamento();
  novo_departamento->info_departamento->quantidade_produtos = 0;
  novo_departamento->info_departamento->lista_produtos= NULL;
  return novo_departamento;
}

ListaDepartamento* ler_departamento_txt(char* linha){
  ListaDepartamento* departamento_auxiliar = cria_lista_departamento(); 
  sscanf(linha, " %[^|]| %[^\n]s", departamento_auxiliar->info_departamento->nome, departamento_auxiliar->info_departamento->porte);
  return departamento_auxiliar;
}

void lst_imprime_txt(ListaDepartamento* lista_departamentos){
  ListaDepartamento* departamento_auxiliar=lista_departamentos;
  ListaProdutos* lista_produtos;
  FILE* arquivo=fopen("lista_teste.txt","wt");
  while(departamento_auxiliar!=NULL){
    fprintf(arquivo,"%s| %s\n",departamento_auxiliar->info_departamento->nome,departamento_auxiliar->info_departamento->porte);
    for(lista_produtos=departamento_auxiliar->info_departamento->lista_produtos;lista_produtos!=NULL;lista_produtos=lista_produtos->prox_prod){
      fprintf(arquivo," %s| %s| %s| %s|%.2f\n",lista_produtos->info->tipo,lista_produtos->info->fabricacao,lista_produtos->info->validade,lista_produtos->info->estoque,lista_produtos->info->preco);
    }
    fprintf(arquivo,"****\n");
    departamento_auxiliar=departamento_auxiliar->proxima_lista_departamento;
  }
  fclose(arquivo);
}

ListaDepartamento* lst_ler(void){
  ListaDepartamento* lista_departamento; //l
  ListaDepartamento* lista_departamento_auxiliar; //d
  ListaProdutos*  lista_produtos;//p
  int quantidade_produtos = 0;
  int quantidade_departamentos = 0;
  int verifica_departamento = 0;
  char linha[100];
  FILE* arquivo = fopen("lista.txt", "rt");

  while(fgets(linha, 100, arquivo) != NULL){
    if(strcmp(linha, "****\n") == 0){
      verifica_departamento = 0;
      lista_departamento_auxiliar->info_departamento->quantidade_produtos = quantidade_produtos;
    }else if(verifica_departamento == 0){
      
      lista_departamento_auxiliar = ler_departamento_txt(linha);
      verifica_departamento++;
      quantidade_departamentos++;
      quantidade_produtos = 0;
      if(quantidade_departamentos == 1){
        lista_departamento = lista_departamento_auxiliar;
      }else{
        lista_departamento_auxiliar->proxima_lista_departamento = lista_departamento;
        lista_departamento = lista_departamento_auxiliar;
      }
    }else{
      lista_produtos  = ler_produto_txt(linha);
      quantidade_produtos++;
      strcpy(lista_produtos->info->nome_departamento,lista_departamento_auxiliar->info_departamento->nome);
      if(quantidade_produtos == 1){
        lista_departamento_auxiliar->info_departamento->lista_produtos = lista_produtos;
      }else{
        lista_produtos->prox_prod = lista_departamento_auxiliar->info_departamento->lista_produtos;
        lista_departamento_auxiliar->info_departamento->lista_produtos = lista_produtos;
      }
    }
  }
  fclose(arquivo);
  return lista_departamento;
}

void lst_imprime(ListaDepartamento* lista_departamento){//l
  ListaDepartamento*  lista_departamento_auxiliar=lista_departamento; //d
  ListaProdutos*  lista_produtos;//p
  while(lista_departamento_auxiliar!=NULL){
    printf("%s %s\n",lista_departamento_auxiliar->info_departamento->nome,lista_departamento_auxiliar->info_departamento->porte);
    for(lista_produtos=lista_departamento_auxiliar->info_departamento->lista_produtos;lista_produtos!=NULL;lista_produtos=lista_produtos->prox_prod){
      printf(" %s %s %s %s %.2f\n",lista_produtos->info->tipo,lista_produtos->info->fabricacao,lista_produtos->info->validade,lista_produtos->info->estoque,lista_produtos->info->preco);
    }
    printf("-----------------------------------------------------------\n");
    lista_departamento_auxiliar=lista_departamento_auxiliar->proxima_lista_departamento;
  }
}

void busca_produto(ListaDepartamento* lista_departamento, char* nome_produto){
  ListaDepartamento* auxiliar_departamento = l;
  ListaProdutos* auxiliar_produto; 
   
   while(auxiliar_departamento != NULL){
    auxiliar_produto = auxiliar_departamento->info->lista_produtos;
    while (auxiliar_produto != NULL){
      
   if(strcmp(auxiliar_produto->tipo, nome_produto) == 0){
      printf("nome do departamento que se encontra o produto: %s\n",auxiliar_produto->info->nome_departamento);
      printf("preço do produto: %.2f\n",auxiliar_produto->info->preco);
      printf("data de fabricação do produto: %s\n",auxiliar_produto->info->fabricacao);
      printf("data de validade do produto: %s\n",auxiliar_produto->info->validade);
      printf("quantidade disponivel em estoque: %s\n\n",auxiliar_produto->info->estoque);
      //  return (auxiliar->info->lista_produtos->info);
    }
    // else{
    //   printf("produto não encontrado");
    // }
      auxiliar_produto = auxiliar_produto->proxima_lista_produto;
    }
    auxiliar_departamento = auxiliar_departamento->proxima_lista_departamento;
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