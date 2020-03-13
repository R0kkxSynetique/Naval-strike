/**
 * @author: Benjamin Fontana
 * @date: 06.03.2020
 */

#include <windows.h>
#include "MyLibrary/menu.h"

/**
 * appel les fonctions
 */
int main()
{
    //TODO plateau 10x10
    // 5 bateaux(1x2 2x3 2x4 1x5)
    // creer des utilisateurs
    // pouvoir se logger en tant qu'utilisateur(pas besoin de stocker)
    // choisis une grille rnd dans un repertoire et l'utilise
    // affiche la liste des scores precedent
    // menu de type console
    // CODE COMMANTE !!!!!

    //fullscreen
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);

    system("cls");

    menuprincipal();

    return 0;
}