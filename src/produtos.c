#include "produtos.h" // Inclui o cabeçalho com a definição da estrutura 'Produto'
#include <stdio.h>
#include <string.h>
#include <windows.h> // Inclui a biblioteca para usar a função Sleep
#include <ctype.h> //para a função isdigit

#define MAX_PRODUTOS 50 // Define o número máximo de produtos que podem ser cadastrados

// Declaração de um array de produtos e uma variável para contar o total de produtos
Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

// Função que verifica se o nome do produto é inválido
int nomeInvalido(char nome[]) {
    for (int i = 0; i < strlen(nome); i++) {
        if (isdigit(nome[i])) { // Verifica se há dígitos no nome
            return 1; // Retorna 1 se o nome é inválido
        }
    }
    return 0; // Retorna 0 se o nome é válido
}

// Função que verifica se o preço inserido é válido
int precoInvalido(float *preco) {
    if (scanf("%f", preco) != 1) { // Tenta ler um float
        fflush(stdin); // Limpa o buffer de entrada
        return 1; // Retorna 1 se a leitura falhou
    }
    return 0; // Retorna 0 se a leitura foi bem-sucedida
}

// Função para cadastrar um novo produto
void cadastrarProduto() {
    if (totalProdutos < MAX_PRODUTOS) { // Verifica se ainda há espaço para cadastrar produtos
        Produto novoProduto; // Cria uma nova instância do Produto
        novoProduto.codigo = totalProdutos + 1; // Atribui um código único ao produto

        do {
            printf("Nome do produto: ");
            fflush(stdin); // Limpa o buffer de entrada
            scanf("%100[^\n]", novoProduto.nome); // Lê o nome do produto
            if (nomeInvalido(novoProduto.nome)) { // Verifica se o nome é inválido
                printf("Erro: Nome invalido. Tente novamente.\n"); // Exibe mensagem de erro
            }
        } while (nomeInvalido(novoProduto.nome)); // Continua pedindo o nome até que seja válido

        printf("Preco do produto: ");
        scanf("%f", &novoProduto.preco); // Lê o preço do produto
        
        // Código comentado que verifica se o preço é inválido (não está em uso atualmente)
        /*if(precoInvalido(&novoProduto.preco)){
            printf("Erro: Preco invalido. Por favor, tente novamente.\n");
            return;
        }*/

        produtos[totalProdutos] = novoProduto; // Adiciona o novo produto ao array
        totalProdutos++; // Incrementa o total de produtos cadastrados

        printf("\nProduto cadastrado com sucesso!\n"); // Mensagem de sucesso
        Sleep(2000); // Pausa por 2 segundos
        system("cls"); // Limpa a tela
    } else {
        printf("\nLimite de produtos atingido.\n"); // Mensagem se o limite for atingido
        Sleep(2000); // Pausa por 2 segundos
        system("cls"); // Limpa a tela
    }
}

// Função para listar todos os produtos cadastrados
void listarProdutos() {
    if (totalProdutos == 0) { // Verifica se não há produtos cadastrados
        printf("\nNenhum produto cadastrado no sistema.\n"); // Mensagem informativa
    } else {
        printf("\n=== Lista de Produtos ===\n");
        printf("%-10s %-30s %-10s\n", "Codigo", "Nome", "Preco"); // Cabeçalho da tabela
        for (int i = 0; i < totalProdutos; i++) { // Loop para listar todos os produtos
            printf("%-10d %-30s R$ %-10.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
        }
    }
}

// Função que retorna um produto com base no código fornecido
Produto pegarProdutoPorCodigo(int codigo) {
    for (int i = 0; i < totalProdutos; i++) { // Loop para buscar o produto
        if (produtos[i].codigo == codigo) { // Verifica se o código corresponde
            return produtos[i]; // Retorna o produto encontrado
        }
    }
    Produto vazio = {0, "", 0.0}; // Produto vazio (padrão) se não for encontrado
    return vazio; // Retorna o produto vazio
}
