#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listlinier.h"
#include "listlinier.c"

int GetFirstSkill(){
    int TabSkill[100];
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

    time_t t;
    int x, skill;
    srand ((unsigned) time (&t));
    x = rand() % 100;
    skill = TabSkill[x];
    printf("Indeks dalam array = %d\n", x);
    printf("Indeks skill = %d\n", skill);
    
    return skill;
}

int main(){
    int skill = GetFirstSkill();
    List LSkill;
    printf("\nLIST SKILL PEMAIN\n");
    CreateEmpty(&LSkill);
    InsVFirst(&LSkill, skill);
    PrintInfo(LSkill); printf("\n");
    printf("\n");

    return 0;
}
