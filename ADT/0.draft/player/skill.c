#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skill.h"

void CreateTabSkill(TabSkill *TS) {
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    /* Skill 1 - Pintu Ga Ke Mana Mana - 10% */
    for (i = 0; i < 10; i++) {
        TI(*TS)[i] = 1;
    }
    /* Skill 2 - Mesin Waktu - 10% */
    for (i = 10; i < 20; i++) {
        TI(*TS)[i] = 2;
    }
    /* Skill 3 - Baling Baling Jambu - 10% */
    for (i = 20; i < 30; i++) {
        TI(*TS)[i] = 3;
    }
    /* Skill 4 - Cermin Pengganda - 6% */
    for (i = 30; i < 36; i++) {
        TI(*TS)[i] = 4;
    }
    /* Skill 5 - Senter Pembesar Hoki - 15% */
    for (i = 36; i < 51; i++) {
        TI(*TS)[i] = 5;
    }
    /* Skill 6 - Senter Pengecil Hoki - 15% */
    for (i = 51; i < 66; i++) {
        TI(*TS)[i] = 6;
    }
    /* Skill 7 - Mesin Penukar Posisi - 4% */
    for (i = 66; i < 70; i++) {
        TI(*TS)[i] = 7;
    }
    /* Skill 8 - Teknologi Gagal - 30% */
    for (i = 70; i < 100; i++) {
        TI(*TS)[i] = 8;
    }
}

void CreateEmptySkill(List *L) {
    CreateEmpty(L);
}

int CountSkill(List L) {
    return NbElmt(L);
}

int RandomSkill(List L, TabSkill TS) {
    /* KAMUS LOKAL */
    time_t t;
    int x;
    /* ALGORTIMA */
    srand((unsigned) time (&t));
    x = rand() % 100;
    return TI(TS)[x];
}

void InsertSkill(List *L, infotype X) {
    InsVFirst(L, X);
}

void DeleteSkill(List *L, infotype X) {
    DelP(L, X);
}

void PrintSkill(List LSkill) {
    /* KAMUS */
    address P;
    /* ALGORITMA */
    if (IsEmpty(LSkill)) {
        printf("Pemain tidak memiliki skill\n");
    } else {
        P = First(LSkill);
        do {
            switch (Info(P)) {
            case 1:
                printf("1 - Pintu Ga Ke Mana Mana\n");
                break;
            case 2:
                printf("2 - Mesin Waktu\n");
                break;
            case 3:
                printf("3 - Baling Baling Jambu\n");
                break;
            case 4:
                printf("4 - Cermin Pengganda\n");
                break;
            case 5:
                printf("5 - Senter Pembesar Hoki\n");
                break;
            case 6:
                printf("6 - Senter Pengecil Hoki\n");
                break;
            case 7:
                printf("7 - Mesin Penukar Posisi\n");
                break;
            case 8:
                printf("8 - Teknologi Gagal\n");
                break;
            }
            P = Next(P);
        } while (P != Nil);
    }
}

void RunSkill(List L, infotype X) {
    
}
