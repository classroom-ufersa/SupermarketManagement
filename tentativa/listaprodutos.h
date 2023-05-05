#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "produto.c"
#include"listadepartamento.c"

typedef struct listaprodutos ListaProdutos;

ListaProdutos* cria_lista_produto();

ListaProdutos* ler_produto_txt(char* linha);

ListaProdutos* ler_lista_produto(ListaDepartamento* lista_departamento);