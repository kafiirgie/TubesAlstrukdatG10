#include <stdio.h>
#include <stdlib.h>

#include "initialization.h"

int main(int argc, char **argv) {
    //MARK: Initialization of the program, just display a welcoming message 
    ProgramInit();
    int menuSelection = 0;
    while (1==1) {
        //MARK: move to another view based on player selection
        menuSelection = playerSelection()
        if (menuSelection == 0) break;
    }
    printf("Thank you for player!");
    return 0;
}