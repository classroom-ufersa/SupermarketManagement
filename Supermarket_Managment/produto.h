
typedef struct produto Produto;

// aloca um produto;
Produto* aloca_produto(void);

// recebe a linha que leu do aquivo produto aloca um produto e retorna o produto preenchido;
Produto* ler_linha_produto(char* linha);
