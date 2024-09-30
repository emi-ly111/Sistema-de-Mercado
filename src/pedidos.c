#include "pedidos.h"
#include "carrinho.h"
#include <stdio.h>

void fecharPedido() {
    if (totalCarrinho > 0) {
        float total = 0;
        printf("\n=== Fechamento de Pedido ===\n");
        for (int i = 0; i < totalCarrinho; i++) {
            float subtotal = carrinho[i].produto.preco * carrinho[i].quantidade;
            printf("%s - %d unidade(s) - R$ %.2f\n", carrinho[i].produto.nome, carrinho[i].quantidade, subtotal);
            total += subtotal;
        }
        printf("Total a pagar: R$ %.2f\n", total);
        totalCarrinho = 0;
        printf("Pedido fechado com sucesso!\n");
    } else {
        printf("Carrinho vazio.\n");
    }
}
