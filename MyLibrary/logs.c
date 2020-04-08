//
// Created by benjamin.fontana on 27.03.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dir.h>
#include <time.h>
#include "logs.h"

void sauvgarderLogs(int y, char x, int type) {

    time_t actualTime = time(NULL);
    char * time_str = ctime(&actualTime);
    time_str[strlen(time_str)-1] = '\0';

    FILE *fichier = NULL;

    fichier = fopen("files/logs.txt", "a");

    if (fichier == NULL) {
        fichier = fopen("logs.txt", "w");
    }

    if (fichier != NULL) {
        if (type == 1){
            fprintf(fichier, "%s: %c%d Touche\n", time_str, x, y);
        }else{
            fprintf(fichier, "%s: %c%d plouf\n", time_str, x, y);
        }

        fclose(fichier);
    } else {
        printf("Erreur d'ouverture de fichier!");
    }
}