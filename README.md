#include "tela.h"
#include "tecla.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Função para aparecer uma mensagem na tela inicial
void telainicial() {
    tela_limpa();
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║  ____  ___   ____  ___       ___    ____      __ __   ___ _     __ __  ____ ║\n");
    printf("║ |    |/   \\ /    |/   \\     |   \\  /    |    |  |  | /  _] |   |  |  |/    |║\n");
    printf("║ |__  |     |   __|     |    |    \\|  o  |    |  |  |/  [_| |   |  |  |  o  |║\n");
    printf("║ __|  |  O  |  |  |  O  |    |  D  |     |    |  |  |    _] |___|  _  |     |║\n");
    printf("║/  |  |     |  |_ |     |    |     |  _  |    |  :  |   [_|     |  |  |  _  |║\n");
    printf("║\\  `  |     |     |     |    |     |  |  |     \\   /|     |     |  |  |  |  |║\n");
    printf("║ \\____j\\___/|___,_|\\___/     |_____|__|__|      \\_/ |_____|_____|__|__|__|__|║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Pressione enter para continuar...");
    getchar();
}

// Função para fazer o tabuleiro aparecer na tela
void imprime_tabuleiro(char tabuleiro[3][3]) {
    tela_limpa();
    printf("    1   2   3\n");
    printf("  ╔═══╦═══╦═══╗\n");
    printf("1 ║ %c ║ %c ║ %c ║\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("  ╠═══╬═══╬═══╣\n");
    printf("2 ║ %c ║ %c ║ %c ║\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("  ╠═══╬═══╬═══╣\n");
    printf("3 ║ %c ║ %c ║ %c ║\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("  ╚═══╩═══╩═══╝\n");
}

// Função principal
int main() {
    char tabuleiro[3][3];
    char player;
    int i, j, linha, coluna, rodada;
    bool vencedor = false;

    // Inicialização do programa
    tela_ini();
    tecla_ini();

    // Retorna a função para mostrar a mensagem no início da execução
    telainicial();

    // Deixa o tabuleiro vazio
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }

    // Retorna a função para imprimir o tabuleiro
    imprime_tabuleiro(tabuleiro);

    vencedor = false;

    // Vai mudando o jogador entre as rodadas
    for (rodada = 1; rodada <= 9 && vencedor == false; rodada++) {
        if (rodada % 2 == 1) {
            player = 'X';
        } else {
            player = 'O';
        }
        // Mostra na tela que o jogador * deve fazer uma jogada
        do {
            printf("Digite as coordenadas (de 1 a 3) separadas por espaço para posicionar o %c: ", player);
            scanf("%d%d", &linha, &coluna);
            if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha-1][coluna-1] != ' ') {
                printf("\nJogada inválida. Tente novamente!\n");
                break;
            } else { 
                break;
            }
        } while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' ');
        
        tabuleiro[linha - 1][coluna - 1] = player;

        imprime_tabuleiro(tabuleiro);

        // Verifica se há um vencedor
        if (tabuleiro[linha-1][0] == tabuleiro[linha-1][1] && tabuleiro[linha-1][1] == tabuleiro[linha-1][2]) {
            vencedor = true;
        } else {
            // Verifica se a coluna onde jogou está toda com o mesmo marcador
            if (tabuleiro[0][coluna-1] == tabuleiro[1][coluna-1] && tabuleiro[1][coluna-1] == tabuleiro[2][coluna-1]) {
                vencedor = true;
            } else {
                // Verifica se possui algum vencedor pelas diagonais
                if (linha == coluna && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
                    vencedor = true;
                } else {
                    if (linha + coluna == 4 && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
                        vencedor = true;
                    }
                }
            }
        }
    }

    // Mostra se há um vencedor e quem ganhou
    if (vencedor == false) {
        printf("\nDeu velha!\n");
    } else {
        printf("\nJogador %c ganhou!\n", player);
    }

    // Finalização do programa
    tecla_fim();
    tela_fim();
    return 0;
}
