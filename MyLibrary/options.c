//
// Created by benjamin.fontana on 13.03.2020.
//

#include <stdio.h>
#include <windows.h>
#include "options.h"
#include "menu.h"
#include "Utils.h"

int concat(int a, int b) {
    char s1[20];
    char s2[20];

    // Convert both the integers to string
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);

    // Concatenate both strings
    strcat(s1, s2);

    // Convert the concatenated string to integer
    int c = atoi(s1);

    return c;
}

void fullscreen() {
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void color() {

    int fond, text;

    scanf("%d", &fond);

    scanf("%d", &text);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), concat(fond, text));

}

void mainOptions() {

    int optionChoice;

    system("cls");

    printf("Choissisez une option a modifier\n\n"
           "1 - Fullscreen ON/OFF\n"
           "2 - Couleur\n");

    fflush(stdin);
    scanf("%d", &optionChoice);

    switch (optionChoice) {
        case 1:
            fullscreen();
            break;
        case 2:
            afficherOptions();
            color();
            break;
    }
}