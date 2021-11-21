#include <stdio.h>
#include <stdlib.h>
#include "Buff.h"


int main(){
    Buff PlayerBuff;

    // Create Buff
    printf("### Create Buff ###\n");
    CreateEmptyBuff(&PlayerBuff);
    PrintBuff(PlayerBuff);
    printf("\n");
    // Insert Buff
    printf("### Insert Buff ###\n");
    InsertBuff(&PlayerBuff, 1);
    InsertBuff(&PlayerBuff, 3);
    InsertBuff(&PlayerBuff, 2);
    InsertBuff(&PlayerBuff, 4);
    PrintBuff(PlayerBuff);
    printf("\n");
    // Delete Buff
    printf("### Delete Buff ###\n");
    DeleteBuff(&PlayerBuff, 3);
    PrintBuff(PlayerBuff);
    printf("\n");
    // Clear Buff
    printf("### Clear Buff ###\n");
    ClearBuff(&PlayerBuff);
    PrintBuff(PlayerBuff);
    printf("\n");


    return 0;
}
