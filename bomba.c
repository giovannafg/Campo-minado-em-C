#include "bomba.h"

void gerar_bombas(int max, casa matrix[max][max], int num_bombas) {
    int bombas_colocadas = 0;
    while (bombas_colocadas < num_bombas) {
        int i = rand() % max;
        int j = rand() % max;
        if (matrix[i][j].boolean == 0) {
            matrix[i][j].boolean = 1;
            bombas_colocadas++;
        }
    }
}

void contador_bombs(int MAX, casa matrix[MAX][MAX]) {
    for (int pi = 0; pi < MAX; pi++) {
        for (int pj = 0; pj < MAX; pj++) {
            matrix[pi][pj].bombs = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (pi + i >= 0 && pi + i < MAX && pj + j >= 0 && pj + j < MAX) {
                        if (matrix[pi + i][pj + j].boolean == 1) {
                            matrix[pi][pj].bombs++;
                        }
                    }
                }
            }
        }
    }
}

void printa_ou_n(int MAX, casa matrix[MAX][MAX], int pi, int pj){
    if (matrix[pi][pj].flag != 0) {
        return;
    }
    matrix[pi][pj].flag = 1;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (pi + i >= 0 && pi + i < MAX && pj + j >= 0 && pj + j < MAX) {
                if (matrix[pi + i][pj + j].bombs == 0) {                
                    printa_ou_n(MAX, matrix, pi + i, pj + j);
                }
                else {
                    matrix[pi + i][pj + j].flag = 1;
                }
            }
        }
    }
}

void printarMatriz(int MAX, casa matrix[MAX][MAX]){
    printf("  "); 
    for (int i = 1; i <= MAX; i++) {
        printf("%02d ", i );
    }
    printf("\n");

    for (int l = 0; l < MAX; l++) {
        printf("%c ", 'A' + l);
        for (int c = 0; c < MAX; c++) {
            if (matrix[l][c].flag == 1) {
                if (matrix[l][c].bombs != 0) {
                    printf(" %d ", matrix[l][c].bombs);
                }
                else {
                    printf(" □ ");
                }
            }
            else if (matrix[l][c].flag == 0) {
                printf(" ■ ");
            }
            else if (matrix[l][c].flag == -1) {
                printf(" 🚩");
            }
        }
        printf("\n");
    }
}

int vitoria(int MAX, casa matrix[MAX][MAX], int num_bombas){
    int casas_abertas = 0;
    int bandeira_certa = 0;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (matrix[i][j].flag == 1) {
                casas_abertas++;
            }
            if (matrix[i][j].flag == -1 && matrix[i][j].boolean == 1) {
                bandeira_certa++;
            }
        }
    }

    if (casas_abertas == MAX * MAX - num_bombas || bandeira_certa == num_bombas) {
        return 1;
    }
    return 0;
}