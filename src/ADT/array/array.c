/* implementasi fungsi2 primitif dll pada array.h */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/*KONSTRUKTOR*/
void MakeEmpty (TabInt *T){
    (*T).Neff = 0; 
}

/*SELEKTOR*/
/*Banyak elemen*/
int NbElmt (TabInt T){
    return T.Neff;
}
int MaxNbEl (TabInt T){
    return IdxMax;
}
/*selektor indeks*/
IdxType GetFirstIdx (TabInt T){
    return IdxMin;
}
IdxType GetLastIdx (TabInt T){
    return T.Neff;
}
ElType GetElmt (TabInt T, IdxType i){
    return T.TI[i];
}

/*Selektor SET: Mengubah nilai TABEL dan elemen tabel*/
void SetTab (TabInt Tin, TabInt *Tout){
    for(IdxType i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++){
        (*Tout).TI[i] = Tin.TI[i];
    }
}

void SetEl (TabInt *T, IdxType i, ElType v){
    (*T).TI[i] = v;
}

void SetNeff (TabInt *T, IdxType N){
    (*T).Neff = N;
}

/*Test Indeks yang valid*/
boolean IsIdxValid (TabInt T, IdxType i){
    return((i >= IdxMin) && (i <= IdxMax) );
}

boolean IsIdxEff (TabInt T, IdxType i){
    return((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/*TEST KOSONG/PENUH*/
boolean IsEmpty (TabInt T){
    return(T.Neff == 0);
}
boolean IsFull (TabInt T){
    return(T.Neff == (IdxMax-IdxMin+1));
}