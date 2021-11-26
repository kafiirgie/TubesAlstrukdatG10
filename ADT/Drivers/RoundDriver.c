#include "../Round/Round.h"
#include "../Player/Player.h"
#include <string.h>

int main(int argc, char **argv){
    Ronde rounde;
    player players;
    roundData data;
    setPlayer(&players);
    sscanf("makan bang","%s",&players.name);
    CreateRondeEmpty(&rounde);
    data.players[0] = players;
    data.players[1] = players;
    data.rondeKeberapa = 1;
    PushRonde(&rounde,data);
    printf("%s",rounde.TOP->Info.players[0].name);
    free(rounde.TOP);
    return 0;
}