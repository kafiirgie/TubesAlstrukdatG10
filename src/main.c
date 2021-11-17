#include <stdio.h>
#include <stdlib.h>
#include "initialization.h"
#include "Menu.h"
#include "Game.h"

int main(int argc, char **argv) {
    //MARK: Initialization of the program, just display a welcoming message 
    ProgramInit();
    int menuSelection = 0;
    while (1==1) {
        //MARK: move to another view based on player selection
        menuSelection = playerSelection();
        if (menuSelection == 1) newGame();
        else if (menuSelection == 2) loadGame();
        else break;
    }
    printf("Thank you for playing!");
    return 0;
}