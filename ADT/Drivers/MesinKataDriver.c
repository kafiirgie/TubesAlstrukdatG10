/* Driver for mesin_kata */

#include <stdio.h>
#include <stdlib.h>
#include "../MesinKarKat/mesin_kata.h"

int main(){
    sscanf("config.txt", "%s", fileName);
    STARTKATA(1);
    while (!EndKata){
        printKata(CKata);
        ADVKATA();
    }
}
