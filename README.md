# Simulador de Supermercado

Projeto Final da disciplina de Programação e Sistemas Computacionais II

## Tema Escolhido
Simulador de Supermercado — Sistema em terminal que simula o fluxo de compras desde o cadastro e consulta de produtos no catálogo, passando pela montagem do carrinho de compras até o atendimento na fila do caixa e fechamento da compra

## Descrição do Sistema
O programa funciona de forma interativa por meio de um menu contínuo no terminal e utiliza alocação dinâmica de memória com new e delete[cite: 3, 4]. Ao iniciar, o sistema carrega 5 produtos padrão no catálogo e permite listar, cadastrar e buscar produtos por código, adicionar itens ao carrinho com quantidade, visualizar o valor total, remover o último item adicionado, inserir clientes na fila do caixa e chamar o próximo cliente para finalizar a compra

## Estruturas de Dados Utilizadas
* Árvore Binária de Busca (NoProduto): Armazena o catálogo de produtos organizados pelo código, permitindo busca eficiente e exibição ordenada por travessia in-ordem
* Pilha (PilhaCarrinho e ItemCarrinho): Controla os itens do carrinho com semântica LIFO (o último produto colocado é o primeiro a ser retirado em caso de desistência)
* Fila (FilaCaixa e ClienteFila): Gerencia a ordem de atendimento nos caixas com semântica FIFO (atendendo os clientes na ordem em que chegaram)
* Algoritmo de Ordenação (ordenarPrecos): Implementação manual do Insertion Sort para ordenação de valores decimais

## Divisão de Responsabilidades
* Vitor Rafael (Bloco 1 - Catálogo e Árvore Binária): Implementação da struct NoProduto, inserção recursiva, busca por código, travessia in-ordem, carregamento inicial dos produtos e liberação de memória da árvore
* Carlos Beltrão (Bloco 2 - Carrinho e Pilha): Implementação das structs PilhaCarrinho e ItemCarrinho, funções de empilhar produtos, remover o último item, exibir itens, calcular o total e liberar memória do carrinho
* Kauã Santos (Bloco 3 - Caixa e Fila): Implementação das structs FilaCaixa e ClienteFila, controle de entrada na fila, visualização da ordem de espera, chamada do próximo cliente e liberação de memória da fila
* Lucas Siqueira (Bloco 4 - Ordenação, Integração e Menu): Implementação do algoritmo de ordenação Insertion Sort, estruturação do menu interativo na função main e integração das chamadas de todos os blocos
