#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "departamento.h"
#include "produto.c"
#include "/workspaces/SupermarketManagement/Supermarket_Managment/tratativas/funcoes.c" 

// typedef struct departamento Departamento;

struct departamento{
   char nome[50]; 
   char porte[20]; 
   int quantidade_produtos;
   Produto* lista_produtos;
   Departamento* proximo_departamento;
   Departamento* departamento_anterior;
};

//imprime o menu de opções
void imprime_menu(){
  printf("\n\t\tMenu\n");
  printf("1 - Adicionar produto;\n2 - Remover produto;\n3 - Listar produtos cadastrados;\n4 - Editar produto;\n5 - Buscar produto;\n6 - Consultar produtos disponíveis em um dado departamento;\n7 - Consultar quantitativo de produtos por departamento;\n8 - Sair.\n");
}

//aloca um departamento
Departamento* aloca_departamento(void){ 
   Departamento* novo_departamento = (Departamento*)malloc(sizeof(Departamento)); 
   if(novo_departamento == NULL){ //para verificar se a alocação foi bem sucedida
     printf("erro na alocação do departamento!\n"); 
     exit(1); 
   } 
   //inicializando o departamento
   novo_departamento->quantidade_produtos=0;
   novo_departamento->lista_produtos=NULL;
   novo_departamento->departamento_anterior=NULL;
   novo_departamento->proximo_departamento=NULL;
   return novo_departamento; 
}

//lê os arquivos produtos e departamento e armazena os dados no departamento que será retornado
Departamento* ler_txt(){
  Departamento* departamento = ler_departamento_txt();
  departamento = ler_produto_txt(departamento);
  return departamento;
}

void imprime_txt(Departamento* departamento){
  imprime_no_arquivo_produto(departamento);
  imprime_no_arquivo_departamento(departamento);
}

//para ler uma linha do departamento
Departamento* ler_linha_departamento(char* linha){
   Departamento* departamento = aloca_departamento();  
   sscanf(linha, " %[^|]| %[^\n]", departamento->nome, departamento->porte); 
   return departamento;
}

//função que lê os dados no arquivo departamentos
Departamento* ler_departamento_txt(void){ 
  Departamento* departamento;  
  Departamento* departamento_auxiliar;   
   int verifica_departamento = 0; 
   char linha[100]; 
   //abre o arquivo e verifica se ele foi aberto corretamente
   FILE* arquivo_departamento = fopen("/workspaces/SupermarketManagement/Supermarket_Managment/departamentos.txt", "rt");     
    if (arquivo_departamento == NULL){ 
      printf("erro no arquivo departamento!"); 
      exit(1); 
    } 
   //para percorrer as linhas do arquivo 
   while(fgets(linha, 100, arquivo_departamento) != NULL){ 
  
  departamento_auxiliar =  ler_linha_departamento(linha);
  //verifica se é o primeiro departamento
     if (verifica_departamento == 0){  
       departamento = departamento_auxiliar;
       verifica_departamento++; 
     }else{ //se não for o primeiro departamento ele vai ser encaixado na lista de departamentos
       departamento_auxiliar->proximo_departamento = departamento;
       departamento->departamento_anterior = departamento_auxiliar;
       departamento = departamento_auxiliar;
       verifica_departamento++; 
     } 
   } 
   //fechando o arquivo e retornando o departamento
   fclose(arquivo_departamento);
  return departamento;
}

