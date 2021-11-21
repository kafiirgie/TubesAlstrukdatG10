#include "Configuration.h"

int main() {
    setConfigFile();
    loadConfig();
    if (gameMap.Neff != 20) {
        printf("Map length not set \n");
        return -1;
    }
    // map test
    if (gameMap.TI[1] != '.'){
        printf("Map properties not set \n");
        return -1;
    }
    //max dice role
    if (maxDiceRole != 10 ) {
        printf("Map properties not set \n");
        return -1;
    }
    if (gameTeleport.TI[1].in != 3){
        printf("Teleporter gone wrong \n");
        printf("Teleporter start point %d", gameTeleport.TI[1].in);
        return -1;
    }
    //freeTeleporters();
    printf("Pass all test,gratio!\n");

    printf("Max Dice Roll : %d\n", maxDiceRole);
    printf("Map : ");
    DisplayMap(gameMap);
    printf("\n");


    return 0;
}