#include "Configuration.h"

int maxDiceRole = 0;
char map[255];
int mapLenght = 0;
int teleportLenght = 0;

int converter(char pep){
    return pep - '0';
}

void setConfigFile(){
    printf("Remember to add .txt in the end, user! \n");
    printf("Configuration file name : ");
    scanf("%s", fileName);
    printf("\nLoading configuration...\n");
}

void loadConfig() {
    STARTKATA(1);
    int line = 1;
    int index = 0;
    while (!EndKata) {
        if (line == 1) {
            setMapLenght(atoi(CKata.TabKata));
        } 
        else if (line == 2) {
            setMap(CKata);
        }
        else if( line == 3) {
            setMaxDiceRole(atoi(CKata.TabKata));
        }
        else if( line == 4) {
            teleportLenght = atoi(CKata.TabKata);
            allocateTeleportersLenght(teleportLenght);
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

void setMapLenght(int lenght) {
    mapLenght = lenght;
}

void setMap(Kata mapConfig) {
    for (int i = 0; i < mapConfig.Length; i++){
        map[i] = mapConfig.TabKata[i];
    }
}

void displayMap() {
    printf("Game map :\n");
    printf("%s\n",map);
}

void inspectMap(int point) {
    point -= 1;
    if (map[point] == '#') {
        printf("Player can't move to this point\n");
    } else if (map[point] == '.') {
        boolean foundtp = false;
        for (int i = 0; i < teleportLenght; i++){
            if (point+1 == teleporters[i].inPoint) {
                foundtp = true;
                printf("There is teleporter from : %d to : %d \n", teleporters[i].inPoint, teleporters[i].outPoint);
            }
        }
        if(!foundtp) {
            printf("There is no teleporter in : %d \n", point+1);
        }
    }
}

void allocateTeleportersLenght(int lenght){
    teleporters = calloc(lenght, sizeof(teleport));
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