//função que lê os dados do arquivo produtos,o departamento é passado como parametro
Departamento* ler_produto_txt(Departamento* departamento){
    Departamento* departamento_auxiliar = departamento;
    Produto* produto;
    char linha[100];
    //abre o arquivo e verifica se ele foi aberto corretamente
  FILE* arquivo_produto = fopen("/workspaces/SupermarketManagement/Supermarket_Managment/produtos.txt","rt");
  if (arquivo_produto == NULL){
    printf("erro: arquivo produto!");
    exit(1);
  }
  //percorre as linhas do arquivo produtos
   while(fgets(linha, 100, arquivo_produto) != NULL){
    produto =  ler_linha_produto(linha);
    departamento_auxiliar = departamento;
    while(departamento_auxiliar != NULL){
      
      if (strcmp(departamento_auxiliar->nome,produto->nome_departamento) == 0){
        //verifica se esse é o primeiro produto
        if (departamento_auxiliar->quantidade_produtos == 0){  
          departamento_auxiliar->lista_produtos = produto;
          departamento_auxiliar->quantidade_produtos++;
        }else{//se não for o primeiro produto esse produto vai ser encaixado na lista
          produto->proximo_produto = departamento_auxiliar->lista_produtos;
          departamento_auxiliar->lista_produtos->produto_anterior = produto;
          departamento_auxiliar->lista_produtos = produto;
          departamento_auxiliar->quantidade_produtos++;
        }
      }
      departamento_auxiliar = departamento_auxiliar->proximo_departamento;
    }
  }
  //fechando o arquivo e retornando o produto
  fclose(arquivo_produto);
  return (departamento);
}

//função responsavel por imprimir todos os prodtos e departamentos que estão no sistema, para isso ela utiliza um departamento que é passado como parametro
void lista_departamento_imprime(Departamento* departamento){
  Departamento* departamento_auxiliar = departamento; 
  Produto* lista_produtos;
  //percorre todos os departamentos
  while(departamento_auxiliar != NULL){
    //verifica se há produtos no departamento
    if(departamento_auxiliar->quantidade_produtos == 0){
      printf("\ndepartamento: %s, nenhum produto nesse departamento;\n",departamento_auxiliar->nome);
    }
    else{//imprimindo o departamento e a quantidade de produtos
    printf("\n\nnome do departamento: %s, quantidade de produtos nesse departamento: %d\n", departamento_auxiliar->nome,departamento_auxiliar->quantidade_produtos);
    lista_produtos = departamento_auxiliar->lista_produtos;
    //percorrendo todos os produtos
    while (lista_produtos != NULL){
      if(lista_produtos->estoque == 0){
        printf("\nnome do produto: %s\nvalidade do produto: %s\ndata de fabricação do produto: %s\neste produto não está disponivel em estoque\npreço do produto: %.2f\n",lista_produtos->tipo, lista_produtos->validade,lista_produtos->fabricacao, lista_produtos->preco);
      }else{
      printf("\nnome do produto: %s\nvalidade do produto: %s\ndata de fabricação do produto: %s\nquantidade em estoque: %d\npreço do produto: %.2f\n",lista_produtos->tipo, lista_produtos->validade,lista_produtos->fabricacao,lista_produtos->estoque, lista_produtos->preco);
      }
      lista_produtos = lista_produtos->proximo_produto;
    }

  }
  departamento_auxiliar = departamento_auxiliar->proximo_departamento;
  }
}

//função responsavel por receber todos os dados do produto e inserir ele no sistema
void insere_novo_produto(Departamento* departamento, char* tipo, char* validade, char* fabricacao, int estoque, char* nome_departamento, float preco){
  Departamento* departamento_auxiliar = departamento;
  Produto* novo_produto = aloca_produto();
  //verifica se a alocação foi bem sucedida
  if(novo_produto == NULL){
    printf("erro!!!");
    exit(1);
  }
  //salva os dados no produto
  strcpy(novo_produto->tipo,tipo);
  strcpy(novo_produto->fabricacao,fabricacao);
  strcpy(novo_produto->nome_departamento,nome_departamento);
  strcpy(novo_produto->validade,validade);
  novo_produto->estoque = estoque;
  novo_produto->preco = preco;
  //percorre todos os departamentos
  while(departamento_auxiliar != NULL){
    //verificando a qual departamento o produto pertence e armazenando no departamento
    if(strcmp(departamento_auxiliar->nome,nome_departamento) == 0){
      novo_produto->proximo_produto = departamento_auxiliar->lista_produtos;
      departamento_auxiliar->lista_produtos->produto_anterior = novo_produto;
      departamento_auxiliar->lista_produtos = novo_produto;
      departamento_auxiliar->quantidade_produtos++;
    }
    departamento_auxiliar = departamento_auxiliar->proximo_departamento;
  }
  departamento = departamento_auxiliar;
}

