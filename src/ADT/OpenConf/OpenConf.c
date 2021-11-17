#include "OpenConf.h"
#include <stdlib.h>
#include <stdio.h>
#include "mesin_kata.h"


//MARK: Map related shits
void allocateMapLenght(int lenght) {
    map = (char) malloc (sizeof(char)*lenght);
    if (map != NULL) {
        map = NULL;
    }
}

void freeMap(void) {
    free(map);
}

//MARK: TELEPORT RELATED shits
void allocateTeleportPlacesLenght(int lenght) {
    teleportPlaces = (teleporters*) malloc (sizeof(teleporters) * (lenght));
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


// PERLU DIPERBAIKIN!
void loadConfig() {
    printf("DONT FORGET TO ADD '.' AT THE END OF THE LINE!\n");
    printf("Configuration file name : \n");
    FILE * fp;
    int line = 0;
    int index = 0;
    //MARK: Bagian ini perlu perbaikan
    STARTKATA();
    if (EndKata) {
        return;
    }
    fp = fopen (CKata.TabKata, "r");
    while (!feof(fp)) {
        line ++;
        if (line == 1) {
            allocateMapLenght(atoi(fgetc(fp)));
        } else if (line == 2) {
            map = fgetc(fp);
        } else if (line == 3) {
            maxRole = atoi(fgetc(fp));
        } else if (line == 4) {
            allocateTeleportPlacesLenght(atoi(fgetc(fp)));
        } else {
            //MARK: Work on Progress
            //assignTeleportPlaces();
            // ADD Start Point
            teleportPlaces[index].start = 0;
            // ADD End point
            teleportPlaces[index].end = 0;
            index++;
        }
    }

}
