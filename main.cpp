#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// BLOCO 1: CATALOGO DE PRODUTOS & ARVORE BINARIA DE BUSCA
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
        cout << "Preco: R$ " << fixed << setprecision(2) << raiz->preco << endl;
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
// BLOCO 2: CARRINHO DE COMPRAS & PILHA (LIFO)
// ============================================================================










// ============================================================================
// BLOCO 3: CAIXA, FILA & PAGAMENTO (FIFO)
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
// BLOCO 4: ORDENACAO, BUSCAS E MENU PRINCIPAL
// ============================================================================