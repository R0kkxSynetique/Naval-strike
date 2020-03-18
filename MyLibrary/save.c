//
// Created by babs2 on 18.03.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dir.h>
#include "save.h"

int saveScores(int score) {

    char username[20];

    FILE* fichier = NULL;

    fichier = fopen("scores.txt", "a");

    if (fichier == NULL){
        fichier = fopen("scores.txt", "w");
    }

    if (fichier != NULL){

        printf("Nom d'utilisateur:");

        scanf("%s", username);

        fprintf(fichier, "%s: %d \n", username, score);

        fclose(fichier);
    }
    else {
        printf("Erreur d'ouverture de fichier!");
    }

    return 0;
}