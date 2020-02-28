#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>

#include "Menu.h"

/**
 * regle du jeu
 */
void aide(){
    printf("Voici l'aide pour apprendre a jouer.\n");
}



/**
 * appel les fonctions
 */
int main()
{
    //TODO plateau 10x10
    // regle
    // 10 bateaux(4x 2 3x 3 2x 4 1x 5)
    // trouver comment faire un tableau X|
    // afficher l'adie du jeu
    // creer des utilisateurs
    // pouvoir se logger en tant qu'utilisateur(pas besoin de stocker)
    // choisis une grille rnd dans un repertoire et l'utilise
    // affiche la liste des scores precedent
    // menu de type console
    // CODE COMMANTE !!!!!
    affichagemenu();
    menuprincipal();

    return 0;
}