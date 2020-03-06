//
// Created by benjamin on 28.02.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include "play.h"

#define MAX_LINE 10
#define MAX_ROW 10

/**
 * deroulement de la partie(jeu)
 */
void jeu() {

    char x;
    int board[MAX_LINE][MAX_ROW];
    int y, bateaux = 1, lineNumber, convertedX;

    //definit la valeur par defaut du tableau a 0
    memset(board, 0, sizeof(board));

    do {
        lineNumber = 1;
        //affiche la premiere ligne de la grille
        printf("\n");
        printf("     A   B   C   D   E   F   G   H   I   J\n   ");
        for (int i = 0; i < 4 * MAX_ROW + 1; i++) {
            printf("%c", 205);
        }
        printf("\n");


        //affiche les bordure par rapport a la taille de la grille
        for (int i = 0; i < MAX_ROW; i++) {
            if (lineNumber < 10) {
                printf("%d  ", lineNumber);
            }
            if (lineNumber == 10) {
                printf("%d ", lineNumber);
            }
            lineNumber += 1;
            //affiche les bordures vertical inter-ligne
            for (int j = 0; j < MAX_LINE; j++) {
                printf("%c %d ", 186, board[i][j]);
            }

            //affiche la derniere bordure verticale inter-ligne
            printf("%c\n", 186);

            //affiche les bordure horizontale
            printf("   ");
            for (int k = 0; k < 4 * MAX_LINE + 1; k++) {
                printf("%c", 205);
            }
            printf("\n");
        }

        //recupere la valeur x en char et la converti en int
        do {
            printf("\n(A-J) x : ");
            fflush(stdin);
            scanf("%c", &x);
            x -= 65;
        } while (x < 0 || x > MAX_ROW);

        //recupere la valeur int de x
        convertedX = (int) (x);

        //recupere la valeur y
        do {
            printf("\n(1-10) y : ");
            scanf("%d", &y);
        } while (y <= 0 || y > MAX_LINE);

        //modifie la valeur pour correspondre a la plage 0:0 9:9
        convertedX -= 1;
        y -= 1;
        board[y][x] = 1;
    } while (bateaux > 0);
}

