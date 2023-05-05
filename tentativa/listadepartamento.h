#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "departamento.c"

typedef struct listadepartamento ListaDepartamento;

void imprime_menu();

ListaDepartamento* cria_lista_departamento();

ListaDepartamento* ler_departamento_txt(char* linha);

void lista_imprime_txt(ListaDepartamento* lista_departamentos);

void lista_departamento_imprime(ListaDepartamento* lista_departamento);

void busca_produto(ListaDepartamento* lista_departamento, char* nome_produto);

void insere_novo_produto(ListaDepartamento* lista_departamento, char* tipo, char* validade, char* fabricacao, char* estoque, char* nome_departamento, float preco);

ListaDepartamento* ler_lista_departamentos(void);

void produtos_por_departamento(ListaDepartamento* lista_departamento);

void lista_produtos_departamento(ListaDepartamento* lista_departamento,char* nome_departamento);

void libera_memoria(ListaDepartamento* lista_departamento);

ListaDepartamento* ler_txt();

ListaProdutos* ler_lista_produto(ListaDepartamento* lista_departamento);