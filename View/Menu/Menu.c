#include "Menu.h"

int playerSelection() {
    int selection = 0;
    printf("MENU");
    printf("0. Exit");
    printf("1. New Game");
    printf("2. Load Game");
    scanf("%d", &selection);
    return selection;
}