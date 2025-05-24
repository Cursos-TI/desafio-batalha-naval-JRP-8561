#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Inicializa o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Verifica se o navio pode ser posicionado sem ultrapassar os limites ou sobrepor outro
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcaoLinha, int direcaoColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int novaLinha = linha + i * direcaoLinha;
        int novaColuna = coluna + i * direcaoColuna;

        if (novaLinha < 0 || novaLinha >= TAMANHO_TABULEIRO || novaColuna < 0 || novaColuna >= TAMANHO_TABULEIRO)
            return 0; // Está fora do tabuleiro

        if (tabuleiro[novaLinha][novaColuna] == NAVIO)
            return 0; // Está sobreposto a outro navio
    }
    return 1;
}

// Posiciona um navio no tabuleiro (horizontal, vertical ou diagonal)
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcaoLinha, int direcaoColuna) {
    if (podePosicionarNavio(tabuleiro, linha, coluna, direcaoLinha, direcaoColuna)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i * direcaoLinha][coluna + i * direcaoColuna] = NAVIO;
        }
    } else {
        printf("Erro: O navio não pode ser posicionado em (%d, %d).\n", linha, coluna);
    }
}

// Exibe o tabuleiro com alinhamento visual melhorado
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) {
                printf("~  ");
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("N  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Posicionamento dos navios horizontais, verticais e diagonais
    posicionarNavio(tabuleiro, 2, 3, 0, 1);  // Horizontal
    posicionarNavio(tabuleiro, 5, 6, 1, 0);  // Vertical
    posicionarNavio(tabuleiro, 1, 1, 1, 1);  // Diagonal (baixo-direita)
    posicionarNavio(tabuleiro, 8, 2, -1, 1); // Diagonal (cima-direita)

    imprimirTabuleiro(tabuleiro);

    return 0;
}