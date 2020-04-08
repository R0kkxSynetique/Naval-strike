//
// Created by benjamin on 28.02.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include <windows.h>
#include "menu.h"
#include "jouer.h"
#include "aide.h"
#include "options.h"
#include "sauvgarder.h"
#include "readscore.h"
#include "Utils.h"

/*
 * execute une des fonctions dispo
 */
void menuprincipal(){

    int choixjoueur,
            error = 0;

    //menu principal
    do{
        system("cls");
        afficherMenuPrincipalGrand();

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
            case 2:
                system("cls");
                lireFile();
                break;

            //regles
            case 3:
                system("cls");
                afficherRegleAscii();
                //pause de 30 sec
                system("pause");
                break;

            //options
            case 4:
                system("cls");
                optionPrincipale();
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
