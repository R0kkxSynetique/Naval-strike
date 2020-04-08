//
// Created by benjamin on 28.02.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include<time.h>
#include <ctype.h>
#include "sauvgarder.h"
#include "jouer.h"
#include "logs.h"


/**
 * deroulement de la partie(jeu)
 */
void jeu() {

    //variables pour le jeu
    char x;
    int y, bateaux = 5, numeroLinge, xConvertis, tirs = 0, typeLogs;

    //variabes de bateau
    int bateau1 = 0, bateau2 = 0, bateau3 = 0, bateau4 = 0, bateau5 = 0;

    //variables pour la grille
    int car, compteur = 0, grilleRng;
    char caractereActuel;

    int grille[MAX_LIGNE][MAX_COLONNE] = {0};                //Grille ou les valeurs sont stockee
    int grilleJoueur[MAX_LIGNE][MAX_COLONNE] = {0};          //Grille que le joueur verra

    time_t t;
    srand((unsigned) time(&t));

    grilleRng = rand() % 4;

    FILE *fichier = NULL;

    //choisis une grille
    switch (grilleRng) {
        case 0:
            fichier = fopen("grilles/grille0.txt", "r");
            break;
        case 2:
            fichier = fopen("grilles/grille1.txt", "r");
            break;
        case 3:
            fichier = fopen("grilles/grille2.txt", "r");
            break;
        case 4:
            fichier = fopen("grilles/grille3.txt", "r");
            break;
        case 5:
            fichier = fopen("grilles/grille4.txt", "r");
            break;
        default:
            system("exit");
    }

    //place la valeur du fichier dans le tableau
    if (fichier != NULL) {
        x = 0;
        y = 0;
        do {

            caractereActuel = (char) fgetc(fichier);

            if (isdigit(caractereActuel)) {
                caractereActuel -= '0';
                grille[y][x] = caractereActuel;
                if (x < MAX_COLONNE - 1) {
                    x++;
                } else {
                    x = 0;
                    y++;
                }
            }

        } while (!feof(fichier));
        fclose(fichier);

    } else {
        printf("Le fichier n'a pas pu être ouvert...\n");
        system("pause");
    }

    do {

        system("cls");

        numeroLinge = 1;

        //affiche la premiere ligne de la grille
        printf("\n");
        printf("     A   B   C   D   E   F   G   H   I   J\n   ");
        for (int i = 0; i < 4 * MAX_COLONNE + 1; i++) {
            printf("%c", 205);
        }
        printf("\n");


        //affiche les bordure par rapport a la taille de la grille
        for (int i = 0; i < MAX_COLONNE; i++) {
            if (numeroLinge < 10) {
                printf("%d  ", numeroLinge);
            }
            if (numeroLinge == 10) {
                printf("%d ", numeroLinge);
            }
            numeroLinge += 1;

            //affiche les bordures vertical inter-ligne
            for (int j = 0; j < MAX_LIGNE; j++) {
                if (grilleJoueur[i][j] > 0 && grille[i][j] > 0) {
                    printf("%c %c ", 186, 254);
                }
                if (grilleJoueur[i][j] > 0 && grille[i][j] <= 0) {
                    printf("%c%c%c%c", 186, 176, 176, 176);
                }
                if (grilleJoueur[i][j] == 0) {
                    printf("%c   ", 186);
                }
            }

            //affiche la derniere bordure verticale inter-ligne
            printf("%c\n", 186);

            //affiche les bordure horizontale
            printf("   ");
            for (int k = 0; k < 4 * MAX_LIGNE + 1; k++) {
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
        } while (x < 0 || x > MAX_COLONNE);

        //recupere la valeur int de x
        xConvertis = (int) (x);

        //recupere la valeur y
        do {
            printf("\n(1-10) y : ");
            scanf("%d", &y);
        } while (y <= 0 || y > MAX_LIGNE);

        //modifie la valeur pour correspondre a la plage 0:0 9:9
        xConvertis -= 1;
        y -= 1;

        //modifie la valeur de l emplacement du tir
        //grille[y][x] -= 1;

        //modifie la valeur de l affichage du tir
        grilleJoueur[y][x] += 1;

        //verifie si il y a un bateau
        if (grille[y][x] > 0) {

            typeLogs = 1;

            //donne le resultat du tir
            switch (grille[y][x]) {
                case 1:
                    if (bateau1 < 1) {
                        printf("touche!");
                        bateau1++;
                    } else {
                        printf("touche coule!");
                        bateaux++;
                    }
                    break;
                case 2:
                    if (bateau2 < 2) {
                        printf("touche!");
                        bateau2++;
                    } else {
                        printf("touche coule!");
                        bateaux++;
                    }
                    break;
                case 3:
                    if (bateau3 < 2) {
                        printf("touche!");
                        bateau3++;
                    } else {
                        printf("touche coule!");
                        bateaux++;
                    }
                    break;
                case 4:
                    if (bateau4 < 3) {
                        printf("touche!");
                        bateau4++;
                    } else {
                        printf("touche coule!");
                        bateaux++;
                    }
                    break;
                case 5:
                    if (bateau5 < 4) {
                        printf("touche!");
                        bateau5++;
                    } else {
                        printf("touche coule!");
                        bateaux++;
                    }
                    break;
                default:
                    break;
            }
        }else{
            printf("plouf!");
        }

        typeLogs = 0;

        //incremente le compteur de tirs
        tirs += 1;

        //sauvegarde les log (coordonnee des tirs)
        sauvgarderLogs(y += 1, x += 65, typeLogs);

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

    //verifie si l'utilisateur veux sauvegarder ou non
    scanf("%d", &yesNo);
    if (yesNo == 1) {
        savegarderScore(tirs);
    }
}