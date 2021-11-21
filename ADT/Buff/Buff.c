#include <stdio.h>
#include <stdlib.h>
#include "Buff.h"


void CreateEmptyBuff(Buff *LB) {
    CreateEmpty(LB);
}

int CountBuff(Buff LB) {
    return NbElmt(LB);
}

void InsertBuff(Buff *LB, infotype X) {
    InsVFirst(LB, X);
}

void DeleteBuff(Buff *LB, infotype X) {
    DelP(LB, X);
}

void ClearBuff(Buff *LB) {
    if (Search(*LB, 2)) {
        DelP(LB, 2);
    }
    if (Search(*LB, 3)) {
        DelP(LB, 3);
    }
    if (Search(*LB, 4)) {
        DelP(LB, 4);
    }
       
}

void PrintBuff(Buff LB) {
    address P;
    int Num = 1;
    if (IsEmpty(LB)) {
        printf("Pemain tidak memiliki Buff\n");
    } else {
        P = First(LB);
        do {
            switch (Info(P)) {
                case 1:
                    printf("%d. %s\n", Num, Buff1);
                    break;
                case 2:
                    printf("%d. %s\n", Num, Buff2);
                    break;
                case 3:
                    printf("%d. %s\n", Num, Buff3);
                    break;
                case 4:
                    printf("%d. %s\n", Num, Buff4);
                    break;
                default:
                    break;
            }
            P = Next(P);
            Num++;
        } while (P != Nil);
    }
}