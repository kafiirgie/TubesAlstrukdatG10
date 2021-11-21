/* implementasi fungsi pada teleport.h */

#include <stdio.h>
#include <stdlib.h>
#include "Teleport.h"

void CreateEmptyPetakTP(PetakTP *TP){
    (*TP).Neff = 0;
}

void SetElTP(PetakTP *TP, IdxType i, ElType In, ElType Out){
    (*TP).in[i] = In;
    (*TP).out[i] = Out;
}

void SetNeffTP(PetakTP *TP, IdxType N){
    (*TP).Neff = N;
}

int getPetakOut(PetakTP TP, ElType In){
    int idx = 1;
    while ((TP).in[idx] != In){
        idx++;
    }
    return (TP).out[idx];
}

boolean Search(PetakTP TP, ElType n){
    boolean found = false;
    for (int i=1; i<=(TP).Neff; i++){
        if ((TP).in[i] == n){
            found = true;
        }
    }
    return found;
}

void inspect(Map M, PetakTP TP, int X){
    if (Search(TP, X)){
        printf("Petak %d memiliki teleporter menuju %d.\n", X, getPetakOut(TP, X));    
    }else if(M.TI[X] == '#'){
        printf("Petak %d merupakan petak terlarang.\n", X);
    }else{
        printf("Petak %d merupakan petak kosong.\n", X);
    }
}

void teleport(Map *M, PetakTP TP, int X){
    SetElMap(&*M, X, '.');
    SetElMap(&*M, getPetakOut(TP, X), '*');
}