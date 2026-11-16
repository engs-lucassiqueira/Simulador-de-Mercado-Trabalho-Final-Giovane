#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ============================================================================
// BLOCO 1: CATALOGO DE PRODUTOS & ARVORE BINARIA DE BUSCA - Vitor Rafael
// ============================================================================

struct NoProduto {
    int codigo;
    string nome;
    double preco;
    NoProduto* esquerda;
    NoProduto* direita;
};

NoProduto* inserirProduto(NoProduto* raiz, int codigo, string nome, double preco) {

    if (raiz == nullptr) {
        NoProduto* novo = new NoProduto;

        novo->codigo = codigo;
        novo->nome = nome;
        novo->preco = preco;
        novo->esquerda = nullptr;
        novo->direita = nullptr;

        return novo;
    }

    if (codigo < raiz->codigo) {
        raiz->esquerda = inserirProduto(raiz->esquerda, codigo, nome, preco);
    }
    else if (codigo > raiz->codigo) {
        raiz->direita = inserirProduto(raiz->direita, codigo, nome, preco);
    }
    else {
        cout << "Codigo ja cadastrado!" << endl;
    }

    return raiz;
}

void exibirCatalogo(NoProduto* raiz) {

    if (raiz != nullptr) {

        exibirCatalogo(raiz->esquerda);

        cout << "Codigo: " << raiz->codigo << endl;
        cout << "Nome: " << raiz->nome << endl;
        cout << "Preco: R$ " << raiz->preco << endl;
        cout << "------------------------" << endl;

        exibirCatalogo(raiz->direita);
    }
}

NoProduto* buscarProduto(NoProduto* raiz, int codigo) {

    if (raiz == nullptr) {
        return nullptr;
    }

    if (codigo == raiz->codigo) {
        return raiz;
    }

    if (codigo < raiz->codigo) {
        return buscarProduto(raiz->esquerda, codigo);
    }

    return buscarProduto(raiz->direita, codigo);
}

NoProduto* carregarCatalogoInicial(NoProduto* raiz) {

    raiz = inserirProduto(raiz, 101, "Arroz", 25.90);
    raiz = inserirProduto(raiz, 102, "Feijao", 8.50);
    raiz = inserirProduto(raiz, 103, "Macarrao", 5.99);
    raiz = inserirProduto(raiz, 104, "Leite", 4.80);
    raiz = inserirProduto(raiz, 105, "Cafe", 16.90);

    return raiz;
}

void liberarArvore(NoProduto* raiz) {

    if (raiz != nullptr) {

        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);

        delete raiz;
    }
}

// ============================================================================
// BLOCO 2: CARRINHO DE COMPRAS & PILHA (LIFO) - Carlos Beltrão
// ============================================================================

struct ItemCarrinho {
    int codigo;
    string nome;
    double preco;
    int quantidade;
    ItemCarrinho* proximo;
};

struct PilhaCarrinho {
    ItemCarrinho* topo = nullptr;
};

void adicionarCarrinho(PilhaCarrinho& carrinho, NoProduto* catalogo, int codigo, int quantidade) {

    NoProduto* produto = buscarProduto(catalogo, codigo);

    if (produto == nullptr) {
        cout << "Produto nao encontrado no catalogo!" << endl;
        return;
    }

    if (quantidade <= 0) {
        cout << "Quantidade invalida!" << endl;
        return;
    }

    ItemCarrinho* novo = new ItemCarrinho;

    novo->codigo = produto->codigo;
    novo->nome = produto->nome;
    novo->preco = produto->preco;
    novo->quantidade = quantidade;

    novo->proximo = carrinho.topo;
    carrinho.topo = novo;

    cout << produto->nome << " adicionado ao carrinho!" << endl;
}

void exibirCarrinho(PilhaCarrinho& carrinho) {

    if (carrinho.topo == nullptr) {
        cout << "Carrinho vazio!" << endl;
        return;
    }

    ItemCarrinho* atual = carrinho.topo;
    double total = 0;

    cout << "\n--- CARRINHO DE COMPRAS ---" << endl;

    while (atual != nullptr) {

        double subtotal = atual->preco * atual->quantidade;

        cout << "Produto: " << atual->nome << endl;
        cout << "Codigo: " << atual->codigo << endl;
        cout << "Quantidade: " << atual->quantidade << endl;
        cout << "Preco unitario: R$ " << atual->preco << endl;
        cout << "Subtotal: R$ " << subtotal << endl;
        cout << "------------------------" << endl;

        total += subtotal;
        atual = atual->proximo;
    }

    cout << "TOTAL: R$ " << total << endl;
}

void removerCarrinho(PilhaCarrinho& carrinho) {

    if (carrinho.topo == nullptr) {
        cout << "Carrinho vazio! Nao ha produtos para remover." << endl;
        return;
    }

    ItemCarrinho* removido = carrinho.topo;

    cout << "Produto removido: " << removido->nome << endl;

    carrinho.topo = removido->proximo;

    delete removido;
}

double calcularTotal(PilhaCarrinho& carrinho) {

    double total = 0;
    ItemCarrinho* atual = carrinho.topo;

    while (atual != nullptr) {
        total += atual->preco * atual->quantidade;
        atual = atual->proximo;
    }

    return total;
}

