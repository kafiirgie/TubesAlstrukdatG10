/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesin_kar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    printf("DONT FORGET TO ADD '.' AT THE END OF THE LINE!\n");
    printf("Example : config.txt\n");
    printf("Configuration file name : \n");
    char configName[255];
    scanf("%s",configName);
    FILE * fp;
    fp = fopen (configName, "r");
    pita = fp;
    ADV();
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) {
       fclose(pita);
    }
}