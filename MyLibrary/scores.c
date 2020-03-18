//
// Created by benjamin on 04.03.2020.
//


#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include "scores.h"

#define MAX_TEXT_LENGTH 255

/*
 * recupere les scores et les trie
 */

int saveScores(int score) {

    char username[20];

    FILE* fichier = NULL;

    fichier = fopen("scores.txt", "a");

    if (fichier == NULL){
        fichier = fopen("scores.txt", "w");
    }

    if (fichier != NULL){

        printf("Username:");

        scanf("%s", username);

        fprintf(fichier, "%s: %d \n", username, score);

        fclose(fichier);
    }
    else {
        printf("nan");
    }

    return 0;
}
