# Simulador-de-Mercado-Trabalho-Final-Giovane
Projeto Final - Programação e Sistemas Computacionais II



Integrante 1: Bloco 1 - Catalogo de Produtos & Arvore Binaria (ABB)O que voce faz: E o responsavel por toda a estrutura de dados dos produtos do supermercado utilizando uma Arvore Binaria de Busca (ABB).   
O que esta no seu bloco:
Struct NoProduto (guarda codigo, nome, preco e os ponteiros esquerda e direita).   
Funcao inserirProduto: insere novos produtos na arvore de forma recursiva baseada no codigo.   
Funcao exibirCatalogo: faz a travessia in-ordem para listar todos os produtos cadastrados ordenados por codigo.   
Funcao buscarProduto: busca um produto especifico na arvore pelo codigo.   
Funcao carregarCatalogoInicial: pre-carrega os produtos padrao logo que o sistema abre.   



Integrante 2: Bloco 2 - Carrinho de Compras & Pilha (LIFO)O que voce faz: E o responsavel por simular o carrinho de compras do cliente utilizando a semantica de Pilha (LIFO - O ultimo a entrar e o primeiro a sair).   
O que esta no seu bloco:
Struct ItemCarrinho e a struct PilhaCarrinho (com o ponteiro topo).   
Funcao empilhar (Push): pega um produto do catalogo e o adiciona no topo do carrinho (alocando memoria com new).   
Funcao desempilhar (Pop): remove o ultimo item adicionado caso o cliente desista daquele produto (liberando memoria com delete).   
Funcao exibirCarrinho: lista todos os itens que estao no carrinho atualmente e calcula o valor total da compra acumulado.   



Integrante 3: Bloco 3 - Fila do Caixa & Atendimento (FIFO)O que voce faz: E o responsavel por gerenciar o fluxo dos clientes que terminaram as compras e foram para a fila de pagamento do caixa usando a semantica de Fila (FIFO - O primeiro a chegar e o primeiro a ser atendido).   
O que esta no seu bloco:
Struct ClienteFila e a struct FilaCaixa (controlando o inicio e o fim da fila).   
Funcao entrarFila (Enqueue): adiciona um novo cliente no fim da fila de atendimento do caixa (com new).   
Funcao exibirFila: mostra todos os clientes que estao aguardando na fila e suas posicoes.   
Funcao chamarProximo (Dequeue): atira o primeiro cliente da fila, chamando-o para o caixa e liberando a memoria dele (delete).   



Integrante 4: Bloco 4 - Algoritmos, Menu Principal e Integracao (main)O que voce faz: E o responsavel por coordenar o sistema, estruturar o menu interativo em looping continuo e garantir que todas as funcoes dos colegas funcionem perfeitamente juntas.   O que esta no seu bloco:
Funcao de ordenacao (ordenarPrecos usando Insertion Sort) para cumprir os requisitos de algoritmos do professor.   
A estrutura principal int main() contendo o laco do-while que mantem o menu rodando de forma fluida ate o usuario escolher sair.   
Os comandos switch-case que ligam as opcoes do usuario diretamente as funcoes criadas pelos integrantes 1, 2 e 3.   