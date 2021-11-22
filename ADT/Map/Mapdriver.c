#include <stdio.h>
#include <stdlib.h>
#include "Map.h"
#include "Map.c"

int main(){
    /* KAMUS */
    Map M;

    /* ALGORITMA */
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

    printf("~MAP~\n");
    printf("\nNobita : ");
    InfoMap(M);    
}