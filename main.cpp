#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// BLOCO 1: CATALOGO DE PRODUTOS & ARVORE BINARIA DE BUSCA
// ============================================================================










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