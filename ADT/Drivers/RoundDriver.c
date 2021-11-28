/* Driver for Round */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Round/Round.h"
#include "../Player/Player.h"
#include "../Configuration/Configuration.h"

int main(){
    Ronde rounde;
    player player1;
    player player2;
    roundData data, datadel;

    // Create Empty
    CreateRondeEmpty(&rounde);
    
    // ROUND 1
    printf("\n===== ROUND 1 =====\n");
    printf("Player name : ");
    setPlayer(&player1);
    data.players[0] = player1;
    data.rondeKeberapa = 1;
    
    PushRonde(&rounde,data);
    
    printf("Nama player : %s\n",rounde.TOP->Info.players[0].name);
    printf("Ronde ke : %d\n",rounde.TOP->Info.rondeKeberapa);
    
    // ROUND 2
    printf("\n===== ROUND 2 =====\n");
    printf("Player name : ");
    setPlayer(&player2);
    data.players[1] = player2;
    data.rondeKeberapa = 2;
    
    PushRonde(&rounde,data);
    
    printf("Nama player 1 : %s\n",rounde.TOP->Info.players[0].name);
    printf("Nama player 2 : %s\n",rounde.TOP->Info.players[1].name);
    printf("Ronde ke : %d\n",rounde.TOP->Info.rondeKeberapa);

    // POP
    printf("\n===== POP ROUND 2 =====\n");
    PopRonde(&rounde, &datadel);
    printf("Data saat ini\n");
    printf("Ronde ke : %d\n",rounde.TOP->Info.rondeKeberapa);
    printf("Data yang dihapus\n");
    printf("Ronde ke : %d\n",datadel.rondeKeberapa);

    // END
    free(rounde.TOP);
    
    return 0;
}