#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct {
    int codigo;
    char nome[100];
    float preco;
} Produto;

void cadastrarProduto();
void listarProdutos();
Produto pegarProdutoPorCodigo(int codigo);

#endif

