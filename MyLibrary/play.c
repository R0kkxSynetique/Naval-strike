//
// Created by benjamin on 28.02.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include<time.h>
#include "save.h"
#include "play.h"
#include "logs.h"


/**
 * deroulement de la partie(jeu)
 */
void jeu() {

    //variables pour le jeu
    char x;
    int y, bateaux = 5, lineNumber, convertedX, tirs = 0, logsType;

    //variabes de bateau
    int boat1 = 0, boat2 = 0, boat3 = 0, boat4 = 0, boat5 = 0;

    //variables pour la grille
    int car, compteur = 0, grilleRng;
    char caractereActuel;

    int board[MAX_LINE][MAX_ROW] = {0};                //0 = Water 2 = boat(2) 3 = boat(3) 4 = boat(4) 5 = boat(5)
    int playerBoard[MAX_LINE][MAX_ROW] = {0};          //Grille que le joueur verra

    time_t t;
    srand((unsigned) time(&t));

    grilleRng = rand() & 4;

    FILE *fichier = NULL;

    switch (grilleRng) {
        case 0:
            fichier = fopen("grilles/grille0.txt", "r");
            break;
        case 2:
            fichier = fopen("grilles/grille2.txt", "r");
            break;
        case 3:
            fichier = fopen("grilles/grille3.txt", "r");
            break;
        case 4:
            fichier = fopen("grilles/grille4.txt", "r");
            break;
        case 5:
            fichier = fopen("grilles/grille5.txt", "r");
            break;
        default:
            system("exit");
    }

    if (fichier != NULL) {

        do {

            fscanf(fichier, "%c", &caractereActuel);

            printf("%c", caractereActuel);
            if (caractereActuel != '\n') {
                for (int j = 0; j < MAX_LINE; j++) {
                    for (int k = 0; k < MAX_ROW; k++) {
                        board[k][j] = (int) caractereActuel;
                    }
                }
            }
        } while (caractereActuel != EOF);
        fclose(fichier);

    } else {
        printf("Le fichier n'a pas pu être ouvert...\n");
        system("pause");
    }

    do {

        //system("cls");

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
                if (playerBoard[i][j] > 0 && board[i][j] <= 0) {
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
            printf("Pour quitter faites \"+\"\n"
                   "(A-J) x : ");
            fflush(stdin);
            scanf("%c", &x);
            if (x == '+') {
                return;
            }
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
        //board[y][x] -= 1;

        //modifie la valeur de l affichage du tir
        playerBoard[y][x] += 1;

        if (board[x][y] > 0) {
            logsType = 1;
            if (board[y][x] == 1 && boat1 < 2) {
                printf("touche!");
                boat1++;
            }
            if (board[y][x] == 2 && boat2 < 3) {
                printf("touche!");
                boat2++;
            }
            if (board[y][x] == 3 && boat3 < 3) {
                printf("touche!");
                boat3++;
            }
            if (board[y][x] == 4 && boat4 < 4) {
                printf("touche!");
                boat4++;
            }
            if (board[y][x] == 5 && boat5 < 5) {
                printf("touche!");
                boat5++;
            }
        }

        if (board[y][x] == 0){
            printf("plouf!");
        }


        logsType = 0;

        //incremente le compteur de tirs
        tirs += 1;

        //sauvegarde les log (coordonnee des tirs)
        saveLogs(y += 1, x += 65, logsType);

        //pause de 1 sec
        _sleep(1000);

    } while (bateaux > 0);

    system("cls");
    //message de victoire
    printf("\nVous avez fini en faisant %d tirs!\n", tirs);

    //pause de 1 sec
    _sleep(5000);

    int yesNo;

    printf("Voulez-vous enregistrer votre score? (1(Oui) / 2(Non)");

    scanf("%d", &yesNo);
    if (yesNo == 1) {
        saveScores(tirs);
    }
}