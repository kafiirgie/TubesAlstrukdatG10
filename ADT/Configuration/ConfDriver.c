#include "Configuration.h"

int main() {
    //sscanf("config.txt","%s",fileName);
    setConfigFile();
    loadConfig();
    if (mapLenght != 20) {
        printf("Map lenght not set \n");
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
    for (int i = 0; i < teleportLenght; i++) {
        printf("in : %d , out : %d \n", teleporters[i].inPoint, teleporters[i].outPoint);
    }
    freeTeleporters();
    printf("Pass all test,gratio!\n");

    printf("Max Dice Roll : %d\n", maxDiceRole);
    printf("Map Length : %d\n", mapLenght);
    printf("Game map :\n");
    printf("%s\n", map);

    return 0;
}