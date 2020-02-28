#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 10
#define MAX_ROW 10

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

    int board[MAX_LINE][MAX_ROW] ;
    int x, y, bateaux = 1;


    do
    {
        printf("\n");
        for (int i = 0; i < 4*MAX_ROW; i++)
        {
            printf("%c", 205);
        }

        printf("%c\n", 205);
        memset(board, 0, sizeof(board));

        for (int i = 0; i < MAX_LINE; i++)
        {
            for (int j = 0; j < MAX_LINE; j++)
            {
                printf("%c %d ", 186, board[i][j]);
            }


            printf("%c\n", 186);

            for (int k = 0; k < 4*MAX_LINE; k++)
            {
                printf("%c", 205);
            }

            printf("%c\n", 205);
        }

        do {
            printf("\nx : ");
            scanf("%d", &x);
        } while (x < 0 || x > MAX_ROW);

        do {
            printf("\ny : ");
            scanf("%d", &y);
            board[x][y] = 1;
        } while (y < 0 || y > MAX_LINE);
    }while (bateaux > 0);
    return 0;
}