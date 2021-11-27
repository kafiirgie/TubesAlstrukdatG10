#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Player.h"
#include "../Configuration/Configuration.h"

void setPlayer(player *thePlayer) {
    //set player position
    thePlayer->position = 0;
    //set player name
    scanf("%s", thePlayer->name);
    //set player skills
    createEmptySkill(&thePlayer->skills);
    //skill playerskills;
    //int temp;
    //createEmptySkill(&playerskills);
    //temp = getRandomSkill();
    //insertSkill(&playerskills, temp);
    //thePlayer->skills = playerskills;
    //set player buff
    thePlayer->buff[0] = false; //Buff Imunitas Teleport
    thePlayer->buff[1] = false; //Buff Cermin Pengganda
    thePlayer->buff[2] = false; //Buff Senter Pembesar Hoki
    thePlayer->buff[3] = false; //Buff Senter Pengecil Hoki
}

int getDiceValue(int minRoll, int maxRoll) {
    return (rand() % maxRoll + minRoll);
}

void playerRollDice(player *thePlayer, int maxDice) {
    // Get move value
    int move;
    int maxRoll = maxDice;
    int minRoll = 1;
    if (thePlayer->buff[2]) {
        minRoll = div(maxDice, 2).quot;
    } else if (thePlayer->buff[3]) {
        maxRoll = div(maxDice, 2).quot;
    }
    move = getDiceValue(minRoll, maxRoll);
    // Move player
    boolean isPlayerCanMoveForward = isPlayerCanMove(move,thePlayer->position,true);
    boolean isPlayerCanMoveBackward = isPlayerCanMove(move,thePlayer->position,false);
    if (isPlayerCanMoveForward && isPlayerCanMoveBackward) {
        printf("%s can move forward %d step.\n", thePlayer->name, move);
        printf("%s can move backward %d step.\n", thePlayer->name, move);
        printf("Type 1 to perform move forward.\n");
        printf("Type 2 to perform move backward.\n");
        printf("Input : ");
        int selection = playerOption();
        if (selection == 1) {
            thePlayer->position += move;
        } 
        else if (selection == 2) {
            thePlayer->position -= move;
        }
        else {
            printf("Wrong input, will automagically move forward.\n");
            thePlayer->position += move;            
        }
    } else if (isPlayerCanMoveForward && !isPlayerCanMoveBackward) {
        printf("%s can only move forward %d steps.\n", thePlayer->name, move);
        thePlayer->position += move;
    } else if (!isPlayerCanMoveForward && isPlayerCanMoveBackward) {
        printf("%s can only move backward %d steps.\n", thePlayer->name, move);
        thePlayer->position -= move;
    } else {
        printf("%s can't move %d steps.\n", thePlayer->name, move);
    }
    printf("%s current position is on : %d.\n", thePlayer->name, thePlayer->position+1);
    // Check teleporter
    playerTeleport(thePlayer);
}

void playerTeleport(player *thePlayer) {
    // Check teleporter
    if (isCanTeleport(thePlayer)) {
        printf("There is teleporter in %s's current position.\n", thePlayer->name);
        if (thePlayer->buff[0]) {
            printf("%s have teleport immunity.\n", thePlayer->name);
            printf("Type 1 to use teleport immunity.\n");
            printf("Type 0 to not use teleport immunity.\n");
            printf("Input : ");
            int selection = playerOption();
            if (selection == 1) {
                printf("%s use teleport immunity.\n", thePlayer->name);
                printf("%s isn't teleporting.\n", thePlayer->name);
                //Remove immunity teleport buff
                thePlayer->buff[0] = false;
            } else if (selection == 0) {
                runTeleport(thePlayer);
            }
        } else {
            printf("%s don't have teleport immunity.\n", thePlayer->name);
            runTeleport(thePlayer);
        }
    } else {
        printf("There is no teleporter in %s's current position.\n", thePlayer->name);
    }
}

void runTeleport(player *thePlayer) {
    for (int i = 0; i < teleportLenght; i++){
        if (thePlayer->position+1 == teleporters[i].inPoint) {
            thePlayer->position = teleporters[i].outPoint-1;
            printf("Teleporting %s from : %d to : %d.\n", thePlayer->name, teleporters[i].inPoint, teleporters[i].outPoint);
            break;
        }
    }
}

boolean isCanTeleport(player *thePlayer) {
    boolean val = false;
    for (int i = 0; i < teleportLenght; i++){
        if (thePlayer->position+1 == teleporters[i].inPoint) {
            val = true;
            break;
        }
    }
    return val;
}

boolean isPlayerCanMove(int change, int position, boolean isUpward) {
    if (isUpward) {
        return map[position+change] != '#' && (position+change < mapLenght);
    } else {
        return map[position-change] != '#' && (position-change >= 0);
    }
}

int playerOption() {
    int selection;
    scanf("%d", &selection);
    printf("\n");
    return selection;
}

void resetPlayerBuff(player *thePlayer) {
    thePlayer->buff[1] = false;
    thePlayer->buff[2] = false;
    thePlayer->buff[3] = false;
}

void showPlayerBuff(player *thePlayer) {
    if (!thePlayer->buff[0] && !thePlayer->buff[1] && !thePlayer->buff[2] && !thePlayer->buff[3]) {
        printf("Player don't have any buff yet.\n");
    } else {
        int i = 1;
        if (thePlayer->buff[0]) {
            printf("%d. Imunitas Telport\n", i);
            i++;
        }
        if (thePlayer->buff[1]) {
            printf("%d. Cermin Pengganda\n", i);
            i++;
        }
        if (thePlayer->buff[2]) {
            printf("%d. Senter Pembesar Hoki\n", i);
            i++;
        }
        if (thePlayer->buff[3]) {
            printf("%d. Senter Pengecil Hoki\n", i);
            i++;
        }    
    }
}

void showPlayerPosition(int position) {
    for (int i = 0; i < mapLenght; i++) {
        if (i == position) {
            printf("%c",'*');
        } else {
            printf("%c",map[i]);
        }
    }
    printf(" %d \n", position+1);
}