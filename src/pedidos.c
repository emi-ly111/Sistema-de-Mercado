#include "pedidos.h" // Inclui o cabeçalho com a definição da função 'fecharPedido'
#include "carrinho.h" // Inclui o cabeçalho com a definição do carrinho e suas funções
#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

// Função para fechar o pedido
void fecharPedido() {
    // Verifica se há produtos no carrinho
    if (totalCarrinho > 0) {
        float total = 0; // Inicializa a variável para o total a pagar
        printf("\n=== Fechamento de Pedido ===\n"); // Cabeçalho do fechamento de pedido
        for (int i = 0; i < totalCarrinho; i++) { // Loop para calcular o subtotal de cada produto
            float subtotal = carrinho[i].produto.preco * carrinho[i].quantidade; // Calcula o subtotal
            // Exibe o nome do produto, quantidade e subtotal
            printf("%s - %d unidade(s) - R$ %.2f\n", carrinho[i].produto.nome, carrinho[i].quantidade, subtotal);
            total += subtotal; // Adiciona o subtotal ao total
        }
        // Exibe o total a pagar
        printf("Total a pagar: R$ %.2f\n", total);
        totalCarrinho = 0; // Limpa o carrinho após o fechamento do pedido
        printf("Pedido fechado com sucesso!\n"); // Mensagem de sucesso
    } else {
        // Mensagem se o carrinho estiver vazio
        printf("Carrinho vazio.\n");
        Sleep(1500); // Pausa para visualização
        system("cls"); // Limpa a tela
    }
}
