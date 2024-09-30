#ifndef CARRINHO_H
#define CARRINHO_H

#include "produtos.h"

typedef struct {
    Produto produto;
    int quantidade;
} Carrinho;

void comprarProduto();
void visualizarCarrinho();
int temNoCarrinho(int codigo);

#endif
