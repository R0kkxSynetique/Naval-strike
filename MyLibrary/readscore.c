//
// Created by babs2 on 20.03.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "readscore.h"
/*
 * lis tout les caractères du fichier scores
 */
void lireFile(){

    char character;

    FILE* fichier = NULL;

    fichier = fopen("scores.txt", "r");

    if (fichier != NULL) {
        do {
            character = fgetc(fichier);
            printf("%c", character);
        } while (character != EOF);
    }

    system("pause");

    fclose(fichier);
};