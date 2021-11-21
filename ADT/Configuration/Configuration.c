#include "Configuration.h"

//char map[255];
//int mapLength = 0;
int maxDiceRole = 0;
Map gameMap;
TabTeleport gameTeleport;
char fileName[];

int converter(char pep){
    return pep - '0';
}
//void setTeleporter(int index, int in, int out);

void setConfigFile(){
    printf("Remember to add .txt in the end, user! \n");
    printf("Configuration file name : ");
    scanf("%s", &fileName);
    printf("\nLoading configuration...\n");
}

void loadConfig() {
    CreateEmptyMap(&gameMap);
    CreateEmptyTabTP(&gameTeleport);
    
    STARTKATA(1);

    int line = 1;
    int index = 1;
    while (!EndKata) {
        if (line == 1) {
            SetNeffMap(&gameMap, atoi(CKata.TabKata));
        } 
        else if (line == 2) {
            setMap(CKata);
        }
        else if (line == 3) {
            setMaxDiceRole(atoi(CKata.TabKata));
        }
        else if (line == 4) {
            //allocateTeleportersLength(atoi(CKata.TabKata));
            SetNeffTP(&gameTeleport, atoi(CKata.TabKata));
        }
        else {
            int in = converter(CKata.TabKata[0]);
            int out = converter(CKata.TabKata[2]);
            //setTeleporter(index, in, out);
            SetElTP(&gameTeleport, index, in, out);
            index ++;
        }
        line++;
        ADVKATA();
    }
    printf("Configuration has been loaded successfully\n");
}

/*void setMapLength(int length) {
    //mapLength = length;
    gameMap.Neff = length;
}*/

void setMap(Kata mapConfig) {
    for (int i = 1; i <= mapConfig.Length; i++){
        //map[i] = mapConfig.TabKata[i];
        //gameMap.TI[i] = mapConfig.TabKata[i];
        SetElMap(&gameMap, i, mapConfig.TabKata[i]);
    }
}

void setMaxDiceRole(int value){
    maxDiceRole = value;
}

/*void allocateTeleportersLength(int length){
    teleporters = calloc(length, sizeof(teleport));
}*/

/*void freeTeleporters(){
    free(teleporters);
}*/

/*void setTabTPLength(int length) {
    //mapLength = length;
    gameTeleport.Neff = length;
}*/

/*void setTeleporter(int index, int in, int out) {
    gameTeleport.TI[index].in = in;
    gameTeleport.TI[index].out = out;
    //teleport temp;
    //temp.startPoint = start;
    //temp.endPoint = end;
    //teleporters[index] = temp;
}*/