#ifndef OPENCONF_H
#define OPENCONF_H

#include <stdlib.h>
#include <stdio.h>

char map[100];

typedef struct teleporter {
    int start;
    int end;
}teleporters;

teleporters *teleportPlaces;

int maxRole;
int mapLenght;

void assignMap(void);
/*  
I.S. 
Assign si map ke dalam variable map, SETELAH KITA allocate lenghtnya
*/

void allocateTeleportPlacesLenght(int lenght);
/* 
I.S. 
Karena dia array dynamic, pas assign jgn lupa 
*/
void assignTeleportPlaces(void);
/*  
I.S. 
Assign si teleporters ke dalam variable map, SETELAH KITA allocate lenghtnya
*/


void freeTeleportPlaces(void);
/* I.S. 
Free Map 
*/

void loadConfig(void);
#endif