//
// Created by benjamin.fontana on 18.03.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dir.h>
#include "sauvgarder.h"

int savegarderScore(int score) {

    char nomUtilisateur[20];

    FILE *fichier = NULL;

    fichier = fopen("files/scores.txt", "a");

    if (fichier == NULL) {
        fichier = fopen("scores.txt", "w");
    }

    if (fichier != NULL) {

        printf("Nom d'utilisateur:");

        scanf("%s", nomUtilisateur);

        fprintf(fichier, "%s: %d \n", nomUtilisateur, score);

        fclose(fichier);
    } else {
        printf("Erreur d'ouverture de fichier!");
    }

    return 0;
}