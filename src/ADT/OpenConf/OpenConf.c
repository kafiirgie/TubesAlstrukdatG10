#include "OpenConf.h"
#include <stdlib.h>


//MARK: Map related shits
void allocateMapLenght(int lenght) {
    map = (int) malloc (sizeof(int)*lenght);
    if (map != NULL) {
        map = NULL;
    }
}

void freeMap(void) {
    free(map);
}

//MARK: TELEPORT RELATED shits
void allocateTeleportPlacesLenght(int lenght) {
    teleportPlaces = (teleporters*) malloc (sizeof(teleporters) * (lenght-1));
    if (teleportPlaces != NULL) {
        teleportPlaces = NULL;
    }
}

void assignTeleportPlaces(void) {
    // example : teleportPlaces[0].start = 0;
}

void freeTeleportPlaces(void) {
    free(teleportPlaces);
}