//
// Created by benjamin.fontana on 13.03.2020.
//

#include <stdio.h>
#include <windows.h>
#include "options.h"
#include "menu.h"

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

    system("cls");
    printf("Voici les differents couleurs disponibles\n"
           "    0 = Noir        5 = Violet\n"
           "    1 = Bleu        6 = Jaune\n"
           "    2 = Vert        7 = Blanc\n"
           "    3 = Bleu-gris   8 = Gris\n"
           "    4 = Rouge       9 = Bleu clair\n\n"
           "Je vous conseil 0 comme premiere couleur pour eviter les surprises oculaires\n\n"
           "Quelle couleur de texte voulez-vous ?\n");

    scanf("%d", &fond);

    system("cls");

    printf("Et quelle couleur de fond voulez-cous ?");

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
            color();
            break;
    }
}