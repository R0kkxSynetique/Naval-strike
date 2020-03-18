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
void file() {

    char score[MAX_TEXT_LENGTH], username[MAX_TEXT_LENGTH], desktop_path[MAX_TEXT_LENGTH] = "C:\\users\\";

    //definit le pointeur
    FILE *fptr;
    mkdir("files");
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fptr = fopen("logs.txt", "a");
    fclose(fptr);

    //demande pseudo
    printf("Pseudo :");
    fflush(stdin);
    gets(username);
    system("cls");

    while (1) {

        //affiche historique scores + username
        system("cls");
        fptr = fopen("logs.txt", "r");
        while (1) {
            fgets(score, MAX_TEXT_LENGTH, fptr);
            if (feof(fptr)) {
                break;
            }
            printf("%s", score);
        }
        fclose(fptr);


        //ecrit le score
        fflush(stdin);
        gets(score);

        //sortir
        if (strcmp(score, "exit") == 0) {
            break;
        }

        //ajoute le texte dans un fichier
        fptr = fopen("logs.txt", "a");
        fprintf(fptr, "%s: %s\n", username, score);
        fclose(fptr);
    }
}
