#include "produtos.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX_PRODUTOS 50

Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

void cadastrarProduto() {
    if (totalProdutos < MAX_PRODUTOS) {
        Produto novoProduto;
        novoProduto.codigo = totalProdutos + 1;
        printf("Nome do produto: ");
        fflush(stdin);
        scanf("%100[^\n]", novoProduto.nome);
        printf("Preco do produto: ");
        scanf("%f", &novoProduto.preco);

        produtos[totalProdutos] = novoProduto;
        totalProdutos++;

        printf("Produto cadastrado com sucesso!\n");
        Sleep(1500);
        system("cls");
    } else {
        printf("Limite de produtos atingido.\n");
        Sleep(1500);
        system("cls");
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
