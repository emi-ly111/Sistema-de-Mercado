#include <stdio.h>
#include <stdlib.h>
#include "produtos.c"
#include "carrinho.c"
#include "pedidos.c"

// Declaração da função 'menu'
void menu();

// Função principal do programa
int main() {
    printarImagem(); // Chama a função para imprimir a imagem
    menu(); // Chama a função 'menu' para iniciar o sistema
    return 0; // Retorna 0, indicando que o programa terminou com sucesso
}

// Função que exibe o menu de opções para o usuário
void menu() {
    int opcao; // Variável para armazenar a opção escolhida pelo usuário
    do {
        // Exibe o título e as opções disponíveis
        printf("\n=== WELDES SUPER STORE ===\n");
        printf("Bem vindo(a)!\n\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Comprar Produto\n");
        printf("4. Visualizar Carrinho\n");
        printf("5. Remover Produto do Carrinho\n");
        printf("6. Fechar Pedido\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário

        // Executa a ação correspondente à opção escolhida
        switch (opcao) {
            case 1: cadastrarProduto(); break; // Chama a função para cadastrar um produto
            case 2: listarProdutos(); break; // Chama a função para listar produtos cadastrados
            case 3: comprarProduto(); break; // Chama a função para comprar um produto
            case 4: visualizarCarrinho(); break; // Chama a função para visualizar o carrinho
            case 5: removerProdutoDoCarrinho(); break; // Chama a função para remover um produto do carrinho
            case 6: fecharPedido(); break; // Chama a função para fechar o pedido
            case 7: printf("Encerrando o sistema...\n"); break; // Exibe mensagem de encerramento
            default: printf("Opcao invalida! Tente novamente.\n"); // Exibe mensagem de erro para opção inválida
        }
    } while (opcao != 7); // Continua o loop até que a opção 7 (sair) seja escolhida
}

// Função que imprime o desenho de mercadinho
void printarImagem(){
    printf("  ######################################################\n");
	printf("  ##  ::::::::::::::::::::::::::::::::::::::::::::--  ##\n");
	printf("  ##  ##------------------------------------------##  ##\n");
	printf("  ##  ##                                          ##  ##\n");
	printf("  ##  ##------------------------------------------##  ##\n");
	printf("  ##  --------------------------------------------..  ##\n");
	printf("  ######################################################\n");
	printf("##  ##  ##  ##    ++  ##  ##  ##  ##  ::++  ##  ##  ##\n");
	printf("@@    ##  ##  ##  @@    ##  ##  ##  mm    ##  ##  ##  @@::\n");
	printf("##  ##    ##  ##  ##    @@  ##  ##    MM  ##  ##  --++  ##\n");
	printf("##  ##  @@    ##  ##    ++  ##  ##    ##  ##  @@--  ##  ##\n");
	printf("##########################################################\n");
	printf("  ##                                                  ##\n");
	printf("  ##    ########################      ############    ##\n");
	printf("  ##    ##                    ##    mm::        ##    ##\n");
	printf("  ##  mm::                    ##..  ##          ##    ##\n");
	printf("  ##  ############################  ##############++  ##\n");
	printf("  ##    ##                    ##      ##########      ##\n");
	printf("  ##    ##                    ##      ##      ##      ##\n");
	printf("  ##    ##                    ##      ##      ##      ##\n");
	printf("  ##    ##                    ##      ##      ##      ##\n");
	printf("  ##    ########################      ##      ##      ##\n");
	printf("  ##                                  ##mmmmmm##      ##\n");
	printf("  ##                                  ##      ##      ##\n");
	printf("  ##########################################################\n\n");
}
