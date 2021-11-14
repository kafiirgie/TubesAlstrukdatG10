#ifndef OpenConf_H
#define OpenConf_H

extern char map;

typedef struct teleporter {
    int start;
    int end;
}teleporters;

extern teleporters *teleportPlaces;

void allocateMapLenght(int lenght);
/* 
I.S. 
Karena dia array dynamic, pas assign jgn lupa 
*/
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

void freeMap(void);
/* I.S. 
Free Map 
*/

void freeTeleportPlaces(void);
/* I.S. 
Free Map 
*/
#endif