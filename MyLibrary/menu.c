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
#include "file.h"
#include "aide.h"
#include "options.h"

void affichageMenuPrincipal(){

    system("cls");

    printf(" Menu principal\n"
           "     ---\n");

    printf("  1 - Jouer\n"
           "  2 - Scores\n"
           "  3 - Aide\n"
           "  4 - Options\n"
           "  5 - Quitter");
}

void menuprincipal(){

    int choixjoueur,
            error = 0;

    do{
        affichageMenuPrincipal();

        fflush(stdin);
        scanf("%d",&choixjoueur);

        switch (choixjoueur)
        {
            case 1:
                jeu();
                system("cls");
                break;
            case 2:
                file();
                break;
            case 3:
                system("cls");
                afiicherRegle();
                _sleep(35000);
                break;
            case 4:
                mainOptions();
                break;
            case 5:
                system("exit");
            default:
                printf("\nErreur! Ce choix n'est pas disponible\n");
                error = 1;
        }
    }while (error == 0);
}