//função responsavel por buscar um produto pelo nome, para isso ela recebe um departamento e o nome do produto que queremos buscar
Produto* busca_produto(Departamento* departamento, char* nome_produto){
  Departamento* departamento_auxiliar = departamento;
  Produto* produto_auxiliar; 
   //percorre os departamentos e produtos para achar o produto
   while(departamento_auxiliar != NULL){
    produto_auxiliar = departamento_auxiliar->lista_produtos;
    while (produto_auxiliar != NULL){
      
   if(strcmp(produto_auxiliar->tipo, nome_produto) == 0){
      return produto_auxiliar;
    }
      produto_auxiliar = produto_auxiliar->proximo_produto;
    }
    departamento_auxiliar = departamento_auxiliar->proximo_departamento;
  }
  return NULL;
}

//função responsavel por listar a quantidade de produtos de cada departamento, para isso ela recebe um departamento como exemplo
void produtos_por_departamento(Departamento* departamento){
  Departamento* departamento_auxiliar = departamento;
 
  while(departamento_auxiliar!=NULL){
     if(verifica_departamento_vazio(departamento_auxiliar) == 0){
      printf("\ndepartamento: %s\neste departamento está vazio\n",departamento_auxiliar->nome);  
     }
     else{
      printf("\ndepartamento: %s\nquantidade de produtos: %d\n\n",departamento_auxiliar->nome,departamento_auxiliar->quantidade_produtos);
     }
    departamento_auxiliar = departamento_auxiliar->proximo_departamento;
  }

}

//função responsável por verificar se um departamento está vazio ou não
int verifica_departamento_vazio(Departamento* departamento){
    return(departamento->quantidade_produtos == 0);
}

//função que verifica a quantidade de produtos que estão em estoque de um determinado departamento, para isso ela recebe o departamento e o nome do departamento que estão os produtos que deseja listar
void verifica_produtos_estoque(Departamento* departamento, char*nome_departamento){
  Departamento* departamento_auxiliar=departamento;
  Produto* produto_auxiliar;
  while(departamento_auxiliar != NULL){
    //para verificar se o nome que o usuario digitou é o mesmo que o do departamento
    if(strcmp(departamento_auxiliar->nome,nome_departamento) == 0){
      produto_auxiliar=departamento_auxiliar->lista_produtos;
      
      if(verifica_departamento_vazio(departamento_auxiliar) == 0){
        printf("\nnenhum produto cadastrado nesse departamento\n");
      }
      //percorre todos os produtos
      while(produto_auxiliar != NULL){
        //para verificar se há produtos disponiveis em estoque
        if(produto_auxiliar->estoque != 0){
          printf("\n\nnome do produto: %s, quantidade disponivel: %d\n",produto_auxiliar->tipo,produto_auxiliar->estoque);
        }else{
          printf("\n\nnão há %s disponivel no estoque\n",produto_auxiliar->tipo);
        }
        produto_auxiliar=produto_auxiliar->proximo_produto;

      }

    }
  departamento_auxiliar = departamento_auxiliar->proximo_departamento;
  }
}

