//
// Created by babs2 on 20.03.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "lirescore.h"

/*
 * lis tout les caractères du fichier scores
 */
void lireFichier(){

    char caractere;

    FILE* fichier = NULL;

    fichier = fopen("files/scores.txt", "r");

    if (fichier != NULL) {
        do {
            caractere = fgetc(fichier);
            printf("%c", caractere);
        } while (caractere != EOF);
    }

    system("pause");

    fclose(fichier);
};