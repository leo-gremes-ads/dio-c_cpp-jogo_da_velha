#include <stdio.h>

char tabuleiro[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char jogador = 'X';
int escolha;
int linha, coluna;
int jogada = 0;

// Função para exibir o tabuleiro
void exibirTabuleiro() {
    printf("\n");
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

// Função para fazer uma jogada
int fazerJogada() {
    printf("Jogador %c, faça sua jogada (1-9): ", jogador);
    scanf("%d", &escolha);
    
    // Calcular a linha e a coluna com base na escolha
    linha = (escolha - 1) / 3;
    coluna = (escolha - 1) % 3;

    // Verificar se a posição está disponível
    if (tabuleiro[linha][coluna] != 'X' && tabuleiro[linha][coluna] != 'O') {
        tabuleiro[linha][coluna] = jogador;
        jogada++;
        return 1;
    } else {
        printf("Posição já ocupada! Tente novamente.\n");
        return 0;
    }
}

// Função para verificar se alguém ganhou
int verificarVitoria() {
    // Verificar linhas, colunas e diagonais
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return 1;
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return 1;
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return 1;
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return 1;

    return 0;
}

// Função principal do jogo
int main() {
    printf("Jogo da Velha\n");
    printf("Jogador 1 = X | Jogador 2 = O\n");
    
    while (1) {
        exibirTabuleiro();
        if (fazerJogada() == 0) {
            continue;
        }

        if (verificarVitoria()) {
            exibirTabuleiro();
            printf("Jogador %c venceu!\n", jogador);
            break;
        }

        if (jogada == 9) {
            exibirTabuleiro();
            printf("Empate!\n");
            break;
        }

        jogador = (jogador == 'X') ? 'O' : 'X'; // Alterna entre X e O
    }

    return 0;
}
