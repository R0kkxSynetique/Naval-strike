//
// Created by benjamin.fontana on 06.03.2020.
//

#include "aide.h"
#include <stdio.h>


void afiicherRegle(){
    printf("Regle\n"
           "Votre flotte a 5 bateaux qui sont les suivant:\n"
           "1 porte-avion(5 cases)\n"
           "1 croiseur(4 cases)\n"
           "1 contre-torpilleur(3 cases)\n"
           "1 sous-marin(3 cases)\n"
           "1 torpilleur (2 cases)\n"
           "Les bateaux ne sont pas colles entre eux.\n"
           "La grille est numerotee de 1 a 10 verticalement\n"
           "et de A a J horizontalement. Vous allez \"tirer\"\n"
           "sur une case de l'adversaire: exemple, B.3. le but est\n"
           "donc de couler les bateaux adverses. au fur et\n"
           "a mesure des \"marqueurs\" serons affiche afin de se\n"
           "souvenir de vos tirs passes.\n"
           "1 - Quitter");
}