#include "Configuration.h"

int mapLength = 0;
int maxDiceRole = 0;
char map[255];

int converter(char pep){
    return pep - '0';
}

void setMap(Kata mapConfig) {
    for (int i = 0; i <= mapConfig.Length; i++){
        map[i] = mapConfig.TabKata[i];
    }
}
void setConfigFile(){
    printf("Remember to add .txt in the end, user! \n");
    printf("Configuration file name : ");
    scanf("%s", fileName);
    printf("\nLoading configuration...\n");
}
void loadConfig() {
    //int flag = 0;
    STARTKATA(1);

    int line = 1;
    int index = 0;
    while (!EndKata) {
        if (line == 1) {
            setMapLength(atoi(CKata.TabKata));
        } 
        else if (line == 2) {
            setMap(CKata);
        }
        else if( line == 3) {
            setMaxDiceRole(atoi(CKata.TabKata));
        }
        else if( line == 4) {
            allocateTeleportersLength(atoi(CKata.TabKata));
        } else {
            int start = converter(CKata.TabKata[0]);
            int end = converter(CKata.TabKata[2]);
            setTeleporter(index, start, end);
            index ++;
        }
        line++;
        ADVKATA();
    }
    printf("Configuration has been loaded successfully\n");
}

void setMapLength(int length) {
    mapLength = length;
}
void allocateTeleportersLength(int length){
    teleporters = calloc(length, sizeof(teleport));
}
void freeTeleporters(){
    free(teleporters);
}

void setTeleporter(int index, int start, int end) {
    teleport temp;
    temp.startPoint = start;
    temp.endPoint = end;
    teleporters[index] = temp;
}

void setMaxDiceRole(int value){
   maxDiceRole = value;
}