#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Skill.h"
#include "../Buff/Buff.h"

int TabSkill[100];

void CreateTabSkill() {
    int i;
    /* Skill 1 - Pintu Ga Ke Mana Mana - 10% */
    for (i = 0; i < 10; i++) {
        TabSkill[i] = 1;
    }
    /* Skill 2 - Mesin Waktu - 10% */
    for (i = 10; i < 20; i++) {
        TabSkill[i] = 2;
    }
    /* Skill 3 - Baling Baling Jambu - 10% */
    for (i = 20; i < 30; i++) {
        TabSkill[i] = 3;
    }
    /* Skill 4 - Cermin Pengganda - 6% */
    for (i = 30; i < 36; i++) {
        TabSkill[i] = 4;
    }
    /* Skill 5 - Senter Pembesar Hoki - 15% */
    for (i = 36; i < 51; i++) {
        TabSkill[i] = 5;
    }
    /* Skill 6 - Senter Pengecil Hoki - 15% */
    for (i = 51; i < 66; i++) {
        TabSkill[i] = 6;
    }
    /* Skill 7 - Mesin Penukar Posisi - 4% */
    for (i = 66; i < 70; i++) {
        TabSkill[i] = 7;
    }
    /* Skill 8 - Teknologi Gagal - 30% */
    for (i = 70; i < 100; i++) {
        TabSkill[i] = 8;
    }
}

void CreateEmptySkill(Skill *LS) {
    CreateEmpty(LS);
}

int CountSkill(Skill LS) {
    return NbElmt(LS);
}

int RandomSkill() {
    time_t t;
    int x;
    
    CreateTabSkill();
    srand((unsigned) time (&t));
    x = rand() % 100;
    return TabSkill[x];
}

void InsertSkill(Skill *LS, infotype X) {
    if (CountSkill(*LS) >= 10) {
        printf("Skill penuh, tidak dapat menambahkan skill\n");
    } else {
        InsVFirst(LS, X);        
    }
}

void DeleteSkill(Skill *LS, int Num) {
    int X, i;
    address P, Prec, PDel;
    P = First(*LS);
    Prec = Nil;
    i = 1;
    while (i < Num) {
        Prec = P;
        P = Next(P);
        i++;
    }
    if (Prec == Nil) { // X merupakan elemen pertama
        DelFirst(LS, &PDel);
        Dealokasi(&PDel);
    } else {  // X bukan merupkan elemen pertama
        DelAfter(LS, &PDel, Prec);
        Dealokasi(&PDel);
    }
}

void PrintSkill(Skill LS) {
    address P;
    int Num = 1;
    if (IsEmpty(LS)) {
        printf("Pemain tidak memiliki skill\n");
    } else {
        P = First(LS);
        do {
            switch (Info(P)) {
                case 1:
                    printf("%d. %s\n", Num, Skill1);
                    break;
                case 2:
                    printf("%d. %s\n", Num, Skill2);
                    break;
                case 3:
                    printf("%d. %s\n", Num, Skill3);
                    break;
                case 4:
                    printf("%d. %s\n", Num, Skill4);
                    break;
                case 5:
                    printf("%d. %s\n", Num, Skill5);
                    break;
                case 6:
                    printf("%d. %s\n", Num, Skill6);
                    break;
                case 7:
                    printf("%d. %s\n", Num, Skill7);
                    break;
                case 8:
                    printf("%d. %s\n", Num, Skill8);
                    break;
                default:
                    break;
            }
            P = Next(P);
            Num++;
        } while (P != Nil);
    }
}

void RunSkill(Skill LS, int Num) {
    int X;
    int i = 1;
    address P = First(LS);
    // get id skill (x)
    while (i < Num) {
        P = Next(P);
        i++;
    }
    X = Info(P);
    // run skill
    switch (X) {
        case 1:
            RunSkill1();
            break;
        case 2:
            RunSkill2();
            break;
        case 3:
            RunSkill3();
            break;
        case 4:
            RunSkill4();
            break;
        case 5:
            RunSkill5();
            break;
        case 6:
            RunSkill6();
            break;
        case 7:
            RunSkill7();
            break;
        case 8:
            RunSkill8();
            break;
        default:
            break;
    }
    // delete skill
    DeleteSkill(&LS, Num);
    // update buff
    // {code here}
}

void RunSkill1() {}
void RunSkill2() {}
void RunSkill3() {}
void RunSkill4() {}
void RunSkill5() {}
void RunSkill6() {}
void RunSkill7() {}
void RunSkill8() {}