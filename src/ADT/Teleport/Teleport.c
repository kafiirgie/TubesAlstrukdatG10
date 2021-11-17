/* implementasi fungsi pada teleport.h */

#include <stdio.h>
#include <stdlib.h>
#include "Teleport.h"

void CreateEmptyTabTP(TabTP *TP){
    TabInt In, Out;
    MakeEmpty(&In);
    MakeEmpty(&Out);
    *(*TP).in = In;
    *(*TP).out = Out;
}

void SetElTP(TabTP *TP, IdxType i, ElType In, ElType Out){
    (*(*TP).in).TI[i] = In;
    (*(*TP).out).TI[i] = Out;
}

void SetNeffTP(TabTP *TP, IdxType N){
    (*(*TP).in).Neff = N;
    (*(*TP).out).Neff = N;
}

int getPetakOut(TabTP TP, ElType In){
    int idx = 1;
    while ((*TP.in).TI[idx] != In){
        idx++;
    }
    return (*TP.out).TI[idx];
}

boolean Search(TabTP TP, int n){
    boolean found = false;
    for (int i=1; i<=(*TP.in).Neff; i++){
        if ((*TP.in).TI[i] == n){
            found = true;
        }
    }
    return found;
}

void inspect(Map M, TabTP TP, int X){
    if (Search(TP, X)){
        printf("Petak %d memiliki teleporter menuju %d.\n", X, getPetakOut(TP, X));    
    }else if(M.TI[X] == '#'){
        printf("Petak %d merupakan petak terlarang.\n", X);
    }else{
        printf("Petak %d merupakan petak kosong.\n", X);
    }
}

void teleport(Map *M, TabTP TP, int X){
    SetElMap(&*M, X, '.');
    SetElMap(&*M, getPetakOut(TP, X), '*');
}