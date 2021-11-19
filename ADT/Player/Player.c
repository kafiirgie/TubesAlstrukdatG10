#include "Player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setPlayer(player *thePlayer) {
    thePlayer->position = 0;
    scanf("%s", thePlayer->name);
}

void playerRoleDice(player* thePlayer,int maxDice) {
    int move = 0;
    move = rand() % maxDice+1;
    thePlayer->position += move;
}

void playerTeleport(player *thePlayer,int endPoint) {
    thePlayer->position = endPoint;
}

void playerOption() {
    int selection = -9;
}