#include<stdio.h>
#include<stdlib.h>
#include "listaprodutos.c"

typedef struct departamento Departamento;

Departamento* aloca_departamento(void);

int verifica_departamento_vazio(Departamento* departamento);

int verifica_quantidade_produto(Departamento* departamento);
