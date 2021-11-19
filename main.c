#include "stdio.h"
#include "View/Game/Game.h"
#include "View/Menu/Menu.h"

int main(int argc, char **argv) {
    while (1==1) {
        MenuView();
        if (selection == 0) break;
        GameView(selection);
    }
    printf("Thank you for playing\n");
    return 0;
}