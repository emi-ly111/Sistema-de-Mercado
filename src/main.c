#include <stdio.h>
#include "produtos.c"
#include "carrinho.c"
#include "pedidos.c"

void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int opcao;
    do {
        printf("\n=== Sistema de Supermercado ===\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Comprar Produto\n");
        printf("4. Visualizar Carrinho\n");
        printf("5. Fechar Pedido\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: listarProdutos(); break;
            case 3: comprarProduto(); break;
            case 4: visualizarCarrinho(); break;
            case 5: fecharPedido(); break;
            case 6: printf("Encerrando o sistema...\n"); break;
            default: printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);
}

