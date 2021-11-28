// File: Configuration.h
// Define map (arr of char), teleport, arr of teleport, maxDiceRole 

#ifndef Configuration_h
#define Configuration_h

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "../MesinKarKat/mesin_kata.h"

extern int maxDiceRole;
extern char map[255];
extern int mapLength;
extern int teleportLength;

typedef struct {
    int inPoint;
    int outPoint;
} teleport;

teleport *teleporters;

void setConfigFile();
// Set the config name

void loadConfig();
// Load the config

void setMapLength(int length);
// Set the map length

void setMap(Kata mapConfig);
// Set the map value

void displayMap(); //adt map
// display game map

void inspectMap(int point); //adt map
// Check if there is a teleporter at that point

void allocateTeleportersLength(int length);
// Allocate memory for teleporters

void freeTeleporters();
// Dealloccte memory for teleporters

void setTeleporter(int index, int in, int out);
// Set teleporter value

void setMaxDiceRole(int value);
//set dice role max

#endif