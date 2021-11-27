/* Driver for mesin_kar */

#include <stdio.h>
#include <stdlib.h>
#include "mesin_kata.h"
#include "mesin_kata.c"
#include "mesin_kar.c"

int main(){
    sscanf("config.txt", "%s", fileName);
    STARTKATA(1);
    while (!EndKata){
        printKata(CKata);
        ADVKATA();
    }
}
