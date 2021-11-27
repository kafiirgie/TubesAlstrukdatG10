/* Driver for Player */

#include <stdio.h>
#include <stdlib.h>
#include "Player.h"
#include "Player.c"
#include "ListLinier.c"
#include "Skill.c"
#include "Configuration.c"
#include "mesin_kar.c"
#include "mesin_kata.c"

int main(){
    player p;
    int MaxDice = 20;
    /* set Player */
    printf("Enter player name: ");
    setPlayer(&p);

    /* Move Player */
    playerRollDice(&p, MaxDice);

    /* select option */
    playerOption();

    /* Buff */
    resetPlayerBuff(&p);
    showPlayerBuff(&p);

    /* inspect */
    showPlayerPosition(1);
}