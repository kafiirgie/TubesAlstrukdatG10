#include "OpenConf.h"

int main(int argc, char **argv) {
    int lenght = 2;
    teleporters tele;
    tele.start = 0;
    tele.end = 0;
    allocateTeleportPlacesLenght(lenght);

    for (int i = 0; i < lenght; i++) {
        teleportPlaces[i] = tele;
    }

    for (int i = 0; i < lenght; i++) {
        //printf("Error at map, map[0] = %d\n",map[0]);
        map[i] = '#';
    }

    if (teleportPlaces[0].end != 0 ) {
        printf("Error at teleport");
        return 0;
    }

    if (map[0] == '#') {
        printf("Error at map, map[0] = %d",map[0]);
        return 0;
    }


    printf("All test finished");
    freeTeleportPlaces();
    return 0;
}
