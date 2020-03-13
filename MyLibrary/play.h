//
// Created by benjamin on 04.03.2020.
//

#ifndef BATAILLE_NAVALE_PLAY_H
#define BATAILLE_NAVALE_PLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>

#define MAX_LINE 10
#define MAX_ROW 10

int lineNumber;
int board[MAX_LINE][MAX_ROW];
int playerBoard[MAX_LINE][MAX_ROW];

void jeu();

#endif //BATAILLE_NAVALE_PLAY_H
