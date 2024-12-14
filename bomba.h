#ifndef bomba_h
#define bomba_h

#define hack '$'

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int bombs;      // número de bombas ao redor
    int boolean;    // booleana = 0 -> não é bomba, booleana = 1 -> é bomba
    int flag;       // 0 -> não marcada, 1 -> aberta, -1 -> marcada com bandeira
} casa;

void gerar_bombas(int max, casa matrix[max][max], int num_bombas);
void contador_bombs(int MAX, casa matrix[MAX][MAX]);

void printa_ou_n(int MAX, casa matrix[MAX][MAX], int pi, int pj);
void printarMatriz(int MAX, casa matrix[MAX][MAX]);
int vitoria(int MAX, casa matrix[MAX][MAX], int num_bombas);

#endif