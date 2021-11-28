/* Driver for Configuration */

#include "../Configuration/Configuration.h"

int main() {
    setConfigFile();
    loadConfig();
    if (mapLength != 20) {
        printf("Map length not set \n");
        return -1;
    }
    // map test
    if (map[0] != '.'){
        printf("Map properties not set \n");
        return -1;
    }
    //max dice role
    if (maxDiceRole != 10 ) {
        printf("Map properties not set \n");
        return -1;
    }
    for (int i = 0; i < teleportLength; i++) {
        printf("in : %d , out : %d \n", teleporters[i].inPoint, teleporters[i].outPoint);
    }
    printf("Pass all test,gratio!\n");

    printf("Max Dice Roll : %d\n", maxDiceRole);
    printf("Map Length : %d\n", mapLength);
    displayMap();

    printf("\nInspect Map :\n");
    for (int i = 1; i <= mapLength; i++) {
        inspectMap(i);
    }
    
    freeTeleporters();

    return 0;
}