// remove um produto utilizando o nome do produto, essa função recebe um departamento e o nome do produto que deseja retirar 
void remove_produto(Departamento* departamento, char* nome_produto){
  int achou_produto=0; // para verificar se o produto existe
  Departamento* departamento_auxiliar = departamento;
  Produto* produto_auxiliar;
  Produto* produto_free; // variável auxiliar para libera a memoria alocada para o produto

  // percorre a lista departamento 
  while(departamento_auxiliar != NULL){
    produto_auxiliar = departamento_auxiliar->lista_produtos;

    // percorre a lista produto
    while (produto_auxiliar != NULL){

      //compara o nome do produto 
      if(strcmp(produto_auxiliar->tipo,nome_produto) == 0){
        // se ele for o primeiro da lista

        if(produto_auxiliar->produto_anterior == NULL){

          achou_produto++;
          produto_free = produto_auxiliar;
          produto_auxiliar = produto_auxiliar->proximo_produto;
          produto_auxiliar->produto_anterior = NULL;

        // se ele for o ultimo da lista
        }else if(produto_auxiliar->proximo_produto == NULL){

          achou_produto++;
          produto_free = produto_auxiliar;
          produto_auxiliar->produto_anterior->proximo_produto = NULL;
        
        // se ele estiver no meio da lista 
        }else{

        achou_produto++;
        produto_free = produto_auxiliar;
        produto_auxiliar->proximo_produto->produto_anterior = produto_auxiliar->produto_anterior;
        produto_auxiliar->produto_anterior->proximo_produto = produto_auxiliar->proximo_produto;
        
        }
        // dados do produto removido
        printf("\ndados do produto que foi removido: \n");
        printf("%s %s %s %d %.2f\n",produto_free->tipo, produto_free->validade,produto_free->fabricacao,produto_free->estoque, produto_free->preco);
        free(produto_free);
        //  printf("\nproduto removido com sucesso\n");
      }
      produto_auxiliar = produto_auxiliar->proximo_produto;
    }
    departamento_auxiliar = departamento_auxiliar->proximo_departamento;
  }
  // nao achou o produto
  if(achou_produto == 0){
    printf("\n\nproduto não encontrado");
  }
}

// essa função é responsavel libera memoria alocada, para isso o departamento é passado como parametro
void libera_memoria(Departamento* departamento){
  Departamento* departamento_auxiliar = departamento;
  Departamento* departamento_free; 
  Produto* produto;  
  Produto* produto_auxiliar;
  //para percorrer todos os departamentos
  while(departamento_auxiliar != NULL){
      produto = departamento_auxiliar->lista_produtos;
      while(produto != NULL){
        produto_auxiliar = produto;
        produto = produto->proximo_produto;
        free(produto_auxiliar);
      }
    departamento_free = departamento_auxiliar;
    departamento_auxiliar = departamento_auxiliar->proximo_departamento;
    free(departamento_free);
  }
}

// essa função imprime o menu que auxilia na edição do produto 
void imprime_menu_edita(){
  printf("\n\tMenu de edição de produto:\n");
  printf("o que deseja editar?\n");
  printf("1 - nome;\n2 - validade;\n3 - fabricacao;\n4 - nome do departamento;\n5 - quantidade em estoque;\n6 - preço;\n7 - sair\n");
}

