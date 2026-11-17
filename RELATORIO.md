Relatório Técnico — Simulador de Supermercado em C++ 

ntegrantes: Vitor Rafael, Carlos Beltrão, Kauã Santos e Lucas Siqueira


1. Escolha das Estruturas de Dados

Para representar o funcionamento real de um supermercado, cada estrutura de dados foi escolhida de acordo com a necessidade de cada etapa do sistema:

Árvore Binária de Busca (Catálogo de Produtos): Escolhida para armazenar os produtos organizados pelo código numérico. Ela permite buscar qualquer produto rapidamente sem precisar percorrer toda a lista um por um, além de exibir todo o catálogo já ordenado por código usando a travessia in-ordem.

Pilha - LIFO (Carrinho de Compras): Escolhida porque simula o comportamento físico de colocar itens em uma cesta ou carrinho. O último produto colocado no topo é o primeiro a ser retirado caso o cliente desista da compra (removerCarrinho).

Fila - FIFO (Atendimento no Caixa): Escolhida para garantir ordem justa no pagamento. O primeiro cliente que entra na fila (entrarFila) é obrigatoriamente o primeiro a ser chamado pelo caixa (chamarProximo)

.2. Algoritmo de Ordenação e Complexidade

Para exibir o catálogo organizado do produto mais barato para o mais caro, foi implementado manualmente o algoritmo Insertion Sort (ordenarPrecos).

Como funciona no projeto: Como os produtos ficam na árvore binária, o sistema primeiro copia os ponteiros dos nós para um vetor temporário e depois o Insertion Sort organiza esse vetor comparando os preços.

Por que foi escolhido: É um algoritmo simples, direto e muito eficiente para conjuntos de dados pequenos ou quase ordenados (como um catálogo inicial de produtos).

3. Gerenciamento de Memória Dinâmica

Como o número de produtos cadastrados, itens no carrinho e clientes na fila muda durante o uso do programa, todas as estruturas foram implementadas com alocação dinâmica:

Alocação (new): Sempre que um novo produto é inserido na árvore, um item é colocado no carrinho, um cliente entra na fila ou um vetor temporário de ordenação é criado, a memória é reservada sob demanda com o operador new.

Liberação (delete e nullptr): Para evitar vazamento de memória (memory leak), todo new possui um delete correspondente. Os nós são liberados individualmente quando um item é removido do carrinho ou um cliente é atendido no caixa, e todas as estruturas completas são limpas ao encerrar o programa (liberarArvore, liberarCarrinho e liberarFila), atribuindo nullptr aos ponteiros liberados.