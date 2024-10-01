# Sistema de Supermercado em C

## Descrição do Projeto

Este projeto é um sistema simples de supermercado desenvolvido em C, utilizando conceitos de estrutura de dados como structs, arrays e funções. O sistema permite o cadastro de produtos, listagem, adição ao carrinho, visualização do carrinho, remoção de produtos e fechamento de pedidos.

## Estrutura do Código

O sistema é organizado em diferentes arquivos de código, cada um responsável por uma parte específica do sistema:

- **`produtos.h` e `produtos.c`**: Contêm a definição da struct `Produto` e funções para cadastrar e listar produtos.
- **`carrinho.h` e `carrinho.c`**: Definem a struct `Carrinho` e funções para gerenciar a adição e remoção de produtos no carrinho.
- **`pedidos.h` e `pedidos.c`**: Implementam a função para fechar um pedido, calcular o total da compra e exibir a fatura.
- **`main.c`**: Contém a função principal do programa, gerenciando o fluxo do sistema e interações com o usuário.

## Funcionamento do Sistema

1. **Cadastro de Produtos**:
   - O usuário pode cadastrar novos produtos fornecendo um código único, nome e preço.
   - Cada produto é armazenado em um array estático de `Produto`.

2. **Listagem de Produtos**:
   - O sistema lista todos os produtos cadastrados, mostrando o código, nome e preço.

3. **Compra de Produtos**:
   - O usuário pode adicionar produtos ao carrinho selecionando pelo código.
   - Se o produto já estiver no carrinho, a quantidade é aumentada ao invés de duplicar.

4. **Visualização do Carrinho**:
   - O usuário pode visualizar os produtos no carrinho, juntamente com as quantidades.

5. **Remoção de Produtos**:
   - O usuário poderá remover produtos do carrinhp que não deseja mais.

6. **Fechamento de Pedido**:
   - O sistema calcula o valor total da compra e exibe um resumo detalhado.
   - Após fechar o pedido, o carrinho é esvaziado e o sistema retorna ao menu principal.

## Funções Principais

1. - cadastrarProduto();
2. - listarProdutos();
3. - comprarProduto();  
4. - visualizarCarrinho();
5. - removerProdutoDoCarrinho();
6. - fecharPedido();

### Compilação e Execução via Botão de Play no Vscode

**Esse projeto foi feito diretamente pelo Vscode**, siga o passo a passo para compilar o projeto por essa IDE:

- Certifique-se de que você tem o Code Runner instalado. Se não tiver, você pode instalá-lo a partir da extensão do Visual Studio Code.
- Abra o arquivo principal (main.c).
- Clique no botão de "Play" que aparece na parte superior direita da tela. Isso irá compilar e executar o programa automaticamente.


