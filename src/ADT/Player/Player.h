#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>


//Ini gw ga tau player proertynya apa2aja
typedef struct player {
    int currPoint;
    int end;
}players;


extern int playing = 0;
extern players playersData[4];

//Initalization of player
void setupPlayer();

/* 

move = user's dice value
*/
void playerMove(players *thePlayer,int move);

//Player teleport
/*
where can be obtain from the teleporter data type inside OpenConf.h
*/
void playerTeleport(players *thePlayer,int where);
#endif