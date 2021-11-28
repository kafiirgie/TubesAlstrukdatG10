#include "Configuration.h"

int maxDiceRole = 0;
char map[255];
int mapLength = 0;
int teleportLength = 0;

int converter(char pep){
    return pep - '0';
}

void setConfigFile(){
    printf("\nRemember to add .txt in the end, user! \n");
    printf("Configuration file name : ");
    scanf("%s", fileName);
}

void loadConfig() {
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
            teleportLength = atoi(CKata.TabKata);
            allocateTeleportersLength(teleportLength);
        } else {
            int in = 0;
            int out = 0;
            int after_space = 0;
            for (int i = 0; i < CKata.Length; i++) {
                // Check is before or after space
                if (CKata.TabKata[i] == ' ') {
                    after_space = 1;
                }
                // Set char before space as in value
                if (after_space == 0 && CKata.TabKata[i] != ' ') {
                    in *= 10;
                    in += converter(CKata.TabKata[i]);
                // Set char after space as out value
                } else  if (after_space == 1 && CKata.TabKata[i] != ' ') {
                    out *= 10;
                    out += converter(CKata.TabKata[i]);
                }
            }
            setTeleporter(index, in, out);
            index++;
        }
        line++;
        ADVKATA();
    }
    printf("Configuration has been loaded successfully\n");
}

void setMapLength(int length) {
    mapLength = length;
}

void setMap(Kata mapConfig) {
    for (int i = 0; i < mapConfig.Length; i++){
        map[i] = mapConfig.TabKata[i];
    }
}

void displayMap() {
    printf("\nGAME MAP ========================\n");
    printf("%s\n",map);
}

void inspectMap(int point) {
    point -= 1;
    //Petak terlarang
    if (map[point] == '#') {
        printf("Player can't move to this point\n");
    } else if (map[point] == '.') {
        //Petak dengan teleporter
        boolean foundtp = false;
        for (int i = 0; i < teleportLength; i++){
            if (point+1 == teleporters[i].inPoint) {
                foundtp = true;
                printf("There is teleporter from %d to %d \n", teleporters[i].inPoint, teleporters[i].outPoint);
                break;
            }
        }
        //Petak kosong
        if(!foundtp) {
            printf("There is no teleporter in : %d \n", point+1);
        }
    }
}

void allocateTeleportersLength(int length){
    teleporters = calloc(length, sizeof(teleport));
}

void freeTeleporters(){
    free(teleporters);
}

void setTeleporter(int index, int in, int out) {
    teleport temp;
    temp.inPoint = in;
    temp.outPoint = out;
    teleporters[index] = temp;
}

void setMaxDiceRole(int value){
    maxDiceRole = value;
}