/* Driver for mesin_kar */

#include <stdio.h>
#include <stdlib.h>
#include "../MesinKarKat/mesin_kar.h"

int main(){
    sscanf("config.txt", "%s", fileName);
    START(1);
    while (!EOP){
        printf("%c", CC);
        ADV();
    }
}
