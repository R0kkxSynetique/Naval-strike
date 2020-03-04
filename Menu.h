//
// Created by benjamin.fontana on 28.02.2020.
//

#include "Play.h"
#include "File.h"

#ifndef BATAILLE_NAVALE_MENU_H
#define BATAILLE_NAVALE_MENU_H

void affichagemenu(){
    printf("menu principal\n");
    printf("1 - Jouer\n");
    printf("2 - Scores\n");
}

void menuprincipal(){
    int choixjoueur,
    error = 1;
    while (error = 1)
    {
        error = 0;
        scanf("%d",&choixjoueur);

        switch (choixjoueur)
        {
            case 1:
                jeu();
                break;
            case 2:
                file();
                break;
            default:
                printf("\nErreur! Ce choix n'est pas disponible\n");
                error = 1;
                affichagemenu();

        }
    }
}
#endif //BATAILLE_NAVALE_MENU_H