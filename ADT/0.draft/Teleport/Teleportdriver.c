#include <stdio.h>
#include <stdlib.h>
#include "Teleport.h"
#include "Teleport.c"
#include "Map.h"
#include "Map.c"

int main(){
    /* KAMUS */
    PetakTP TP;
    Map M;

    /* ALGORITMA */
    CreateEmptyPetakTP(&TP);
    CreateEmptyMap(&M);

    printf("input map...\n\n");
    SetElMap(&M, 1, '*');
    SetElMap(&M, 2, '.');
    SetElMap(&M, 3, '#');
    SetElMap(&M, 4, '.');
    SetElMap(&M, 5, '.');
    SetElMap(&M, 6, '#');
    SetElMap(&M, 7, '.');
    SetElMap(&M, 8, '#');
    SetElMap(&M, 9, '.');
    SetElMap(&M, 10, '.');
    SetNeffMap(&M, 10);

    printf("input teleporter...\n\n");
    SetElTP(&TP, 1, 2, 5);
    SetElTP(&TP, 2, 4, 9);
    SetNeffTP(&TP, 2);

    printf("~INSPECT~\n\n");
    printf("Inspect petak 2 : \n");
    inspect(M, TP, 2);
    printf("Inspect petak 4 : \n");
    inspect(M, TP, 4);
    printf("Inspect petak 6 : \n");
    inspect(M, TP, 6);
    printf("Inspect petak 7 : \n");
    inspect(M, TP, 7);
    
    printf("\n~TELEPORT~\n");
    printf("Posisi player\n");
    printf("Nobita : ");
    InfoMap(M);
    printf("\nPlayer maju ke ke petak 2\n");
    SetElMap(&M, 1, '.');
    SetElMap(&M, 2, '*');
    printf("Nobita : ");
    InfoMap(M);
    printf("teleporting...\n\n");
    teleport(&M, TP, 2);
    printf("Nobita : ");
    InfoMap(M);

}