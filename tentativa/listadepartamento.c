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
  sscanf(linha, " %[^|]| %[^\n]", departamento_auxiliar->info_departamento->nome, departamento_auxiliar->info_departamento->porte);
  return departamento_auxiliar;
}

void lista_imprime_txt(ListaDepartamento* lista_departamentos){
  ListaDepartamento* departamento_auxiliar = lista_departamentos;
  ListaProdutos* lista_produtos;
  FILE* arquivo = fopen("lista_teste.txt","wt");
  while(departamento_auxiliar != NULL){
    fprintf(arquivo,"%s| %s\n",departamento_auxiliar->info_departamento->nome,departamento_auxiliar->info_departamento->porte);
    for(lista_produtos = departamento_auxiliar->info_departamento->lista_produtos; lista_produtos != NULL; lista_produtos = lista_produtos->proxima_lista_produto){
      fprintf(arquivo," %s| %s| %s| %s|%.2f\n", lista_produtos->info_produto->tipo, lista_produtos->info_produto->fabricacao, lista_produtos->info_produto->validade, lista_produtos->info_produto->estoque, lista_produtos->info_produto->preco);
    }
    fprintf(arquivo,"****\n");
    departamento_auxiliar = departamento_auxiliar->proxima_lista_departamento;
  }
  fclose(arquivo);
}

ListaDepartamento* ler_lista_departamentos(void){
  ListaDepartamento* lista_departamento; 
  ListaDepartamento* lista_departamento_auxiliar; 
  ListaProdutos*  lista_produtos;//p
  int quantidade_produtos = 0;
  int quantidade_departamentos = 0;
  int verifica_departamento = 0;
  char linha[100];
  FILE* arquivo = fopen("lista.txt", "rt");
  
  if (arquivo == NULL){
    printf("erro!!");
    exit(1);
  }
  

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
      strcpy(lista_produtos->info_produto->nome_departamento,lista_departamento_auxiliar->info_departamento->nome);
      if(quantidade_produtos == 1){
        lista_departamento_auxiliar->info_departamento->lista_produtos = lista_produtos;
      }else{
        lista_produtos->proxima_lista_produto = lista_departamento_auxiliar->info_departamento->lista_produtos;
        lista_departamento_auxiliar->info_departamento->lista_produtos = lista_produtos;
      }
    }
  }
  fclose(arquivo);
  return lista_departamento;
}

void lista_departamento_imprime(ListaDepartamento* lista_departamento){
  ListaDepartamento*  lista_departamento_auxiliar=lista_departamento; 
  ListaProdutos*  lista_produtos;//p
  while(lista_departamento_auxiliar!=NULL){
    printf("%s %s\n", lista_departamento_auxiliar->info_departamento->nome, lista_departamento_auxiliar->info_departamento->porte);
    for(lista_produtos = lista_departamento_auxiliar->info_departamento->lista_produtos; lista_produtos !=NULL ;lista_produtos = lista_produtos->proxima_lista_produto){
      printf(" %s %s %s %s %.2f\n", lista_produtos->info_produto->tipo,lista_produtos->info_produto->fabricacao,lista_produtos->info_produto->validade,lista_produtos->info_produto->estoque,lista_produtos->info_produto->preco);
    }
    printf("-----------------------------------------------------------\n");
    lista_departamento_auxiliar=lista_departamento_auxiliar->proxima_lista_departamento;
  }
}

void busca_produto(ListaDepartamento* lista_departamento, char* nome_produto){
  ListaDepartamento* lista_departamento_auxiliar = lista_departamento;
  ListaProdutos* lista_produto_auxiliar; 
   
   while(lista_departamento_auxiliar != NULL){
    lista_produto_auxiliar = lista_departamento_auxiliar->info_departamento->lista_produtos;
    while (lista_produto_auxiliar != NULL){
      
   if(strcmp(lista_produto_auxiliar->info_produto->tipo, nome_produto) == 0){
      printf("nome do departamento que se encontra o produto: %s\n",lista_produto_auxiliar->info_produto->nome_departamento);
      printf("preço do produto: %.2f\n",lista_produto_auxiliar->info_produto->preco);
      printf("data de fabricação do produto: %s\n",lista_produto_auxiliar->info_produto->fabricacao);
      printf("data de validade do produto: %s\n",lista_produto_auxiliar->info_produto->validade);
      printf("quantidade disponivel em estoque: %s\n\n",lista_produto_auxiliar->info_produto->estoque);
      //  return (auxiliar->info->lista_produtos->info);
    }
    // else{
    //   printf("produto não encontrado");
    // }
      lista_produto_auxiliar = lista_produto_auxiliar->proxima_lista_produto;
    }
    lista_departamento_auxiliar = lista_departamento_auxiliar->proxima_lista_departamento;
  }
  
}

void insere_novo_produto(ListaDepartamento* lista_departamento, char* tipo, char* validade, char* fabricacao, char* estoque, char* nome_departamento, float preco){
  ListaDepartamento*  lista_departamento_auxiliar = lista_departamento;
  ListaProdutos* novo_produto = cria_lista_produto();
  if(novo_produto == NULL){
    printf("erro!!!");
    exit(1);
  }

  strcpy(novo_produto->info_produto->tipo,tipo);
  strcpy(novo_produto->info_produto->fabricacao,fabricacao);
  strcpy(novo_produto->info_produto->nome_departamento,nome_departamento);
  strcpy(novo_produto->info_produto->validade,validade);
  strcpy(novo_produto->info_produto->estoque, estoque);
  novo_produto->info_produto->preco = preco;

  while(lista_departamento_auxiliar != NULL){
    
    if(strcmp(lista_departamento_auxiliar->info_departamento->nome,nome_departamento) == 0){
      novo_produto->proxima_lista_produto = lista_departamento_auxiliar->info_departamento->lista_produtos;
      lista_departamento_auxiliar->info_departamento->lista_produtos = novo_produto;
    }
    lista_departamento_auxiliar = lista_departamento_auxiliar->proxima_lista_departamento;
  }
  lista_departamento = lista_departamento_auxiliar;
}