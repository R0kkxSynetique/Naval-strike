//
// Created by benjamin.fontana on 13.03.2020.
//

#include <stdio.h>
#include <windows.h>
#include "options.h"
#include "menu.h"
#include "Utils.h"
/*
 * Concatene les 2 variables
 */
int concat(int a, int b) {
    char s1[20];
    char s2[20];

    // Convertis les 2 int en string
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);

    // Concatene les 2 strings
    strcat(s1, s2);

    // Convertis les string concatene en int
    int c = atoi(s1);

    return c;
}

/*
 * option de plein ecran
 */
void pleinEcran() {
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

/*
 * option de couleur
 */
void couleur() {

    int fond, text;

    scanf("%d", &text);

    scanf("%d", &fond);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), concat(fond, text));

}

/*
 * gere le choix des options
 */
void optionPrincipale() {

    int choixOption;

    system("cls");

    afficherOprions();

    fflush(stdin);
    scanf("%d", &choixOption);

    switch (choixOption) {
        case 1:
            pleinEcran();
            break;
        case 2:
            system("cls");
            afficherOptionColor();
            couleur();
            break;
        default:
            break;
    }
}