#include "produtos.h"
#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 50

Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

void cadastrarProduto() {
    if (totalProdutos < MAX_PRODUTOS) {
        Produto novoProduto;
        novoProduto.codigo = totalProdutos + 1;
        printf("Nome do produto: ");
        scanf("%s", novoProduto.nome);
        printf("Preco do produto: ");
        scanf("%f", &novoProduto.preco);

        produtos[totalProdutos] = novoProduto;
        totalProdutos++;

        printf("Produto cadastrado com sucesso!\n");
    } else {
        printf("Limite de produtos atingido.\n");
    }
}

void listarProdutos() {
    printf("\n=== Lista de Produtos ===\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Codigo: %d, Nome: %s, Preco: R$ %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }
}

Produto pegarProdutoPorCodigo(int codigo) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return produtos[i];
        }
    }
    Produto vazio = {0, "", 0.0};
    return vazio;
}
