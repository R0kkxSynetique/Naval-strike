//
// Created by benjamin on 28.02.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include "menu.h"
#include "play.h"
#include "file.h"
#include "aide.h"

void affichageMenuPrincipal(){
    printf(" Menu principal\n"
           "     ---\n");
    printf("  1 - Jouer\n"
           "  2 - Scores\n"
           "  3 - Aide\n"
           "  4 - Quitter\n");
}

void menuprincipal(){
    int choixjoueur,
            error = 0;
    do{
        fflush(stdin);
        scanf("%d",&choixjoueur);
        switch (choixjoueur)
        {
            case 1:
                jeu();
                system("cls");
                affichageMenuPrincipal();
                break;
            case 2:
                file();
                break;
            case 3:
                afiicherRegle();
                _sleep(35000);
                affichageMenuPrincipal();
                break;
            case 4:
                system("exit");
            default:
                printf("\nErreur! Ce choix n'est pas disponible\n");
                affichageMenuPrincipal();
                error = 1;
        }
    }while (error == 0);
}
