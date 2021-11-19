#include "Menu.h"

int selection = -1;

void MenuView() {
    int select = -9;
    printf("Hello user!, welcome to the game, please select...\n");
    printf("[0].Exit\n");
    printf("[1].New Game\n");
    printf("[2].Load Game\n");
    printf("Your selection : ");
    scanf("%d", &select);
    printf("\n");
    setSelection(select);
}

void setSelection(int value) {
    selection = value;
}