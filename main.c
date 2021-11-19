#include "stdio.h"
#include "View/Game/Game.h"
#include "View/Menu/Menu.h"
#include "View/Exit/Exit.h"

void initial();

int main(int argc, char **argv) {
    initial();
    exitView();
    return 0;
}

void initial() {
    MenuView();
    if (selection != 0 ){
        GameView(selection);
        initial();
    }
}