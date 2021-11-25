#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Skill.h"

int tabSkill[100];

void createTabSkill() {
    int i;
    /* Skill 1 - Pintu Ga Ke Mana Mana - 10% */
    for (i = 0; i < 10; i++) {
        tabSkill[i] = 1;
    }
    /* Skill 2 - Mesin Waktu - 10% */
    for (i = 10; i < 20; i++) {
        tabSkill[i] = 2;
    }
    /* Skill 3 - Baling Baling Jambu - 10% */
    for (i = 20; i < 30; i++) {
        tabSkill[i] = 3;
    }
    /* Skill 4 - Cermin Pengganda - 6% */
    for (i = 30; i < 36; i++) {
        tabSkill[i] = 4;
    }
    /* Skill 5 - Senter Pembesar Hoki - 15% */
    for (i = 36; i < 51; i++) {
        tabSkill[i] = 5;
    }
    /* Skill 6 - Senter Pengecil Hoki - 15% */
    for (i = 51; i < 66; i++) {
        tabSkill[i] = 6;
    }
    /* Skill 7 - Mesin Penukar Posisi - 4% */
    for (i = 66; i < 70; i++) {
        tabSkill[i] = 7;
    }
    /* Skill 8 - Teknologi Gagal - 30% */
    for (i = 70; i < 100; i++) {
        tabSkill[i] = 8;
    }
}

void createEmptySkill(skill *LS) {
    CreateEmpty(LS);
}

int countSkill(skill LS) {
    return NbElmt(LS);
}

int getRandomSkill() {
    time_t t;
    int x;
    
    createTabSkill();
    srand((unsigned) time (&t));
    x = rand() % 100;
    return tabSkill[x];
}

void insertSkill(skill *LS, infotype X) {
    if (countSkill(*LS) >= 10) {
        printf("Player skills are full, can't add more skill\n");
    } else {
        InsVFirst(LS, X);        
        printf("New player skill has been added\n");
    }
}

void deleteSkill(skill *LS, int num) {
    int i;
    address P, Prec, PDel;

    P = First(*LS);
    Prec = Nil;
    i = 1;
    while (i < num) {
        Prec = P;
        P = Next(P);
        i++;
    }
    if (Prec == Nil) { // skill is first element
        DelFirst(LS, &PDel);
        Dealokasi(&PDel);
    } else {  // skill isn't first element
        DelAfter(LS, &PDel, Prec);
        Dealokasi(&PDel);
    }
}

void printSkill(skill LS) {
    address P;
    int num = 1;
    if (IsEmpty(LS)) {
        printf("Player has no skills\n");
    } else {
        P = First(LS);
        do {
            switch (Info(P)) {
            case 1:
                printf("%d. %s\n", num, Skill1);
                break;
            case 2:
                printf("%d. %s\n", num, Skill2);
                break;
            case 3:
                printf("%d. %s\n", num, Skill3);
                break;
            case 4:
                printf("%d. %s\n", num, Skill4);
                break;
            case 5:
                printf("%d. %s\n", num, Skill5);
                break;
            case 6:
                printf("%d. %s\n", num, Skill6);
                break;
            case 7:
                printf("%d. %s\n", num, Skill7);
                break;
            case 8:
                printf("%d. %s\n", num, Skill8);
                break;
            default:
                break;
            }
            P = Next(P);
            num++;
        } while (P != Nil);
    }
}

int getIdSkill(skill LS, int num) {
    int x, i;
    address P;
    i = 1;
    P = First(LS);
    while (i < num) {
        P = Next(P);
        i++;
    }
    x = Info(P);
    return x;
}