// função responsavel por editar um produto, ela recebe um departamento e o nome do produto que deseja editar
void editar_produto(Departamento* departamento, char* nome_produto){
  Produto* produto_editar = busca_produto(departamento,nome_produto); // buscando o produto para a edição
  // variáveis auxiliares
  char tipo[50],validade[50],fabricacao[50],nome_departamento[50];
  int escolha = 0, opcao;

  printf("\nproduto a ser editado:\n");
  printf("nome do produto:%s\ndata de validade do produto:%s\ndata de fabricação do produto:%s\nquantidade em estoque desse produto:%d\npreço do produto:%.2f\n",produto_editar->tipo, produto_editar->validade,produto_editar->fabricacao,produto_editar->estoque, produto_editar->preco);

  do{

    imprime_menu_edita();
    printf("digite a opção que deseja: ");
    escolha=somente_numeros();
    switch (escolha){
      
      case 1://alterar nome do produto

        printf("digite novo nome do produto: \n");
        scanf(" %[^\n]", tipo);
        minuscula(tipo); // tornando o nome em minuscula, remove os caracteres especiais e numeros
        strcpy(produto_editar->tipo,tipo);
        break;

      case 2://alterar a data de validade

        printf("digite a nova data de validade: \n");
        scanf(" %[^\n]", validade);
        strcpy(produto_editar->validade,validade);
        break;

      case 3://alterar a data de fabricação

        printf("digite a nova data de fabricação: \n");
        scanf(" %[^\n]", fabricacao);
        strcpy(produto_editar->fabricacao,fabricacao);
        break;

      case 4: //alterar o nome do departamento

        printf("digite o novo nome do departamento: \n");
        scanf(" %[^\n]", nome_departamento);
        minuscula(nome_departamento); // tornando o nome em minuscula 
        //verificando se o departamento digitado existe no sisema
        //  if((verifica_departamento_existe(departamento,nome_departamento) == 1)){
          strcpy(produto_editar->nome_departamento,nome_departamento);
          imprime_no_arquivo_produto(departamento); // imprime no arquivo produto
          ler_produto_txt(departamento);// ler do arquivo produtos
        // }else{
        //   printf("departamento nao existe\n");
        // }
        break;

      case 5://alterar quantidade em estoque

        printf("digite a nova quantidade desse produto no estoque: \n");
        scanf("%d",&produto_editar->estoque);
        break;

      case 6://alterar preço

        printf("digite o novo preço do produto: \n");
        produto_editar->preco = somente_numeros_preco();
        // scanf("%f",&produto_editar->preco);
        break;

      case 7://sair do menu de edição

        printf("item editado com sucesso\n");
        printf("dados do produto: ");
        printf("nome do produto:%s\ndata de validade do produto:%s\ndata de fabricação do produto:%s\nquantidade em estoque:%d\npreço do produto:%.2f\ndepartamento do produto:%s",produto_editar->tipo, produto_editar->validade,produto_editar->fabricacao,produto_editar->estoque, produto_editar->preco,produto_editar->nome_departamento);
        break;

      default:

        printf("opção inválida\n");

        break;
    }
    // perguntar ao usuario se ele deseja alterar mais alguma informação
    do{
    printf("mais alguma alteraçao a ser feita ?\n 1-sim ou 2-não\n"); 
      opcao = somente_numeros();
    if(opcao == 2){
      printf("item editado com sucesso\n");
      printf("nome do produto: %s\ndata de validade do produto: %s\ndata de fabricação do produto: %s\nquantidade em estoque desse produto: %d\npreço do produto: %.2f\n",produto_editar->tipo, produto_editar->validade,produto_editar->fabricacao,produto_editar->estoque, produto_editar->preco);
      escolha = 7;
      opcao = 1;
    }else if(opcao != 2 ){
      printf("opcão invalida\n");
    }
    }while(opcao != 1);
  }while(escolha != 7);
}

// essa função imprime os dados dos produtos no arquivo produtos.txt, para isso o departamento é passado como parametro
void imprime_no_arquivo_produto(Departamento* departamento){
  Departamento* departamento_auxiliar = departamento;
  Produto* produto;
  FILE* arquivo_produto = fopen("/workspaces/SupermarketManagement/Supermarket_Managment/produtos.txt","wt");
  if(arquivo_produto == NULL){
    printf("erro no arquivo produto");
    exit(1);
  }
  while(departamento_auxiliar != NULL){
    produto = departamento_auxiliar->lista_produtos;
    while(produto != NULL){
      fprintf(arquivo_produto,"%s|%s|%s|%s|%d|%.2f\n",produto->nome_departamento,produto->tipo,produto->validade,produto->fabricacao,produto->estoque,produto->preco);
      produto = produto->proximo_produto; 
    }
    departamento_auxiliar = departamento_auxiliar->proximo_departamento;
    
  }
}

