// File: Player.h
// Define player adt 

#ifndef Player_h
#define Player_h

#include "../boolean.h"
#include "../Skill/Skill.h"


typedef struct {
    int position; //Initial position is always 0
    char name[20];
    skill skills;
    boolean buff[4]; //Initial buff is always all false
} player;


void setPlayer(player *thePlayer);
// Set player properties

void playerRoleDice(player *thePlayer, int maxDice);
// Role dice

void playerTeleport(player *thePlayer);
// Check if teleport eligible at that point and condition, if it's then the player will teleport

boolean isCanTeleport(player *thePlayer);
// Check is teleport eligible at that point

boolean isPlayerCanMove(int change, int position, boolean isUpward);
// Check future displacement

int playerOption();
// Scan the option

void resetPlayerBuff(player *thePlayer);
// reset player buff for every round

void showPlayerBuff(player *thePlayer);
// show player buff that active


#endif