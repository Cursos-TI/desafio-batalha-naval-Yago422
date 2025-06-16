#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>  // Inclusão necessária para a função abs()

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para verificar se uma posição está dentro do tabuleiro
bool dentro_do_tabuleiro(int linha, int coluna) {
    return linha >= 0 && linha < TAM_TABULEIRO && 
           coluna >= 0 && coluna < TAM_TABULEIRO;
}

// Função para criar matriz de habilidade em Cone
void criar_cone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Cone: forma triangular apontando para baixo
            if (j >= (TAM_HABILIDADE/2 - i/2) && j <= (TAM_HABILIDADE/2 + i/2) && i <= TAM_HABILIDADE/2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade em Cruz
void criar_cruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Cruz: linha central + coluna central
            if (i == TAM_HABILIDADE/2 || j == TAM_HABILIDADE/2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade em Octaedro
void criar_octaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Octaedro: formato de losango (usando abs() para calcular distâncias)
            int distancia = abs(i - TAM_HABILIDADE/2) + abs(j - TAM_HABILIDADE/2);
            if (distancia <= TAM_HABILIDADE/2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para aplicar habilidade ao tabuleiro
void aplicar_habilidade(int tabuleiro[][TAM_TABULEIRO], int habilidade[][TAM_HABILIDADE], 
                        int centro_linha, int centro_coluna) {
    int offset = TAM_HABILIDADE / 2;
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha = centro_linha - offset + i;
            int coluna = centro_coluna - offset + j;
            
            if (dentro_do_tabuleiro(linha, coluna) && habilidade[i][j] == 1) {
                tabuleiro[linha][coluna] = HABILIDADE;
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[][TAM_TABULEIRO]) {
    printf("\nTabuleiro com Habilidades Especiais:\n\n");
    printf("   ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Inicializa o tabuleiro com água
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    
    // Posiciona alguns navios para demonstração
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][7] = NAVIO;
    tabuleiro[7][7] = NAVIO;
    tabuleiro[4][2] = NAVIO;
    tabuleiro[5][2] = NAVIO;
    tabuleiro[6][2] = NAVIO;
    
    // Cria as matrizes de habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    
    criar_cone(cone);
    criar_cruz(cruz);
    criar_octaedro(octaedro);
    
    // Aplica as habilidades ao tabuleiro
    aplicar_habilidade(tabuleiro, cone, 3, 4);      // Cone centrado em (3,4)
    aplicar_habilidade(tabuleiro, cruz, 6, 5);      // Cruz centrada em (6,5)
    aplicar_habilidade(tabuleiro, octaedro, 5, 2);  // Octaedro centrado em (5,2)
    
    // Exibe o tabuleiro final
    exibir_tabuleiro(tabuleiro);
    
    printf("\nLegenda:\n");
    printf(" 0 - Agua\n");
    printf(" 3 - Navio\n");
    printf(" 5 - Area de efeito da habilidade\n");
    
    return 0;
}