// essa função imprime os dados dos departamentos no arquivo departamentos.txt, para isso o departamento é passado como parametro
void imprime_no_arquivo_departamento(Departamento* departamento){
  Departamento* departamento_auxiliar = departamento;
  
  FILE* arquivo_departamento = fopen("/workspaces/SupermarketManagement/Supermarket_Managment/departamentos.txt","wt");
   if(arquivo_departamento == NULL){
    printf("erro no arquivo produto");
    exit(1);
  }
  while(departamento_auxiliar != NULL){
    
    fprintf(arquivo_departamento,"%s|%s\n",departamento_auxiliar->nome,departamento_auxiliar->porte);
    departamento_auxiliar = departamento_auxiliar->proximo_departamento;
    
  }
}
//essa função verifica se um departamento especifico existe, para isso ela recebe um departamento e o nome do departamento que deseja verificar se existir
int verifica_departamento_existe(Departamento* departamento, char* nome_departamento){
  Departamento* departamento_auxiliar = departamento;
  while(departamento_auxiliar != NULL){
    if(strcmp(departamento->nome,nome_departamento) == 0){
      return (1);
    }
    departamento_auxiliar = departamento_auxiliar->proximo_departamento;
  }
  return (-1);
}


// void insere_novo_produto_ordenado(Departamento* departamento, char* tipo, char* validade, char* fabricacao, int estoque, char* nome_departamento, float preco){
//     //inserção de elementos ordenados na lista duplamente encadeada
//     // Lista2 * novo = (Lista2*) malloc(sizeof(Lista2));
    
//     // novo->info = v;

//   Departamento* departamento_auxiliar = departamento;
//   Produto* novo_produto = aloca_produto();

//   strcpy(novo_produto->tipo,tipo);
//   strcpy(novo_produto->fabricacao,fabricacao);
//   strcpy(novo_produto->nome_departamento,nome_departamento);
//   strcpy(novo_produto->validade,validade);
//   novo_produto->estoque = estoque;
//   novo_produto->preco = preco;

//     // Lista2 * ant = NULL;
//     // Lista2 * p = l;

//     Produto* anterior = NULL;
//     Produto* produto_auxiliar; //= departamento_auxiliar->lista_produtos;
  
//   while(departamento_auxiliar != NULL){
//     produto_auxiliar = departamento_auxiliar->lista_produtos;
    
//     // while(p!=NULL && p->info < v){
//     //     ant = p;
//     //     p = p->prox;
//     // }

//     while(produto_auxiliar != NULL && strcmp(produto_auxiliar->tipo, novo_produto->tipo) < 0){
//       anterior = produto_auxiliar;
//       produto_auxiliar = produto_auxiliar->proximo_produto;
//     } 

//     // if(ant==NULL){
//     //     novo->prox = l;
//     //     novo->ant = NULL;
//     //     l->ant = novo;
//     //     return novo;
//     // }

//     if(anterior == NULL){
//       novo_produto->proximo_produto = produto_auxiliar->lista_produtos;
//       novo_produto->produto_anterior = NULL;
//       produto_auxiliar->anterior = novo_produto;
//       //return novo_produto;
//       departamento_auxiliar->lista_produtos = novo_produto;
//     }

//     // else{
//     //     novo->prox = ant->prox;
//     //     novo->ant = ant;
//     //     ant->prox = novo;
//     //     if(p!=NULL)
//     //         p->ant = novo;
//     //     return l;
//     // }

//     else{

//       novo_produto->proximo_produto = anterior->proximo_produto;
//       novo_produto->produto_anterior = anterior;
//       anterior->proximo_produto = novo_produto;
//       if(produto_auxiliar != NULL){
//         produto_auxiliar->produto_anterior = novo_produto;
//         departamento_auxiliar->lista_produtos = produto_auxiliar;
//         //return produto_auxiliar->lista_produtos;
//       }
//     }

//     departamento_auxiliar = departamento_auxiliar->proximo_departamento;
//   }

// }
