#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE_CONE 5
#define HABILIDADE_CRUZ 6
#define HABILIDADE_OCTAEDRO 7

// Inicializa o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Posiciona um navio no tabuleiro (horizontal, vertical ou diagonal)
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcaoLinha, int direcaoColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int novaLinha = linha + i * direcaoLinha;
        int novaColuna = coluna + i * direcaoColuna;

        if (novaLinha >= 0 && novaLinha < TAMANHO_TABULEIRO && novaColuna >= 0 && novaColuna < TAMANHO_TABULEIRO) {
            tabuleiro[novaLinha][novaColuna] = NAVIO;
        }
    }
}

// Aplica uma habilidade específica ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char tipo) {
    if (tipo == 'C') { // Habilidade em Cruz
        for (int i = -2; i <= 2; i++) {
            int x = linha + i;
            int y = coluna;
            if (x >= 0 && x < TAMANHO_TABULEIRO) tabuleiro[x][y] = HABILIDADE_CRUZ;
        }
        for (int j = -2; j <= 2; j++) {
            int x = linha;
            int y = coluna + j;
            if (y >= 0 && y < TAMANHO_TABULEIRO) tabuleiro[x][y] = HABILIDADE_CRUZ;
        }
    } else if (tipo == 'O') { // Habilidade em Octaedro
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                int x = linha + i;
                int y = coluna + j;
                if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO && abs(i) + abs(j) <= 2) {
                    tabuleiro[x][y] = HABILIDADE_OCTAEDRO;
                }
            }
        }
    } else if (tipo == 'N') { // Habilidade em Cone
        for (int i = 0; i < 3; i++) {
            for (int j = -i; j <= i; j++) {
                int x = linha + i;
                int y = coluna + j;
                if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                    tabuleiro[x][y] = HABILIDADE_CONE;
                }
            }
        }
    }
}

// Exibe o tabuleiro no console
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], const char *titulo) {
    printf("\n%s\n\n", titulo);
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) {
                printf("~ ");
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("N ");
            } else if (tabuleiro[i][j] == HABILIDADE_CONE) {
                printf("^ ");
            } else if (tabuleiro[i][j] == HABILIDADE_CRUZ) {
                printf("+ ");
            } else if (tabuleiro[i][j] == HABILIDADE_OCTAEDRO) {
                printf("O ");
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Exibição do tabuleiro apenas com água
    inicializarTabuleiro(tabuleiro);
    imprimirTabuleiro(tabuleiro, "Tabuleiro Inicial (Apenas Água)");

    // Exibição do tabuleiro com navios posicionados
    posicionarNavio(tabuleiro, 2, 3, 0, 1);  // Horizontal
    posicionarNavio(tabuleiro, 5, 6, 1, 0);  // Vertical
    posicionarNavio(tabuleiro, 1, 1, 1, 1);  // Diagonal (baixo-direita)
    posicionarNavio(tabuleiro, 8, 2, -1, 1); // Diagonal (cima-direita)
    imprimirTabuleiro(tabuleiro, "Tabuleiro com Navios");

    // Exibição do tabuleiro com habilidades aplicadas
    aplicarHabilidade(tabuleiro, 4, 4, 'C'); // Cruz
    aplicarHabilidade(tabuleiro, 6, 6, 'O'); // Octaedro
    aplicarHabilidade(tabuleiro, 8, 8, 'N'); // Cone
    imprimirTabuleiro(tabuleiro, "Tabuleiro com Habilidades");

    return 0;
}