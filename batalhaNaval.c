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

// Verifica se é possível posicionar um navio sem sobreposição e dentro dos limites
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] == NAVIO) return 0;
        }
    } else if (orientacao == 'V') {
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] == NAVIO) return 0;
        }
    }
    return 1;
}

// Posiciona um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (podePosicionarNavio(tabuleiro, linha, coluna, orientacao)) {
        if (orientacao == 'H') {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha][coluna + i] = NAVIO;
            }
        } else if (orientacao == 'V') {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha + i][coluna] = NAVIO;
            }
        }
    } else {
        printf("Erro: O navio não pode ser posicionado em (%d, %d) com orientação '%c'.\n", linha, coluna, orientacao);
    }
}

// Posiciona navios diagonalmente
void posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao) {
    if (direcao == 1) { // Diagonal para baixo-direita
        if (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha + i][coluna + i] = NAVIO;
            }
        }
    } else if (direcao == -1) { // Diagonal para cima-direita
        if (linha - TAMANHO_NAVIO >= 0 && coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha - i][coluna + i] = NAVIO;
            }
        }
    }
}

// Exibe o tabuleiro de forma organizada
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) {
                printf("~ ");
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("N ");
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Posicionamento dos navios horizontais/verticais
    posicionarNavio(tabuleiro, 2, 3, 'H');
    posicionarNavio(tabuleiro, 5, 6, 'V');

    // Posicionamento dos navios diagonais
    posicionarNavioDiagonal(tabuleiro, 1, 1, 1);
    posicionarNavioDiagonal(tabuleiro, 8, 2, -1);

    imprimirTabuleiro(tabuleiro);

    return 0;
}