#include <stdio.h>
#include <stdlib.h>
#include "Teleport.h"

void CreateEmptyTabTP(TabTeleport *TP){
    (*TP).Neff = 0;
}

void SetElTP(TabTeleport *TP, IdxType i, int in, int out){
    (*TP).TI[i].in = in;
    (*TP).TI[i].out = out;
}

void SetNeffTP(TabTeleport *TP, IdxType N){
    (*TP).Neff = N;
}

int GetTPOut(TabTeleport TP, int in){
    int idx = 1;
    while ((TP.TI[idx].in != in) && (idx < TP.Neff)){
        idx++;
    }
    if (TP.TI[idx].in == in){
        return TP.TI[idx].out;
    } else {
        return -999;
    }   
}

boolean SearchTP(TabTeleport TP, int in){
    boolean found = false;
    int idx = 1;
    while ((TP.TI[idx].in != in) && (idx < TP.Neff)){
        idx++;
    }
    if (TP.TI[idx].in == in){
        found = true;
    }
    return found;
}

void InspectMap(Map M, TabTeleport TP, int X){
    if (SearchTP(TP, X)) {
        printf("Petak %d memiliki teleporter menuju %d.\n", X, GetTPOut(TP, X));    
    } else if (M.TI[X] == '#'){
        printf("Petak %d merupakan petak terlarang.\n", X);
    } else {
        printf("Petak %d merupakan petak kosong.\n", X);
    }
}

void RunTeleport(Map *M, TabTeleport TP, int X){
    SetElMap(M, X, '.');
    SetElMap(M, GetTPOut(TP, X), '*');
}