void liberarCarrinho(PilhaCarrinho& carrinho) {

    while (carrinho.topo != nullptr) {
        ItemCarrinho* temp = carrinho.topo;
        carrinho.topo = carrinho.topo->proximo;
        delete temp;
    }
}


// ============================================================================
// BLOCO 3: CAIXA, FILA & PAGAMENTO (FIFO) - Kauã Santos
// ============================================================================
struct ClienteFila {
    std::string nome;
    ClienteFila* proximo;
};

struct FilaCaixa {
    ClienteFila* inicio = nullptr;
    ClienteFila* fim = nullptr;
};

inline void entrarFila(FilaCaixa& fila, const std::string& nome) {
    ClienteFila* novo = new ClienteFila{nome, nullptr};

    if (fila.fim == nullptr) {
        fila.inicio = novo;
        fila.fim = novo;
    } else {
        fila.fim->proximo = novo;
        fila.fim = novo;
    }

    std::cout << "Cliente " << nome
              << " entrou na fila!\n";
}

inline void exibirFila(const FilaCaixa& fila) {
    if (fila.inicio == nullptr) {
        std::cout << "A fila esta vazia!\n";
        return;
    }

    const ClienteFila* atual = fila.inicio;
    int posicao = 1;

    std::cout << "\n--- FILA DO CAIXA ---\n";

    while (atual != nullptr) {
        std::cout << posicao << " - "
                  << atual->nome << "\n";

        atual = atual->proximo;
        posicao++;
    }
}

inline void chamarProximo(FilaCaixa& fila) {
    if (fila.inicio == nullptr) {
        std::cout << "Nao ha clientes na fila!\n";
        return;
    }

    ClienteFila* atendido = fila.inicio;

    std::cout << "Atendendo cliente: "
              << atendido->nome << "\n";

    fila.inicio = atendido->proximo;

    if (fila.inicio == nullptr) {
        fila.fim = nullptr;
    }

    delete atendido;
}

inline void liberarFila(FilaCaixa& fila) {
    while (fila.inicio != nullptr) {
        ClienteFila* temp = fila.inicio;
        fila.inicio = fila.inicio->proximo;
        delete temp;
    }

    fila.fim = nullptr;
}

// ============================================================================
// BLOCO 4: ORDENACAO, BUSCAS E MENU PRINCIPAL - Lucas Siqueira
// ============================================================================

void ordenarPrecos(double precos[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        double chave = precos[i];
        int j = i - 1;
        while (j >= 0 && precos[j] > chave) {
            precos[j + 1] = precos[j];
            j--;
        }
        precos[j + 1] = chave;
    }
}

int main() {
    NoProduto* catalogo = nullptr;
    PilhaCarrinho carrinho;
    FilaCaixa fila;

    catalogo = carregarCatalogoInicial(catalogo);

    int opcao;
    do {
        cout << "\n========================================\n";
        cout << "       SIMULADOR DE SUPERMERCADO        \n";
        cout << "========================================\n";
        cout << "1. Exibir Catalogo de Produtos\n";
        cout << "2. Cadastrar Novo Produto\n";
        cout << "3. Buscar Produto por Codigo\n";
        cout << "4. Adicionar Produto ao Carrinho\n";
        cout << "5. Exibir Carrinho e Total\n";
        cout << "6. Remover Ultimo Item do Carrinho\n";
        cout << "7. Entrar na Fila do Caixa\n";
        cout << "8. Exibir Fila do Caixa\n";
        cout << "9. Chamar Proximo Cliente no Caixa\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        
        if (!(cin >> opcao)) break;
        cout << "----------------------------------------\n";

        switch (opcao) {
            case 1:
                exibirCatalogo(catalogo);
                break;

            case 2: {
                int cod;
                string nome;
                double preco;
                cout << "Codigo: ";
                cin >> cod;
                cout << "Nome (sem espacos): ";
                cin >> nome;
                cout << "Preco: ";
                cin >> preco;
                catalogo = inserirProduto(catalogo, cod, nome, preco);
                break;
            }

            case 3: {
                int codBusca;
                cout << "Codigo do produto: ";
                cin >> codBusca;
                NoProduto* encontrado = buscarProduto(catalogo, codBusca);
                if (encontrado != nullptr) {
                    cout << "Produto encontrado: " << encontrado->nome 
                         << " | Preco: R$ " << encontrado->preco << endl;
                } else {
                    cout << "Produto nao encontrado!\n";
                }
                break;
            }

            case 4: {
                int cod, qtd;
                cout << "Codigo do produto: ";
                cin >> cod;
                cout << "Quantidade: ";
                cin >> qtd;
                adicionarCarrinho(carrinho, catalogo, cod, qtd);
                break;
            }

            case 5:
                exibirCarrinho(carrinho);
                break;

            case 6:
                removerCarrinho(carrinho);
                break;

            case 7: {
                string nomeCliente;
                cout << "Nome do cliente: ";
                cin >> nomeCliente;
                entrarFila(fila, nomeCliente);
                break;
            }

            case 8:
                exibirFila(fila);
                break;

            case 9: {
                double total = calcularTotal(carrinho);
                chamarProximo(fila);
                if (total > 0) {
                    cout << "Total da compra finalizada: R$ " << total << endl;
                    liberarCarrinho(carrinho);
                }
                break;
            }

            case 0:
                cout << "Encerrando o sistema...\n";
                liberarArvore(catalogo);
                liberarCarrinho(carrinho);
                liberarFila(fila);
                break;

            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}