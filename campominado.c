#include <stdio.h>
#include "bomba.h"

int main() {
    char jogardnv[4] = "Sim";

    printf("\n\tBEM VINDO AO JOGO CAMPO MINADO\n");
    printf("Escolha uma coordenada para abrir colocando a letra maiuscula seguida do numero, por exemplo A1.\n");
    printf("Caso queira marcar uma coordenada onde voce acha que tem uma bomba, marque essa coordenada colocando a letra minuscula seguida do numero da coluna, por exemplo b5.\n\n");

    while (jogardnv[0] == 'S' || jogardnv[0] == 's') {

        printf("Escolha o nivel de dificuldade:\n");
        printf("1 - Facil  -> 100 casas e 10 bombas\n");
        printf("2 - Intermediario  -> 225 casas e 35 bombas\n");
        printf("3 - Dificil  -> 400 casas e 90 bombas\n");

        int escolha;
        scanf("%d", &escolha);

        int MAX, num_bombas;

        switch (escolha) {
            case 1:
                MAX = 10;
                num_bombas = 10;
                break;
            case 2:
                MAX = 15;
                num_bombas = 35;
                break;
            case 3:
                MAX = 20;
                num_bombas = 90;
                break;
            default:
                printf("??? Escolha uma opção valida!\n");
                continue;
        }

        casa matriz[MAX][MAX];
        srand(time(NULL));

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                matriz[i][j].flag = 0;
                matriz[i][j].bombs = 0;
                matriz[i][j].boolean = 0;
            }   
        }

        gerar_bombas(MAX, matriz, num_bombas);
        contador_bombs(MAX, matriz);

        printarMatriz(MAX, matriz);

        char letra;
        int coluna, linha;

        while (scanf(" %c", &letra) != EOF) {
            scanf("%d", &coluna);

            if (letra == hack) {
                printf("\n");
                for (int i = 0; i < MAX; i++) {
                    for (int j = 0; j < MAX; j++) {
                        if (matriz[i][j].boolean == 1) {
                            printf("%c%d  ", 'A' + i, j + 1);
                        }
                    }
                }
                letra = 'A' + MAX;
                printf("\n\n");  
            }

            if (coluna > 0 && coluna <= MAX) {
                linha = letra - 'A';
                coluna--;

                if (letra >= 'A' && letra <= 'A' + MAX - 1) {
                    if (matriz[linha][coluna].boolean == 0) {
                        if (matriz[linha][coluna].bombs == 0) {
                            printa_ou_n(MAX, matriz, linha, coluna);
                        }
                        else {
                            matriz[linha][coluna].flag = 1;
                        }
                    }
                    else   // ACHOU BOMBA
                        {
                        //matriz[linha][coluna].flag = 1;
                        printf("   "); 
                        for (int i = 1; i <= MAX; i++) //printar o numero das colunas
                        {
                            printf("%02d ", i );
                        }
                        printf("\n");
                        
                        for (int l = 0; l < MAX; l++)
                        {
                            printf("%c ", 'A' + l); //printar as letras da coluna ao lado
                            for (int c = 0; c < MAX; c++)
                            {
                                if(matriz[l][c].boolean == 1){
                                    printf(" 💥");
                                }
                                else if(matriz[l][c].bombs != 0){
                                    printf(" %d ", matriz[l][c].bombs);
                                }
                                else{
                                    printf(" □ ");
                            
                                }
                            }
                            printf("\n");
                        }  
                
                        printf("      ,--.!,\n");
                        printf("   __/   -*-\n");
                        printf(" ,d08b.  '|` \n");
                        printf(" 0088MM       PERDEU OTARIOKKKKKKKKKKKKKKKKKK explodiu foi tudo\n");
                        printf(" `9MMP'      \n");
                        break;
                    }
                }
                else if (letra >= 'a' && letra <= 'a' + MAX - 1) { // BANDEIRA
                    linha = letra - 'a';
                    if (matriz[linha][coluna].flag == -1) {
                        matriz[linha][coluna].flag = 0;
                    }
                    else if (matriz[linha][coluna].flag != 1) {
                        matriz[linha][coluna].flag = -1;
                    }
                }
            }
            else {
                printf("\n???? Escolha uma coordenada valida!\n");
            }
            printarMatriz(MAX, matriz);

            if (vitoria(MAX, matriz, num_bombas)) {
                printf(" GENIO DEMAIS! VOCE VENCEU!!\n ");
                break;
            }
        }
        printf("\nDeseja jogar mais uma vez?: ");     
        scanf("%s", jogardnv);  
    }
    return 0;
}
