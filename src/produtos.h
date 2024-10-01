#ifndef PRODUTOS_H // Verifica se o cabeçalho não foi incluído anteriormente
#define PRODUTOS_H // Define o cabeçalho

// Define a estrutura Produto
typedef struct {
    int codigo; // Código do produto
    char nome[100]; // Nome do produto, com tamanho máximo de 100 caracteres
    float preco; // Preço do produto
} Produto; // Fim da definição da estrutura Produto

// Declaração da função para cadastrar um novo produto
void cadastrarProduto();
// Declaração da função para listar todos os produtos cadastrados
void listarProdutos();
// Declaração da função para buscar um produto pelo código
Produto pegarProdutoPorCodigo(int codigo); // Recebe o código do produto e retorna o produto correspondente

#endif // Fim da verificação de inclusão do cabeçalho
