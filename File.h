#ifndef BATAILLE_NAVALE_IDK_H
#define BATAILLE_NAVALE_IDK_H

#endif //BATAILLE_NAVALE_IDK_H

#include <stdio.h>
#include <stdlib.h>
#include <dir.h>

#define MAX_TEXT_LENGTH 255

void file() {

    char score[MAX_TEXT_LENGTH], username[MAX_TEXT_LENGTH], desktop_path[MAX_TEXT_LENGTH] = "C:\\users\\";

    //definit le pointeur
    FILE *fptr;
    mkdir("files");
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fptr = fopen("C:\\Users\\Benjamin.FONTANA\\Documents\\GitHub\\Prog-C\\Naval-strike\\logs.txt", "a");
    fclose(fptr);

    //demande pseudo
    printf("Pseudo :");
    fflush(stdin);
    gets(username);
    system("cls");

    while (1) {

        //affiche historique scores + username
        system("cls");
        fptr = fopen("C:\\Users\\Benjamin.FONTANA\\Documents\\GitHub\\Prog-C\\Naval-strike\\logs.txt", "r");
        while (1) {
            fgets(score, MAX_TEXT_LENGTH, fptr);
            if (feof(fptr)) {
                break;
            }
            printf("%s", score);
        }
        fclose(fptr);


        //ecrire score
        fflush(stdin);
        gets(score);

        //sortir
        if (strcmp(score, "exit") == 0) {
            break;
        }

        //ajout texte dans fichier
        fptr = fopen("C:\\Users\\Benjamin.FONTANA\\Documents\\GitHub\\Prog-C\\Naval-strike\\logs.txt", "a");
        fprintf(fptr, "%s: %s\n", username, score);
        fclose(fptr);
    }
}

