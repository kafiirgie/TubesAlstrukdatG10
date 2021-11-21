#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Skill.h"


void delay(int number_of_seconds) {
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void loading(int input_seconds) {
    int i;
    printf("\nloading ");
    for (i = 0; i < input_seconds; i++) {
        // delay of one second
        delay(1);
        printf(". ", i + 1);
    }
    printf("\n");
}

int main(){
    int IDSkill;
    Skill LSkill;

    printf("\n===== SKILL =====\n");
    
    CreateEmptySkill(&LSkill);

    printf("\n## Skill Pertama ##\n");
    printf("Melakukan random skill pemain\n");
    IDSkill = RandomSkill(LSkill);
    printf("Skill yang diperoleh adalah : %d\n", IDSkill);
    InsertSkill(&LSkill, IDSkill);
    printf("Skill pemain saat ini :\n");
    PrintSkill(LSkill);
    printf("\n");
    
    loading(5);

    printf("\n## Operasi Skill tiap Ronde ##");
    int input;
    do {
        printf("\n~ AWAL RONDE ~\n");
        if (CountSkill(LSkill) == 10) {
            printf("Skill penuh, tidak dapat melakukan random skill\n");
        } else {
            // Random Skill
            printf("Melakukan random skill pemain\n");
            IDSkill = RandomSkill(LSkill);
            printf("Skill yang diperoleh adalah : %d\n", IDSkill);
            // Insert Skill
            InsertSkill(&LSkill, IDSkill);
        }
        // Print Skill
        printf("Skill pemain saat ini :\n");
        PrintSkill(LSkill);
        // Get user input
        printf("\nMasukkan input : ");
        scanf("%d", &input);
        // Do operation based on user input
        if (input > 0) {
            printf("Skill %d berhasil digunakan!!\n", input);
            DeleteSkill(&LSkill, input);
        } else if (input < 0) {
            input *= -1;
            printf("Skill %d berhasil dibuang\n", input);
            DeleteSkill(&LSkill, input);
        }
        printf("~ AKHIR RONDE ~\n");
        loading(3);
    } while (input != 0);
    // End of program
    printf("===== AKHIR PROGRAM =====\n\n");

    return 0;
}
