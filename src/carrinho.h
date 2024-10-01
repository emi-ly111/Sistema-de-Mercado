#ifndef CARRINHO_H // Verifica se o cabeçalho não foi incluído anteriormente
#define CARRINHO_H // Define o cabeçalho

#include "produtos.h" // Inclui o cabeçalho produtos.h para usar a estrutura Produto

// Define a estrutura Carrinho
typedef struct {
    Produto produto; // Produto associado ao item no carrinho
    int quantidade; // Quantidade do produto no carrinho
} Carrinho; // Fim da definição da estrutura Carrinho

// Declaração da função para comprar um produto e adicioná-lo ao carrinho
void comprarProduto();
// Declaração da função para visualizar os produtos no carrinho
void visualizarCarrinho();
// Declaração da função para verificar se um produto está no carrinho
int temNoCarrinho(int codigo); // Recebe o código do produto e retorna o índice se encontrado, ou -1 se não estiver
// Declaração da função para remover um produto do carrinho
void removerProdutoDoCarrinho();

#endif // Fim da verificação de inclusão do cabeçalho
