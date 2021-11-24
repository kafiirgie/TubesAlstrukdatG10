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
    skill playerskills;
    int temp;
    createEmptySkill(&playerskills);
    temp = getRandomSkill();
    insertSkill(&playerskills, temp);
    thePlayer->skills = playerskills;
    //set player buff
    thePlayer->buff[0] = false; //Buff Imunitas Teleport
    thePlayer->buff[1] = false; //Buff Cermin Pengganda
    thePlayer->buff[2] = false; //Buff Senter Pembesar Hoki
    thePlayer->buff[3] = false; //Buff Senter Pengecil Hoki
}

void playerRoleDice(player *thePlayer, int maxDice) {
    // Get move value
    int move = 0;
    int maxRoll = maxDice;
    int minRoll = 1;
    if (thePlayer->buff[2]) {
        minRoll = div(maxDice, 2).quot;
    } else if (thePlayer->buff[3]) {
        maxRoll = div(maxDice, 2).quot;
    }
    move = rand() % maxRoll + minRoll;
    // Move player
    boolean isPlayerCanMoveForward = isPlayerCanMove(move,thePlayer->position,true);
    boolean isPlayerCanMoveBackward = isPlayerCanMove(move,thePlayer->position,false);
    if (isPlayerCanMoveForward && isPlayerCanMoveBackward) {
        printf("Player can move forward %d step\n",move);
        printf("Player can move backward %d step\n",move);
        printf("Type 1 to perform move forward\n");
        printf("Type 2 to perform move forward\n");
        // if (isPlayerCanMoveForward) { 
        //     printf("Player can move forward %d step\n",move);
        //     printf("Type 1 to perform move forward\n");
        // }
        // if (isPlayerCanMoveBackward) { 
        //     printf("Player can move backward %d step\n",move);
        //     printf("Type 2 to perform move forward\n");
        // }
        //printf("Type '1' to move forward or type '2' to move backward\n");
        printf("Input : ");
        int selection = playerOption();
        if (selection == 1) {
            thePlayer->position += move;
        } 
        if (selection == 2) {
            thePlayer->position -= move;
        }
    } else if (isPlayerCanMoveForward && !isPlayerCanMoveBackward) {
        printf("Player can only move forward %d step\n",move);
        thePlayer->position += move;
    } else if (!isPlayerCanMoveForward && isPlayerCanMoveBackward) {
        printf("Player can only move backward %d step\n",move);
        thePlayer->position -= move;
    } else {
        printf("Player can't move\n");
    }
    printf("Now your position is : %d\n", thePlayer->position);
    // Check teleporter
    if (isCanTeleport(thePlayer)) {
        printf("There is teleporter in your current position.\n");
        if (thePlayer->buff[0]) {
            printf("You have teleport immunity.\n");
            printf("Type '1' to use teleport immunity or type '0' if not\n");
            printf("Input : ");
            int selection = playerOption();
            if (selection == 1) {
                printf("You are using teleport immunity\n");
            } else if (selection == 0) {
                playerTeleport(thePlayer);
            }
        } else {
            printf("You don't have teleport immunity.\n");
            playerTeleport(thePlayer);
        }
    } else {
        printf("There is no teleporter in your current position.\n");
    }
}

/*void playerTeleport(player *thePlayer, int outPoint) {
    thePlayer->position = outPoint;
}*/

void playerTeleport(player *thePlayer) {
    for (int i = 0; i < teleportLenght; i++){
        if (thePlayer->position+1 == teleporters[i].inPoint) {
            //playerTeleport(thePlayer, teleporters[i].outPoint);
            thePlayer->position = teleporters[i].outPoint-1;
            printf("Teleporting player from : %d to : %d \n", teleporters[i].inPoint, teleporters[i].outPoint);
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

/*void playerUseSkill(player *thePlayer) {
    printSkill(thePlayer->skills);
    printf("Insert your input : ");
    int num = playerOption();
    if (num > 0) {
        //get skill id
        int index = getIdSkill(thePlayer->skills, num);
        //use skill
        switch (index) {
            case 1: useSkill1(thePlayer); break;
            case 2: useSkill2(thePlayer); break;
            case 3: useSkill3(thePlayer); break;
            case 4: useSkill4(thePlayer); break;
            case 5: useSkill5(thePlayer); break;
            case 6: useSkill6(thePlayer); break;
            case 7: useSkill7(thePlayer); break;
            case 8: useSkill8(thePlayer); break;
            default: break;
        }
        //delete skill
        deleteSkill(&thePlayer->skills, num);
        if (thePlayer->buff[1]) {
            // Get 2 new skill
            int temp;
            temp = getRandomSkill();
            insertSkill(&thePlayer->skills, temp);
            printf("please wait..."); sleep(5);
            temp = getRandomSkill();
            insertSkill(&thePlayer->skills, temp);
        }
    } else if (num < 0) {
        //delete skill
        num *= -1;
        deleteSkill(&thePlayer->skills, num);
    } else { //num == 0
        printf("Player don't use or remove skills\n");
    }
}*/

int getIdSkill(skill LS, int num) {
    int x, i;
    address P;
    i = 1;
    P = First(LS);
    while (i < num) {
        P = Next(P);
        i++;
    }
    x = Info(P);
    return x;
}

/*void useSkill1(player *thePlayer) {
    // Set buff player "Imunitas Teleport" into true
    thePlayer->buff[0] = true;
    printf("Congrats, you got new buff!!\n");
    printf("New buff : Imunitas Teleport\n");
    // Set implementation in playerTeleport!!
}
void useSkill2(player *thePlayer) {
    // UNDER DEVELOPMENT
}
void useSkill3(player *thePlayer) {
    // UNDER DEVELOPMENT
}
void useSkill4(player *thePlayer) {
    if (countSkill(thePlayer->skills) <= 9) {
        // Set buff player "Cermin Pengganda" into true
        thePlayer->buff[1] = true;
        printf("Congrats, you got new buff!!\n");
        printf("New buff : Cermin Pengganda\n");
    } else {
        printf("Sorry, you can't use this skill now, please remove some skills.\n");
    }
}
void useSkill5(player *thePlayer) {
    // Set buff player "Senter Pembesar Hoki" into true
    thePlayer->buff[2] = true;
    printf("Congrats, you got new buff!!\n");
    printf("New buff : Senter Pembesar Hoki\n");
    // Set implementation in role dice!!
}
void useSkill6(player *thePlayer) {
    // Set buff player "Senter Pengecil Hoki" into true
    thePlayer->buff[3] = true;
    printf("Congrats, you got new buff!!\n");
    printf("New buff : Senter Pengecil Hoki\n");
    // Set implementation in role dice!!
}
void useSkill7(player *thePlayer1, player *thePlayer2) {
    // UNDER DEVELOPMENT
}
void useSkill8(player *thePlayer) {
    printf("!!! This skill was broken !!!\n");
    printf("You can't use this skill.\n");
}*/

void resetPlayerBuff(player *thePlayer) {
    thePlayer->buff[1] = false;
    thePlayer->buff[2] = false;
    thePlayer->buff[3] = false;
}

void showPlayerBuff(player *thePlayer) {
    int i = 1;
    if (thePlayer->buff[0]) {
        printf("%d. Imunitas Telport", i);
        i++;
    }
    if (thePlayer->buff[1]) {
        printf("%d. Cermin Pengganda", i);
        i++;
    }
    if (thePlayer->buff[2]) {
        printf("%d. Senter Pembesar Hoki", i);
        i++;
    }
    if (thePlayer->buff[3]) {
        printf("%d. Senter Pengecil Hoki", i);
        i++;
    }
}