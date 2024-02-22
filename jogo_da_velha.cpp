#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char matriz[3][3];

/* preenche a matriz com espaços*/
void init_matriz(void) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) matriz[i][j] = ' ';
}

/* verifica se houve um empate */
bool verificar_empate(void) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (matriz[i][j] == ' ')
                return false;
    return true;
}

/* mostra a matriz na tela */
void show_matriz(void) {
    int t;
    for (t = 0; t < 3; t++) {
        printf("  %c | %c | %c ", matriz[t][0], matriz[t][1], matriz[t][2]);
        if (t != 2) printf("\n ---|---|---\n");
    }
    printf("\n");
}

/* verifica se um jogador ganhou */
bool verificar_vitoria(char jogador) {
    for (int i = 0; i < 3; i++) {
        if (matriz[i][0] == jogador && matriz[i][1] == jogador && matriz[i][2] == jogador) return true;
        if (matriz[0][i] == jogador && matriz[1][i] == jogador && matriz[2][i] == jogador) return true;
    }
    if (matriz[0][0] == jogador && matriz[1][1] == jogador && matriz[2][2] == jogador) return true;
    if (matriz[0][2] == jogador && matriz[1][1] == jogador && matriz[2][0] == jogador) return true;
    return false;
}

/* recebe a jogada do player */
void get_player_move(void) {
    int x, y;
    printf("digite as coordenadas para o x:\n");
    scanf("%d%d", &x, &y);

    x--;
    y--;

    if (x < 0 || x >= 3 || y < 0 || y >= 3 || matriz[x][y] != ' ') {
        printf("Posição inválida, tente novamente\n");
        get_player_move();
    } else {
        matriz[x][y] = 'X';
    }
}

/* recebe a jogada do computador */
void get_computer_move(void) {
    int x, y;

    // Lógica simples para o computador: joga aleatoriamente em uma posição vazia
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (matriz[x][y] != ' ');

    matriz[x][y] = 'O';
}

int main() {
    init_matriz();
    while (true) {
        show_matriz();
        get_player_move();
        if (verificar_vitoria('X')) {
            printf("Você ganhou!\n");
            break;
        }
        if (verificar_empate()) {
            printf("Empate!\n");
            break;
        }
        get_computer_move();
        if (verificar_vitoria('O')) {
            printf("O computador ganhou!\n");
            break;
        }
        if (verificar_empate()) {
            printf("Empate!\n");
            break;
        }
    }
    return 0;
}
