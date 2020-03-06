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
    printf("menu principal\n");
    printf("1 - Jouer\n"
           "2 - Scores\n"
           "3 - Aide\n"
           "4 - Quitter\n");
}

void menuprincipal(){
    int choixjoueur,
            error = 0;
    do{
        scanf("%d",&choixjoueur);
        switch (choixjoueur)
        {
            case 1:
                jeu();
                break;
            case 2:
                file();
                break;
            case 3:
                afiicherRegle();
                break;
            default:
                printf("\nErreur! Ce choix n'est pas disponible\n");
                affichageMenuPrincipal();
                error = 0;
        }
    }while (error == 1);
}
