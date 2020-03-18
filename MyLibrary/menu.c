//
// Created by benjamin on 28.02.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include <windows.h>
#include "menu.h"
#include "play.h"
#include "scores.h"
#include "aide.h"
#include "options.h"


/*
 * affiche le menu pricipal
 */
void affichageMenuPrincipal(){

    system("cls");

    printf(" Menu principal\n"
           "     ---\n");

    printf("  1 - Jouer\n"
           "  2 - Scores (Coming soon)\n"
           "  3 - Aide\n"
           "  4 - Options\n"
           "  5 - Quitter");
}

/*
 * execute une des fonctions dispo
 */
void menuprincipal(){

    int choixjoueur,
            error = 0;

    //menu principal
    do{
        affichageMenuPrincipal();

        //recupere le choix
        fflush(stdin);
        scanf("%d",&choixjoueur);


        switch (choixjoueur)
        {
            //jeu
            case 1:
                jeu();
                system("cls");
                break;

            //scores
//            case 2:
//                file();
//                break;

            //regles
            case 3:
                system("cls");
                afiicherRegle();
                //pause de 30 sec
                _sleep(30000);
                break;

            //options
            case 4:
                mainOptions();
                break;

            //sortie
            case 5:
                system("exit");

            default:
                printf("\nErreur! Ce choix n'est pas disponible\n");
                error = 1;
        }
    }while (error == 0);
}
