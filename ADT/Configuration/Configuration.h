//
//  Configuration.h
//  AlstrukDat
//
//  Created by Farhandika Zahrir Mufti guenia on 31/08/21.
//

#ifndef Configuration_h
#define Configuration_h

#include <stdio.h>
#include <stdlib.h>
#include "../MesinKarKat/mesin_kata.h"
#include<string.h>

extern char map[255];
extern int mapLenght;
extern int maxDiceRole;
typedef struct {
    int startPoint;
    int endPoint;
} teleport;

teleport *teleporters;

void loadConfig();
//Load the config
void setConfigFile();
//set the config name
void setMapLenght(int lenght);
// set the map lenght
void setMap(Kata mapConfig);
// set the map value
void allocateTeleportersLenght(int lenght);
// allocate memory for teleporters
void freeTeleporters();
void setTeleporter(int index,int start,int end);
//set teleportter value
void setMaxDiceRole(int value);
//set dice role max

#endif /* boolean_h */