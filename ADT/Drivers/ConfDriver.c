#include "../Configuration/Configuration.h"

int main(int argc, char **argv) {
    //test configuration file
    sscanf("testConf.txt","%s",fileName);
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
    if (teleporters[0].startPoint != 3){
        printf("Teleporter gone wrong \n");
        printf("Teleporter start point %d",teleporters[0].startPoint);
        return -1;
    }
    freeTeleporters();
    printf("Pass all test,gratio!\n");
    return 0;
}