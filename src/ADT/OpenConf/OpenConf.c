#include "OpenConf.h"
#include <stdlib.h>
#include <stdio.h>
#include "mesin_kata.h"



//MARK: TELEPORT RELATED shits
void allocateTeleportPlacesLenght(int lenght) {
    teleportPlaces = calloc(lenght, sizeof(teleporters));
}
void assignTeleportPlaces(void) {
    // example : teleportPlaces[0].start = 0;
}

void freeTeleportPlaces(void) {
    free(teleportPlaces);
}

//
void loadConfig() {
    int line = 1;
    int index = 0;
    STARTKATA();
    while (!EndKata) {
        if (line == 1) {
            // get map lenght
            mapLenght = atoi(CKata.TabKata);
        }
        else if (line == 2) {
            // get Map data
            //iterate 1 per 1, base on the map lenght
            for (int i = 0;i < mapLenght; i++){
                map[i] = CKata.TabKata[i];
            }
        }
        else if (line == 3) {
            //get max dice role
            maxRole = atoi(CKata.TabKata);
        }
        else if (line == 4) {
            allocateTeleportPlacesLenght(atoi(CKata.TabKata));
        } else {
            // ADD Start Point
             teleportPlaces[index].start = atoi(CKata.TabKata);
             ADVKATA();
             // ADD End point
             teleportPlaces[index].end = atoi(CKata.TabKata);
             index++;
        }
        line ++; 
        ADVKATA();
    }
}


// PERLU DIPERBAIKIN!
// void loadConfig() {
//     // printf("DONT FORGET TO ADD '.' AT THE END OF THE LINE!\n");
//     // printf("Example : config.txt\n");
//     // printf("Configuration file name : \n");
//     // char configName[255];
//     // scanf("%s",configName);
//     // FILE * fp;
//     int line = 0;
//     int index = 0;
//     //MARK: Bagian ini perlu perbaikan
//     // STARTKATA();
//     // if (EndKata) {
//     //     return;
//     // }
//     //fp = fopen (configName, "r");
//     //
//     while (!feof(fp)) {
//         line ++;
//         if (line == 1) {
//             mapLenght = atoi(fgetc(fp));
//         } else if (line == 2) {
//             //iterate i per 1
//         } else if (line == 3) {
//             maxRole = atoi(fgetc(fp));
//         } else if (line == 4) {
//             allocateTeleportPlacesLenght(atoi(fgetc(fp)));
//         } else {
//             //MARK: Work on Progress
//             //assignTeleportPlaces();
//             // ADD Start Point
//             teleportPlaces[index].start = 0;
//             // ADD End point
//             teleportPlaces[index].end = 0;
//             index++;
//         }
//     }

// }
