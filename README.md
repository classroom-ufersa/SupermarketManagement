# Supermarket-Inventory-Management-System
## Problematica: 
Criar um progama em linguagem c que gerencia um estoque de supermercado, utilizando os conteúdos vistos nas 3 unidades da máteria Algoritmos e Estrutura de Dados 1
## Recursos disponiveis no sistema:
- **`Adicionar produto`**
```c
//essa função recebe todos os dados necessarios para criar um produto e guarda o produto em um departamento;
void insere_novo_produto(Departamento* departamento, char* tipo, char* validade, char* fabricacao, int estoque, char* nome_departamento, float preco){
  
  Departamento* departamento_auxiliar = departamento;
  Produto* novo_produto = aloca_produto();
  if(novo_produto == NULL){
    printf("erro!!!");
    exit(1);
  }
  
  strcpy(novo_produto->tipo,tipo);
  strcpy(novo_produto->fabricacao,fabricacao);
  strcpy(novo_produto->nome_departamento,nome_departamento);
  strcpy(novo_produto->validade,validade);
  novo_produto->estoque = estoque;
  novo_produto->preco = preco;

  while(departamento_auxiliar != NULL){
    
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
```
- **`Remover produto`** 
```c
//essa função usa o nome do produto e a lista de departamentos para conseguir retirar um produto do sistema;
void remove_produto(Departamento* departamento, char* nome_produto){
  int achou_produto=0;
  Departamento* departamento_auxiliar = departamento;
  Produto* produto_auxiliar;
  Produto* produto_free;

  while(departamento_auxiliar != NULL){
    produto_auxiliar = departamento_auxiliar->lista_produtos;
    
    while (produto_auxiliar != NULL){
      
      if(strcmp(produto_auxiliar->tipo,nome_produto) == 0){
        if(produto_auxiliar->produto_anterior == NULL){

          achou_produto++;
          produto_free = produto_auxiliar;
          produto_auxiliar = produto_auxiliar->proximo_produto;
          produto_auxiliar->produto_anterior = NULL;

        }else if(produto_auxiliar->proximo_produto == NULL){

          achou_produto++;
          produto_free = produto_auxiliar;
          produto_auxiliar->produto_anterior->proximo_produto = NULL;

        }else{

        achou_produto++;
        produto_free = produto_auxiliar;
        produto_auxiliar->proximo_produto->produto_anterior = produto_auxiliar->produto_anterior;
        produto_auxiliar->produto_anterior->proximo_produto = produto_auxiliar->proximo_produto;

        }
         printf("%s %s %s %d %.2f\n",produto_free->tipo, produto_free->validade,produto_free->fabricacao,produto_free->estoque, produto_free->preco);
         free(produto_free);
         printf("\nproduto removido com sucesso\n");
      }
      produto_auxiliar = produto_auxiliar->proximo_produto;
    }
    departamento_auxiliar = departamento_auxiliar->proximo_departamento;
  }
  if(achou_produto == 0){
    printf("\n\nproduto não encontrado");
  }
}
```
- **`Listar produtos cadastrados`**
```c
//essa função recebe nosso a lista de departamento e imprime todos os produtos e departamentos que estão no sistema;
void lista_departamento_imprime(Departamento* departamento){
  Departamento* departamento_auxiliar = departamento; 
  Produto* lista_produtos;

  while(departamento_auxiliar != NULL){
    if(departamento_auxiliar->quantidade_produtos == 0){
      printf("\ndepartamento: %s, nenhum produto nesse departamento;\n",departamento_auxiliar->nome);
    }
    else{
    printf("\n\nnome do departamento: %s, quantidade de produtos nesse departamento: %d\n", departamento_auxiliar->nome,departamento_auxiliar->quantidade_produtos);
    lista_produtos = departamento_auxiliar->lista_produtos;

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
```
- **`Editar produto`**
```c
//essa função utiliza a lista de departamentos e um nome digitado pelo usuario para editar algum dado do determinado produto;
void* editar_produto(Departamento* departamento, char* nome_produto){
  Produto* produto_editar = busca_produto(departamento,nome_produto);
  char tipo[50],validade[50],fabricacao[50],nome_departamento[50];
  int escolha = 0, opcao;

  printf("nome do produto:%s\ndata de validade do produto:%s\ndata de fabricação do produto:%s\nquantidade em estoque desse produto:%d\npreço do produto:%.2f\n",produto_editar->tipo, produto_editar->validade,produto_editar->fabricacao,produto_editar->estoque, produto_editar->preco);

  do{
    imprime_menu_edita();
    printf("digite a opção que deseja: ");
    escolha=somente_numeros();//garante que o usuario só vai digitar numeros
    switch (escolha){
      case 1:
        printf("digite novo nome do produto: \n");
        scanf(" %[^\n]", tipo);
        minuscula(tipo);
        strcpy(produto_editar->tipo,tipo);
        break;
      case 2:
        printf("digite a nova data de validade: \n");
        scanf(" %[^\n]", validade);
        minuscula(validade);
        strcpy(produto_editar->validade,validade);
        break;
      case 3:
        printf("digite a nova data de fabricação: \n");
        scanf(" %[^\n]", fabricacao);
        minuscula(fabricacao);
        strcpy(produto_editar->fabricacao,fabricacao);
        break;
      case 4:
        printf("digite o novo nome do departamento: \n");
        scanf(" %[^\n]", nome_departamento);
        minuscula(nome_departamento);
        strcpy(produto_editar->nome_departamento,nome_departamento);
        break;
      case 5:
        printf("digite a nova quantidade desse produto no estoque: \n");
        scanf("%d",&produto_editar->estoque);
        break;
      case 6:
        printf("digite o novo preço do produto: \n");
        scanf("%f",&produto_editar->preco);
        break;
      case 7:
        printf("item editado com sucesso\n");
        printf("%s %s %s %d %.2f\n",produto_editar->tipo, produto_editar->validade,produto_editar->fabricacao,produto_editar->estoque, produto_editar->preco);
        break;
      default:
        printf("opção inválida\n");
        break;
    }

    do{
    printf("mais alguma alteraçao a ser feita ?\n 1-sim ou 2-não\n");
      opcao = somente_numeros();
    if(opcao == 2){
      printf("item editado com sucesso\n");
      printf("nome do produto: %s\ndata de validade do produto: %s\ndata de fabricação do produto: %s\nquantidade em estoque desse produto: %d\npreço do produto: %.2f\n",produto_editar->tipo, produto_editar->validade,produto_editar->fabricacao,produto_editar->estoque, produto_editar->preco);
      escolha = 7;
      opcao = 1;
    }else if(opcao != 2){
      printf("opcão invalida\n");
    }
    }while(opcao != 1);
  }while(escolha != 7);
}
```
- **`Consultar produtos disponiveis em um departamento`**
```c
//essa função recebe a lista de departamentos e o nome do produto e verifica se esse produto está disponivel em estoque;
void verifica_produtos_estoque(Departamento* departamento, char*nome_departamento){
  Departamento* departamento_auxiliar=departamento;
  Produto* produto_auxiliar;
  while(departamento_auxiliar != NULL){

    if(strcmp(departamento_auxiliar->nome,nome_departamento) == 0){
      
      produto_auxiliar=departamento_auxiliar->lista_produtos;
      
      if(verifica_departamento_vazio(departamento_auxiliar) == 0){
        printf("\nnenhum produto cadastrado nesse departamento\n");
      }
      
      while(produto_auxiliar != NULL){

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
```
- **`Consultar quantidade de produtos por departamento`**
```c
//essa função imprime a quantidade de produtos de cada departamento;
void produtos_por_departamento(Departamento* departamento){
  Departamento* departamento_auxiliar = departamento;
 
  while(departamento_auxiliar!=NULL){
      printf("\ndepartamento: %s\nquantidade de produtos: %d\n\n",departamento_auxiliar->nome,departamento_auxiliar->quantidade_produtos);
   
    departamento_auxiliar = departamento_auxiliar->proximo_departamento;
  }

}
```
- **`Sair`**
    - Essa funcionalidade é responsavel pela finalização o programa.
