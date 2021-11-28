#include "Menu.h"

int selection = -1;

void MenuView() {
    int select = -9;
    printf("\n  =========================\n");
    printf("========= MAIN MENU =========\n");
    printf("  =========================\n");
    printf("Hello user!, welcome to the game, please select...\n");
    printf("[0].Exit\n");
    printf("[1].New Game\n");
    printf("Your selection : ");
    scanf("%d", &select);
    printf("\n");
    setSelection(select);
}

void setSelection(int value) {
    selection = value;
}