#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 1

// Nível Novato - Posicionamento dos Navios
// Representação do tabuleiro 10x10 com inicialização de todas as posições como água.
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Validação do posicionamento dos navios dentro dos limites e sem sobreposição.
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

// Posicionamento de navios, garantindo que estão dentro dos limites e não sobrepostos.
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

// Nível Aventureiro - Posicionamento Diagonal de Navios
void posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao) {
    if (direcao == 1) { // Direção diagonal para baixo-direita
        if (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha + i][coluna + i] = NAVIO;
            }
        }
    } else if (direcao == -1) { // Direção diagonal para cima-direita
        if (linha - TAMANHO_NAVIO >= 0 && coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha - i][coluna + i] = NAVIO;
            }
        }
    }
}

// Nível Mestre - Habilidades Especiais
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char tipo) {
    if (tipo == 'C') { // Habilidade em cruz
        if (linha > 0) tabuleiro[linha - 1][coluna] = HABILIDADE;
        if (linha < TAMANHO_TABULEIRO - 1) tabuleiro[linha + 1][coluna] = HABILIDADE;
        if (coluna > 0) tabuleiro[linha][coluna - 1] = HABILIDADE;
        if (coluna < TAMANHO_TABULEIRO - 1) tabuleiro[linha][coluna + 1] = HABILIDADE;
        tabuleiro[linha][coluna] = HABILIDADE;
    } else if (tipo == 'O') { // Habilidade em octaedro
        if (linha > 1) tabuleiro[linha - 2][coluna] = HABILIDADE;
        if (linha < TAMANHO_TABULEIRO - 2) tabuleiro[linha + 2][coluna] = HABILIDADE;
        if (coluna > 1) tabuleiro[linha][coluna - 2] = HABILIDADE;
        if (coluna < TAMANHO_TABULEIRO - 2) tabuleiro[linha][coluna + 2] = HABILIDADE;
        tabuleiro[linha][coluna] = HABILIDADE;
    }
}

// Exibir o tabuleiro no console
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Nível Novato: Posicionamento inicial de navios
    posicionarNavio(tabuleiro, 2, 3, 'H');
    posicionarNavio(tabuleiro, 5, 6, 'V');

    // Nível Aventureiro: Posicionamento diagonal de navios
    posicionarNavioDiagonal(tabuleiro, 1, 1, 1);
    posicionarNavioDiagonal(tabuleiro, 8, 2, -1);

    // Nível Mestre: Aplicar habilidades especiais
    aplicarHabilidade(tabuleiro, 4, 4, 'C');
    aplicarHabilidade(tabuleiro, 7, 7, 'O');

    imprimirTabuleiro(tabuleiro);

    return 0;
}
