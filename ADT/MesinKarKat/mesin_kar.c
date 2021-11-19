/* File: mesinkar.c */
/* Implementasi Mesin Karakter */


#include "mesin_kar.h"
#include <stdio.h>
#include <stdlib.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;
char fileName [255];

void START(int type) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
       if (type == 1) {
              pita = fopen(fileName,"r");
              //error handler, to be continue
              if (pita == NULL) {
                     printf("Found null");
                     return;
              }
       } else {
              pita = stdin;
              //printf("Your name : ")
       }
       //printf("start");
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