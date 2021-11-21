#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Player.h"

void setPlayer(Player *thePlayer) {
    Position(*thePlayer) = 0;
    scanf("%s", &Name(*thePlayer)); //ini gatau error ga ya
    PMap(*thePlayer) = gameMap;
    CreateEmptySkill(&PSkill(*thePlayer)); //ini gatau error ga ya
    CreateEmptyBuff(&PBuff(*thePlayer)); //ini gatau error ga ya
}

void setPlayerMap(Player *thePlayer) {
    if (Position(*thePlayer) != 0){
        SetElMap(&PMap(*thePlayer), Position(*thePlayer), '*');
    }
}

void playerRoleDice(Player *thePlayer, int maxDice) {
    int move = 0;
    move = (rand() % maxDice) + 1;
    //belum cek petak terlarang
    Position(*thePlayer) += move;
    setPlayerMap(thePlayer);
}

void playerTeleport(Player *thePlayer, int endPoint) {
    Position(*thePlayer) = endPoint;
    setPlayerMap(thePlayer);
}


/*void playerOption() {
    int selection = -9;
}*/