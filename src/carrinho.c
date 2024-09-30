#include "carrinho.h"
#include <stdio.h>

#define MAX_CARRINHO 50

Carrinho carrinho[MAX_CARRINHO];
int totalCarrinho = 0;

void comprarProduto() {
    int codigo, quantidade;
    listarProdutos();
    printf("Digite o codigo do produto que deseja comprar: ");
    scanf("%d", &codigo);

    Produto prod = pegarProdutoPorCodigo(codigo);
    if (prod.codigo != 0) {
        printf("Quantidade: ");
        scanf("%d", &quantidade);

        int indice = temNoCarrinho(codigo);
        if (indice != -1) {
            carrinho[indice].quantidade += quantidade;
        } else if (totalCarrinho < MAX_CARRINHO) {
            Carrinho novoItem;
            novoItem.produto = prod;
            novoItem.quantidade = quantidade;
            carrinho[totalCarrinho] = novoItem;
            totalCarrinho++;
        } else {
            printf("Carrinho cheio.\n");
        }

        printf("Produto adicionado ao carrinho!\n");
    } else {
        printf("Produto nao encontrado.\n");
    }
}

void visualizarCarrinho() {
    printf("\n=== Carrinho de Compras ===\n");
    if (totalCarrinho > 0) {
        for (int i = 0; i < totalCarrinho; i++) {
            printf("%s (Quantidade: %d)\n", carrinho[i].produto.nome, carrinho[i].quantidade);
        }
    } else {
        printf("Carrinho vazio.\n");
    }
}

int temNoCarrinho(int codigo) {
    for (int i = 0; i < totalCarrinho; i++) {
        if (carrinho[i].produto.codigo == codigo) {
            return i;
        }
    }
    return -1;
}
