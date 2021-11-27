#include "Game.h"
#include "../../ADT/Configuration/Configuration.h"
#include "../../ADT/Progress/Progress.h"
#include "../../ADT/MesinKarKat/mesin_kata.h"
#include "../../ADT/Round/Round.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int playersPlaying = 0;
boolean isEndGame = false;
roundData data;
roundData datadel;

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void delay(int number_of_seconds) {
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void loading(int input_seconds) {
    int i;
    //printf("\nloading ");
    for (i = 0; i < input_seconds; i++) {
        // delay of one second
        delay(1);
        printf(".");
    }
    printf("\n");
}

void showPlayerCommand() {
    printf("\n---------------\n");
    printf("Your commands : \n");
    printf("[1] Roll Dice\n"); //roll
    printf("[2] Use Skill\n"); //skill
    printf("[3] Show Buff\n"); //buff
    printf("[4] Inspect Map\n"); //inspect
    printf("[5] Show Position\n"); //map
    printf("[6] Undo\n"); //undo
    printf("[7] End Turn\n"); //endturn
    printf("[0] Exit Game\n");
}

void GameView(int opsi) {
    if (opsi == 1) { //New Game
        NewGame();
    } else { //Load Game
        LoadGame();
    }
    setConfigFile();
    printf("\nLoading configuration"); loading(3);
    loadConfig();

    displayGameRule();
    // click enter to continue type of shit
    printf("\nLet's Start The Game!\n");
    loading(3);
    clear();
    displayMap(); printf("\n");
    StartGame();
    ExitGame();
}

void NewGame() {
    printf("Starting game"); loading(3);
    printf("Hi, Welcome to MOBITANGGA!!\n");
    printf("How many players are playing today (minimum 2, maximum 4) ? : ");
    scanf("%d", &playersPlaying);
    //Setup how many players are playing
    if (playersPlaying < 2 || playersPlaying > 4) {
        printf("Looks like you put the wrong number, re-starting the game... \n");
        NewGame(); //got infinite loop!!
    } else {
        for (int i = 0; i < playersPlaying; i++) {
            player temp;
            printf("\nPlayer %d name : ",i+1);
            setPlayer(&temp);
            data.players[i] = temp;
        }
    }
}

void LoadGame() {
//     progressName();
//     loadProgress();
//     int line = 1;
//     int idx = 0;
//     while (!EndKata) {
//         if (line == 1) {
//             sscanf(fileName, "%s", CKata.TabKata);
//         }
//         else if (line == 2) {
//             playersPlaying = atoi(CKata.TabKata);
//         }
//         else {
// //WIP
//         }
//     }
}

// THE GAME
void StartGame() {
    int round = 0;
    int opsi = -9;
    // boolean isRedo = false;
    // stack rondenya
    Ronde rounde;
    //
    CreateRondeEmpty(&rounde);
    data.rondeKeberapa = round;
    round++;
    PushRonde(&rounde, data);
    boolean exitGame = false;
    
    //Loop per ronde
    clear();
    while (!isEndGame) {
        //clear();
        data = CurrRonde(rounde);
        data.rondeKeberapa = round;
        boolean isUndo = false;
        boolean isEndRound = false;
        int i = 0;
        while (!isEndRound) {
        //for (int i = 0; i < playersPlaying; i++) {
            //clear();
            printf("ROUND %d =========================\n", data.rondeKeberapa);
            printf("It's %s turn! \n",data.players[i].name);
            //Generate random skill
            insertSkill(&data.players[i].skills, getRandomSkill());
            //Show player posiiton in map
            printf("Players current position :\n");
            for (int j = 0; j < playersPlaying; j++) {
                printf("%d. %s : ", j+1, data.players[j].name);
                showPlayerPosition(data.players[j].position);
            }
            //Loop untill player choose end turn
            boolean didRoleDice = false;
            boolean isMoved = false;
            boolean isEndTurn = false;
            while (!isEndTurn) { 
                //Show player command
                showPlayerCommand();
                printf("Select your move : ");
                opsi = playerOption();
                if (opsi == 1) {
                    if (isMoved) {
                        printf("Player can't roll dice again!\n");
                    } else {
                        int positionInitial = data.players[i].position; 
                        playerRollDice(&data.players[i],maxDiceRole);
                        didRoleDice = true;
                        int positionFinal = data.players[i].position;
                        isMoved = positionInitial != positionFinal; 
                    }
                }
                else if (opsi == 2) {
                    if (isMoved) {
                        printf("Player can't use skill, already roll dice!\n");
                    } else {
                        playerUseSkill(i, playersPlaying);
                    }
                }
                else if (opsi == 3) {
                    showPlayerBuff(&data.players[i]);
                }
                else if (opsi == 4) {
                    int point;
                    printf("Insert map point that you want to inspect : ");
                    scanf("%d", &point);
                    inspectMap(point);
                }
                else if (opsi == 5) {
                    printf("Players current position :\n");
                    for (int j = 0; j < playersPlaying; j++) {
                        printf("%d. %s : ", j+1, data.players[j].name);
                        showPlayerPosition(data.players[j].position);
                    }
                }
                else if (opsi == 6) {
                    /*if (data.rondeKeberapa == 1 || data.rondeKeberapa == 2){
                        printf("Starting game state at end of round 1 \n");
                        // redo the whole thing
                        // isRedo = true;
                        // exitGame = true;
                        break;
                    } else {
                        PopRonde(&rounde,&data);
                        data = CurrRonde(rounde);
                    }*/
                    // undo
                    printf("checkpoint undo 1\n");
                    isUndo = true;
                    int r = data.rondeKeberapa;
                    while (r > 1) {
                        printf("Current round is %d.\n", r);
                        printf("Game will start at end of round %d.\n", r-1);
                        printf("Type 1 if player want to undo again.\n");
                        printf("Type 0 if not.\n");
                        printf("Input : ");
                        int selection = playerOption();
                        if (selection == 1) {
                            PopRonde(&rounde, &datadel);
                            r -= 1;
                        } else if (selection == 0) {
                            break;
                        }
                    }
                    if (r == 1) {
                        printf("Current round is %d.\n", r);
                        printf("Game will start at end of round %d.\n", r-1);
                    }
                    isEndTurn = true;
                    isEndRound = true;
                    loading(3);
                } else if (opsi == 7) {
                    // end turn
                    if (isMoved) {
                        isEndTurn = true;
                    } else {
                        printf("Player can't end turn now, player has not moved yet.\n");
                    }
                }
                else if (opsi == 8) {
                    // hidden feature aka buat testing
                    data.players[i].position = mapLenght-1;
                    didRoleDice = true;
                }
                else if (opsi == 0) {
                    // exit game
                    exitGame = true;
                    isEndTurn = true;
                }
            }
            printf("checkpoint end turn\n");
            if (exitGame) break;
            isEndGame = checkIsEndGame(data.players[i].position);
            if (isEndGame) break;
            i++;
            if (i >= playersPlaying) isEndRound = true;
            //PushRonde(&rounde, data);
            //didRoleDice = false;
            // if (isEndGame) { 
            //     printf("end game %d",data.players[i].position);
            // } else {
            //     printf("not end ganme %d",data.players[i].position);
            // }
        }
        // redo game
        // if (isRedo) StartGame();

        // end game
        printf("checkpoint end round\n");
        if (!isUndo) {
            PushRonde(&rounde, data);
            round++;
        }
        if (exitGame) break;
    }
    free(rounde.TOP);
}

void ExitGame() {
    freeTeleporters();
    if (isEndGame == 1) {
        //sort user based on position
        rankPlayers();
        printf("Congratulation, you've reach the end game!\n");
        printf("Player ranks : \n");
        displayRank();
    } else {
        // Save progress
        printf("Saving progress.....\n");
    }
}

void displayGameRule() {
// display game rule
}

boolean checkIsEndGame(int position) {
    return position + 1 >= mapLenght;
}

void rankPlayers() {
    int i, j;
    player key;
    for (i = 1; i < playersPlaying; i++) {
        key = data.players[i];
        j = i - 1;
        while (j >= 0 && data.players[j].position < key.position) {
            data.players[j + 1] = data.players[j];
            j = j - 1;
        }
        data.players[j + 1] = key;
    }
}

void displayRank() {
    for (int i = 0; i < playersPlaying; i++) {
       printf("Rank #%d : %s \n",i+1,data.players[i].name);
    }
}

/*void showPlayerPosition(int position) {
    for (int i = 0; i < mapLenght; i++) {
        if (i == position) {
            printf("%c",'*');
        } else {
            printf("%c",map[i]);
        }
    }
    printf(" %d \n", position+1);
}*/

/*void displayMap() {
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
}*/

void playerUseSkill(int idPlayer, int countPlayersPlaying) {
    printSkill(data.players[idPlayer].skills);
    if (!IsEmpty(data.players[idPlayer].skills)) {
        printf("Insert your input : ");
        int num = playerOption();
        if (num > 0) {
            //get skill id
            int index = getIdSkill(data.players[idPlayer].skills, num);
            //use skill
            switch (index) {
                case 1: useSkill1(idPlayer); break;
                case 2: useSkill2(idPlayer, countPlayersPlaying); break;
                case 3: useSkill3(idPlayer, countPlayersPlaying); break;
                case 4: useSkill4(idPlayer); break;
                case 5: useSkill5(idPlayer); break;
                case 6: useSkill6(idPlayer); break;
                case 7: useSkill7(idPlayer, countPlayersPlaying); break;
                case 8: useSkill8(idPlayer); break;
                default: break;
            }
            //delete skill
            deleteSkill(&data.players[idPlayer].skills, num);
            if (data.players[idPlayer].buff[1]) {
                // Get 2 new skill
                int temp;
                temp = getRandomSkill();
                insertSkill(&data.players[idPlayer].skills, temp);
                printf("please wait..."); delay(5);
                temp = getRandomSkill();
                insertSkill(&data.players[idPlayer].skills, temp);
                // Remove player buff
                data.players[idPlayer].buff[1] = false;
            }
        } else if (num < 0) {
            //delete skill
            num *= -1;
            deleteSkill(&data.players[idPlayer].skills, num);
            printf("Delete skill has done successfully.\n");
        } else { //num == 0
            printf("Player don't use or remove skills.\n");
        }
    }
}

void useSkill1(int idPlayer) {
    if (data.players[idPlayer].buff[0]) {
        printf("Player can't use this skill, player already got this buff.\n");
    } else {
        // Set buff player "Imunitas Teleport" into true
        data.players[idPlayer].buff[0] = true;
        printf("Congrats, you got new buff!!\n");
        printf("New buff : Imunitas Teleport\n");   
    }
}
void useSkill2(int idPlayer, int countPlayersPlaying) {
    printf("You can move other players backward.\n");
    printf("Players :\n");
    for (int i = 0; i < countPlayersPlaying; i++) {
        if (i != idPlayer) {
            printf("%d. %s\n", i+1, data.players[i].name);
        }
    }
    printf("Select id Player : ");
    int idOpponent = playerOption()-1;
    int moveOpponent = getDiceValue(1, maxDiceRole);
    if (isPlayerCanMove(moveOpponent, data.players[idOpponent].position, false)) {
        // Move opponent player backward
        data.players[idOpponent].position -= moveOpponent;
        printf("%s is moved backward %d steps.\n", data.players[idOpponent].name, moveOpponent);
        printf("Now, %s position is on : %d.\n", data.players[idOpponent].name, data.players[idOpponent].position+1);
        // Check teleporter
        playerTeleport(&data.players[idOpponent]);
    } else {
        printf("%s can't move backward %d steps.\n", data.players[idOpponent].name);
    }
}
void useSkill3(int idPlayer, int countPlayersPlaying) {
    printf("You can move other players forward.\n");
    printf("Players :\n");
    for (int i = 0; i < countPlayersPlaying; i++) {
        if (i != idPlayer) {
            printf("%d. %s\n", i+1, data.players[i].name);
        }
    }
    printf("Select id Player : ");
    int idOpponent = playerOption()-1;
    int moveOpponent = getDiceValue(1, maxDiceRole);
    if (isPlayerCanMove(moveOpponent, data.players[idOpponent].position, true)) {
        // Move opponent player forward
        data.players[idOpponent].position += moveOpponent;
        printf("%s is moved forward %d steps.\n", data.players[idOpponent].name, moveOpponent);
        printf("Now, %s position is on : %d.\n", data.players[idOpponent].name, data.players[idOpponent].position+1);
        // Check teleporter
        playerTeleport(&data.players[idOpponent]);
    } else {
        printf("%s can't move forward %d steps.\n", data.players[idOpponent].name);
    }
}
void useSkill4(int idPlayer) {
    if (data.players[idPlayer].buff[1]) {
        printf("Player can't use this skill, player already got this buff.\n");
    } else {
        if (countSkill(data.players[idPlayer].skills) <= 9) {
            // Set buff player "Cermin Pengganda" into true
            data.players[idPlayer].buff[1] = true;
            printf("Congrats, you got new buff!!\n");
            printf("New buff : Cermin Pengganda\n");
        } else {
            printf("Sorry, you can't use this skill now, please remove some skills.\n");
        }
    }
}
void useSkill5(int idPlayer) {
    if (data.players[idPlayer].buff[2]) {
        printf("Player can't use this skill, player already got this buff.\n");
    } else {
        if (data.players[idPlayer].buff[3]) {
            printf("Sorry, you can't use this skill now, other buff still active.\n");
        } else {
            // Set buff player "Senter Pembesar Hoki" into true
            data.players[idPlayer].buff[2] = true;
            printf("Congrats, you got new buff!!\n");
            printf("New buff : Senter Pembesar Hoki\n");
        }
    }
}
void useSkill6(int idPlayer) {
    if (data.players[idPlayer].buff[3]) {
        printf("Player can't use this skill, player already got this buff.\n");
    } else {
        if (data.players[idPlayer].buff[2]) {
            printf("Sorry, you can't use this skill now, other buff still active.\n");
        } else {
            // Set buff player "Senter Pengecil Hoki" into true
            data.players[idPlayer].buff[3] = true;
            printf("Congrats, you got new buff!!\n");
            printf("New buff : Senter Pengecil Hoki\n");
        }
    }
}
void useSkill7(int idPlayer, int countPlayersPlaying) {
    printf("You can switch your position with other players.\n");
    printf("Players position :\n");
    for (int i = 0; i < countPlayersPlaying; i++) {
        printf("%d. %s : ", i+1, data.players[i].name);
        showPlayerPosition(data.players[i].position);
    }
    
    printf("Select id Player : ");
    int idOpponent = playerOption()-1;
    int tempPosition = data.players[idPlayer].position;
    data.players[idPlayer].position = data.players[idOpponent].position;
    data.players[idOpponent].position = tempPosition;
    
    printf("\nSwitching position done succesfully\n");
    printf("Final players position :\n");
    for (int i = 0; i < countPlayersPlaying; i++) {
        printf("%d. %s : ", i+1, data.players[i].name);
        showPlayerPosition(data.players[i].position);
    }
}
void useSkill8(int idPlayer) {
    printf("!!! This skill was broken !!!\n");
    printf("You can't use this skill.\n");
}