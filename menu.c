/**
 * @author: Benjamin Fontana
 * @date 04.03.2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include "menu.h"
#include "play.h"
#include "file.h"

void affichageMenuPrincipal(){
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
                affichageMenuPrincipal();
        }
    }
}
