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

int getDiceValue(int minRoll, int maxRoll);
// Generate random dice value with interval minRoll-maxRoll 

void playerRollDice(player *thePlayer, int maxDice);
// Roll dice and move player

void playerTeleport(player *thePlayer);
// Check if teleport eligible at that point and condition, if it's then the player will teleport

void runTeleport(player *thePlayer);
// Teleport player from inPoint to outPoint

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

void showPlayerPosition(int position); //adt player
// show the position of the player

#endif