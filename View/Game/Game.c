#include "Game.h"
#include "OpenConf.h"
#include "mesin_kata.h"

void newGame() {
    int player = 0;
    printf("Welcome Players! \n");
    while (player <= 0 || player > 4) {
        printf("How many are playing today? (1-4 players only) :");
        scanf("%d", &player);
        if (player > 0 && player <= 4) break;
        printf("\n Whoops! Looks like your input does not satify the requirement needed\n");
    }
    // Load configuration
    loadConfig();

    printf("Hajimemasho minna san?\n");
    printf("Press any key to continue...\n");
    getchar();

    startGame();
}

void loadGame(){
    //MARK: WIP
    //loadConfig();
    startGame();
}

void startGame() {
    endGame();
}

void endGame() {
    freeTeleportPlaces();
    freeMap();
}