#ifndef Configuration_h
#define Configuration_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../MesinKarKat/mesin_kata.h"
#include "../Map/Map.h"
#include "../Teleport/Teleport.h"

//extern char map[255];
//extern int mapLength;
extern int maxDiceRole;
extern Map gameMap;
extern TabTeleport gameTeleport;
extern char fileName[];

/*typedef struct {
    int startPoint;
    int endPoint;
} teleport;*/

//teleport *teleporters;

void loadConfig();
//Load the config

void setConfigFile();
//set the config name

////void setMapLength(int length);
// set the map length

void setMap(Kata mapConfig);
// set the map value

void setMaxDiceRole(int value);
//set dice role max

// allocate memory for teleporters
//void allocateTeleportersLength(int length);
//void freeTeleporters();

////void setTabTPLength(int length);
// set tabteleporter length

////void setTP(int index, int in, int out);
// set teleportter value


#endif