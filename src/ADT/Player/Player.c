#include "Player.h"

void setupPlayer() {
    //MARK: Adding player initial properties
    players player;
    player.currPoint = 0;
    for (int i = 0; i < playing; i++) {
        //MARK: Assigning player to the player pool
        playersData[i] = player;
    }
}

void playerMove(players *thePlayer,int move) {
    thePlayer->currPoint += move;
}

void playerTeleport(players *thePlayer,int where) {
    thePlayer->currPoint = where;
}

void getPlayerRank() {
    
}