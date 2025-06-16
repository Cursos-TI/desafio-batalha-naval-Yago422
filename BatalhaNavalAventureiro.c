#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para verificar se uma posição está dentro do tabuleiro
bool dentro_do_tabuleiro(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO_TABULEIRO && 
           coluna >= 0 && coluna < TAMANHO_TABULEIRO;
}

// Função para verificar se há sobreposição de navios
bool pode_posicionar(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna) {
    return dentro_do_tabuleiro(linha, coluna) && tabuleiro[linha][coluna] == AGUA;
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Define as coordenadas iniciais dos navios
    // Navio horizontal (linha fixa)
    int h_linha = 2, h_coluna = 3;
    
    // Navio vertical (coluna fixa)
    int v_linha = 5, v_coluna = 7;
    
    // Navio diagonal principal (linha = coluna)
    int d1_linha = 1, d1_coluna = 1;
    
    // Navio diagonal secundária (linha + coluna = constante)
    int d2_linha = 6, d2_coluna = 2;

    // Valida posicionamento do navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!pode_posicionar(tabuleiro, h_linha, h_coluna + i)) {
            printf("Erro: Navio horizontal fora do tabuleiro ou sobreposto!\n");
            return 1;
        }
    }

    // Valida posicionamento do navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!pode_posicionar(tabuleiro, v_linha + i, v_coluna)) {
            printf("Erro: Navio vertical fora do tabuleiro ou sobreposto!\n");
            return 1;
        }
    }

    // Valida posicionamento do navio diagonal principal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!pode_posicionar(tabuleiro, d1_linha + i, d1_coluna + i)) {
            printf("Erro: Navio diagonal 1 fora do tabuleiro ou sobreposto!\n");
            return 1;
        }
    }

    // Valida posicionamento do navio diagonal secundário
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!pode_posicionar(tabuleiro, d2_linha + i, d2_coluna - i)) {
            printf("Erro: Navio diagonal 2 fora do tabuleiro ou sobreposto!\n");
            return 1;
        }
    }

    // Posiciona os navios no tabuleiro
    // Navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[h_linha][h_coluna + i] = NAVIO;
    }

    // Navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[v_linha + i][v_coluna] = NAVIO;
    }

    // Navio diagonal principal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[d1_linha + i][d1_coluna + i] = NAVIO;
    }

    // Navio diagonal secundário
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[d2_linha + i][d2_coluna - i] = NAVIO;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval com Navios Diagonais\n\n");
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
