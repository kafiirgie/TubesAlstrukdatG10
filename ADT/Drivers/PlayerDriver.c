/* Driver for Player */

#include <stdio.h>
#include <stdlib.h>
#include "../Player/Player.h"
#include "../Configuration/Configuration.h"

int main(){
    player p;
    
    /* load configuration */
    //setConfigFile();
    sscanf("config.txt", "%s", fileName);
    loadConfig();
    
    /* set Player */
    printf("\nEnter player name: ");
    setPlayer(&p);

    /* Move Player */
    printf("\nPlayer role dice\n");
    playerRollDice(&p, maxDiceRole);

    /* select option */
    printf("\nInput number selection : ");
    int selection = playerOption();
    printf("Player select option %d\n", selection);

    /* Buff */
    printf("\nPlayer buff :\n");
    resetPlayerBuff(&p);
    showPlayerBuff(&p);

    /* inspect */
    printf("\nPlayer position : ");
    showPlayerPosition(p.position);
}