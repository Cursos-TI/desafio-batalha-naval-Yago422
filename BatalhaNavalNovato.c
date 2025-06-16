#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Define as coordenadas iniciais dos navios
    int navio_horizontal_linha = 2;
    int navio_horizontal_coluna = 3;
    int navio_vertical_linha = 5;
    int navio_vertical_coluna = 7;

    // Valida se os navios estão dentro dos limites do tabuleiro
    if (navio_horizontal_coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        navio_vertical_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navios fora dos limites do tabuleiro!\n");
        return 1;
    }

    // Valida se os navios não se sobrepõem
    if (navio_horizontal_linha >= navio_vertical_linha - 1 &&
        navio_horizontal_linha <= navio_vertical_linha + TAMANHO_NAVIO &&
        navio_vertical_coluna >= navio_horizontal_coluna - 1 &&
        navio_vertical_coluna <= navio_horizontal_coluna + TAMANHO_NAVIO) {
        printf("Erro: Navios se sobrepoem!\n");
        return 1;
    }

    // Posiciona o navio horizontal (linha fixa, coluna varia)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio_horizontal_linha][navio_horizontal_coluna + i] = NAVIO;
    }

    // Posiciona o navio vertical (coluna fixa, linha varia)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio_vertical_linha + i][navio_vertical_coluna] = NAVIO;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval - Navios Posicionados\n\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n"); // Cabeçalho das colunas
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
