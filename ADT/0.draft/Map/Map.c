/* implementasi fungsi Map.h */

#include <stdio.h>
#include <stdlib.h>
#include "Map.h"

void CreateEmptyMap(Map *M){
    (*M).Neff = 0;
}

void SetElMap(Map *M, IdxType i, char v){
    (*M).TI[i] = v;
}

void SetNeffMap(Map *M, IdxType N){
    (*M).Neff = N;
}

int GetPosition(Map M){
    int idx = 1;
    while (M.TI[idx] != '*'){
        idx++;
    }
    return idx;
}

void InfoMap(Map M){
    for (int i=1; i<=M.Neff; i++){
        printf("%c", M.TI[i]);
    }
    printf(" %d\n", GetPosition(M));
}

