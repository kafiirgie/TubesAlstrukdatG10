/* Driver for mesin_kar */

#include <stdio.h>
#include <stdlib.h>
#include "mesin_kar.h"
#include "mesin_kar.c"

int main(){
    sscanf("config.txt", "%s", fileName);
    START(1);
    while (!EOP){
        printf("%c", CC);
        ADV();
    }
}
