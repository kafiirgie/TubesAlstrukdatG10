#include "Round.h"
#include "stdlib.h"


void AlokasiRonde (addressRonde *P, roundData X){
    *P = (addressRonde) malloc (sizeof(ElmtRonde));
    if (*P != Nil){
        InfoRonde(*P) = X;
        PrevRonde(*P) = Nil;
    }
}

void DeAlokasiRonde (addressRonde  P){
    free(P);
}

boolean IsRondeEmpty (Ronde S){
    return TopRonde(S) == Nil;
}

void CreateRondeEmpty (Ronde * S){
    TopRonde(*S) = Nil;
}

void PushRonde (Ronde * S, roundData X){
    addressRonde A;
    AlokasiRonde(&A, X);
    if (A == Nil) return;

    addressRonde first = TopRonde(*S);
    PrevRonde(A) = first;
    TopRonde(*S) = A;
}

void PopRonde (Ronde * S, roundData * X){
    *X = CurrRonde(*S);

    addressRonde deleted = TopRonde(*S);
    TopRonde(*S) = PrevRonde(deleted);
}