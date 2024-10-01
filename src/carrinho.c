#include "carrinho.h" // Inclui o cabeçalho com a definição da estrutura 'Carrinho' e outras dependências
#include <stdio.h>
#include <windows.h> // Inclui a biblioteca para usar a função Sleep

#define MAX_CARRINHO 50 // Define o número máximo de itens que podem ser adicionados ao carrinho

// Declaração de um array de carrinhos e uma variável para contar o total de itens no carrinho
Carrinho carrinho[MAX_CARRINHO];
int totalCarrinho = 0;

// Função para comprar um produto
void comprarProduto() {
    // Verifica se há produtos cadastrados
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado! Por favor, cadastre produtos antes de realizar uma compra.\n");
        Sleep(2500); 
        system("cls"); // Limpa a tela
        return;
    }

    int codigo, quantidade; // Variáveis para armazenar o código do produto e a quantidade desejada
    listarProdutos(); // Lista os produtos cadastrados
    printf("Digite o codigo do produto que deseja comprar: ");
    scanf("%d", &codigo); // Lê o código do produto

    Produto prod = pegarProdutoPorCodigo(codigo); // Tenta pegar o produto pelo código
    if (prod.codigo != 0) { // Verifica se o produto foi encontrado
        printf("Quantidade: ");
        scanf("%d", &quantidade); // Lê a quantidade desejada

        int indice = temNoCarrinho(codigo); // Verifica se o produto já está no carrinho
        if (indice != -1) { // Se já está no carrinho, aumenta a quantidade
            carrinho[indice].quantidade += quantidade;
        } else if (totalCarrinho < MAX_CARRINHO) { // Se não está no carrinho e ainda há espaço
            Carrinho novoItem; // Cria um novo item para o carrinho
            novoItem.produto = prod; // Atribui o produto
            novoItem.quantidade = quantidade; // Atribui a quantidade
            carrinho[totalCarrinho] = novoItem; // Adiciona o novo item ao carrinho
            totalCarrinho++; // Incrementa o total de itens no carrinho
        } else {
            printf("Carrinho cheio.\n"); // Mensagem de erro se o carrinho estiver cheio
            Sleep(2000);
            system("cls"); // Limpa a tela
        }

        printf("Produto adicionado ao carrinho!\n"); // Mensagem de sucesso
        Sleep(2000);
        system("cls"); // Limpa a tela
    } else {
        printf("Produto nao encontrado.\n"); // Mensagem de erro se o produto não for encontrado
        Sleep(2000);
        system("cls"); // Limpa a tela
    }
}

// Função para visualizar os itens no carrinho
void visualizarCarrinho() {
    printf("\n=== Carrinho de Compras ===\n");
    printf(" %-30s %-10s %-10s\n", "Nome", "Preco", "Quantidade"); // Cabeçalho da tabela
    if (totalCarrinho > 0) { // Verifica se há itens no carrinho
        for (int i = 0; i < totalCarrinho; i++) { // Loop para listar todos os itens
            printf("%-30s R$ %-10.2f %-10d\n", carrinho[i].produto.nome, carrinho[i].produto.preco, carrinho[i].quantidade);
            /*printf("Nome: %s\nPreco:  R$%.2f\nQuantidade: %d\n", carrinho[i].produto.nome, carrinho[i].produto.preco, carrinho[i].quantidade);*/
        }
    } else {
        printf("Carrinho vazio.\n"); // Mensagem se o carrinho estiver vazio
        Sleep(2000);
        system("cls"); // Limpa a tela
    }
}

// Função que verifica se um produto já está no carrinho
int temNoCarrinho(int codigo) {
    for (int i = 0; i < totalCarrinho; i++) { // Loop para verificar os itens no carrinho
        if (carrinho[i].produto.codigo == codigo) { // Se o código do produto corresponder
            return i; // Retorna o índice do produto no carrinho
        }
    }
    return -1; // Retorna -1 se o produto não estiver no carrinho
}

// Função para remover um produto do carrinho
void removerProdutoDoCarrinho() {
    // Verifica se o carrinho está vazio
    if (totalCarrinho == 0) {
        printf("O carrinho esta vazio!\n");
        Sleep(2500);
        system("cls"); // Limpa a tela
        return;
    }

    listarProdutos(); // Lista os produtos cadastrados 

    int codigo; // Variável para armazenar o código do produto a ser removido
    printf("Digite o codigo do produto a ser removido: ");
    scanf("%d", &codigo); // Lê o código do produto a ser removido

    int encontrado = -1; // Inicializa a variável para verificar se o produto foi encontrado
    // Procurar o produto no carrinho
    for (int i = 0; i < totalCarrinho; i++) {
        if (carrinho[i].produto.codigo == codigo) { // Se o código corresponder
            encontrado = i; // Armazena o índice do produto encontrado
            break;
        }
    }

    // Verifica se o produto foi encontrado
    if (encontrado == -1) {
        printf("Produto nao encontrado no carrinho!\n"); // Mensagem se não encontrado
        Sleep(2500);
        system("cls"); // Limpa a tela
        return;
    }

    // Se a quantidade for maior que 1, perguntar quantas unidades remover
    if (carrinho[encontrado].quantidade > 1) {
        int removerUnidades; // Variável para armazenar a quantidade a ser removida
        printf("Quantidade no carrinho: %d\n", carrinho[encontrado].quantidade);
        printf("Quantas unidades deseja remover? (Digite 0 para cancelar): ");
        scanf("%d", &removerUnidades); // Lê a quantidade a ser removida

        // Verifica a quantidade a ser removida
        if (removerUnidades > 0 && removerUnidades < carrinho[encontrado].quantidade) {
            carrinho[encontrado].quantidade -= removerUnidades; // Remove a quantidade desejada
            printf("%d unidades removidas do produto %s.\n", removerUnidades, carrinho[encontrado].produto.nome);
        } else if (removerUnidades >= carrinho[encontrado].quantidade) {
            printf("Removendo todas as unidades do produto %s.\n", carrinho[encontrado].produto.nome);
            // Remover o item completamente
            for (int i = encontrado; i < totalCarrinho - 1; i++) {
                carrinho[i] = carrinho[i + 1]; // Desloca os itens para preencher o "buraco"
            }
            totalCarrinho--; // Decrementa o total de itens no carrinho
        } else {
            printf("Operacao cancelada.\n"); // Mensagem de cancelamento
        }
    } else {
        // Se a quantidade for 1, remove o produto do carrinho
        printf("Removendo o produto %s do carrinho.\n", carrinho[encontrado].produto.nome);
        for (int i = encontrado; i < totalCarrinho - 1; i++) {
            carrinho[i] = carrinho[i + 1]; // Desloca os itens para preencher o "buraco"
        }
        totalCarrinho--; // Decrementa o total de itens no carrinho
    }
}
