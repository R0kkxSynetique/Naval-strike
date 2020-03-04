//
// Created by benjamin.fontana on 28.02.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>


#ifndef BATAILLE_NAVALE_JOUER_H
#define BATAILLE_NAVALE_JOUER_H

#define MAX_LINE 10
#define MAX_ROW 10

/**
 * deroulement de la partie(jeu)
 */
void jeu() {

    int board[MAX_LINE][MAX_ROW];
    int x, y, bateaux = 1;

    //definit la valeur par defaut du tableau a 0
    memset(board, 0, sizeof(board));

    do {
        //affiche la premiere ligne de la grille
        printf("\n");
        for (int i = 0; i < 4 * MAX_ROW; i++) {
            printf("%c", 205);
        }
        //affiche le dernier caractere de la premiere ligne
        printf("%c\n", 205);


        //affiche les bordure par rapport a la taille de la grille
        for (int i = 0; i < MAX_ROW; i++) {

            //affiche les bordures verticale inter-ligne
            for (int j = 0; j < MAX_LINE; j++) {
                printf("%c %d ", 186, board[i][j]);
            }

            //affiche la derniere bordure verticale inter-ligne
            printf("%c\n", 186);

            //affiche les bordure horizontale
            for (int k = 0; k < 4 * MAX_LINE; k++) {
                printf("%c", 205);
            }
            //affiche la derniere bordure horizontal
            printf("%c\n", 205);
        }

        //recupere la valeur x
        do {
            printf("\nx : ");
            scanf("%d", &x);
        } while (x <= 0 || x > MAX_ROW);

        //recupere la valeur y
        do {
            printf("\ny : ");
            scanf("%d", &y);
        } while (y <= 0 || y > MAX_LINE);

        //modifie la valeur a la coordonee x:y
        x -= 1;
        y -= 1;
        board[y][x] = 1;
    } while (bateaux > 0);
}

#endif //BATAILLE_NAVALE_JOUER_H