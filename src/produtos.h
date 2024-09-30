#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

void cadastrarProduto();
void listarProdutos();
Produto pegarProdutoPorCodigo(int codigo);

#endif

