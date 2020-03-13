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
    int y, bateaux = 5, lineNumber, convertedX, tirs = 0,      //Bateau = 17 (5+4+3+3+2)
            boat1 = 1, boat2 = 2, boat3 = 2, boat4 = 3, boat5 = 4;
    int board[MAX_LINE][MAX_ROW] = {                //0 = Water 2 = boat(2) 3 = boat(3) 4 = boat(4) 5 = boat(5)
            {2, 2, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 3, 3, 3, 0, 0, 0, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 5, 0},
            {0, 0, 0, 0, 3, 0, 0, 0, 5, 0},
            {0, 0, 0, 0, 3, 0, 0, 0, 5, 0},
            {0, 0, 0, 0, 3, 0, 0, 0, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 4, 4, 4, 4, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    int playerBoard[MAX_LINE][MAX_ROW] = {          //Grille que le joueur verra
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

    };

    do {

        system("cls");

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
                if (playerBoard[i][j] > 0 && board[i][j] > 0) {
                    printf("%c %c ", 186, 254);
                }
                if (playerBoard[i][j] > 0 && board[i][j] <= 0){
                    printf("%c%c%c%c", 186, 176, 176, 176);
                }
                if (playerBoard[i][j] == 0) {
                    printf("%c   ", 186);
                }
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

        //modifie la valeur de l emplacement du tir
        board[y][x] -= 1;

        //modifie la valeur de l affichage du tir
        playerBoard[y][x] += 1;

        //Si la valeur du tableau est pas de l'eau alors...
        if (board[y][x] > 0) {

            printf("\nTouche");

            //si boat1 est en vie modifie la valeur
            if (boat1 > 0) {
                if (board[0][0] < 2 && board[0][1] < 2) {
                    printf("\nTouche coule !");
                    boat1 = 0;
                    bateaux -= 1;
                }

            }
            //si boat2 est en vie modifie la valeur
            if (boat2 > 0) {
                if (board[2][2] < 3 && board[2][3] < 3 && board[2][4] < 3) {   //bateau(3) C3 E3
                    printf("\nTouche coule !");
                    boat2 = 0;
                    bateaux -= 1;
                }
            }
            //si boat3 est en vie modifie la valeur
            if (boat3 > 0) {
                if (board[4][4] < 3 && board[5][4] < 3 && board[6][4] < 3) {   //bateau(3) E5 E7
                    printf("\nTouche coule !");
                    boat3 = 0;
                    bateaux -= 1;
                }
            }
            //si boat4 est en vie modifie la valeur
            if (boat4 > 0) {
                if (board[8][4] < 4 && board[8][5] < 4 && board[8][6] < 4 && board[8][7] < 4) {   //bateau(4) E9 H9
                    printf("\nTouche coule !");
                    boat4 = 0;
                    bateaux -= 1;
                }
            }
            //si boat5 est en vie modifie la valeur
            if (boat5 > 0) {
                if (board[2][8] < 5 && board[3][8] < 5 && board[4][8] < 5 && board[5][8] < 5 &&
                    board[6][8] < 5) {   //bateau(5) I3 I7
                    printf("\nTouche coule !");
                    boat5 = 0;
                    bateaux -= 1;
                }
            }
        //si aucune des conditions est validée plouf
        } else {
            printf("\nPlouf !");
        }

        //incremente le compteur de tirs
        tirs += 1;

        //pause de 1 sec
        _sleep(1000);

    } while (bateaux > 0);

    //message de victoire
    printf("\nVous avez gagne en faisant %d tirs!\n", tirs);

    //pause de 1 sec
    _sleep(1000);
}