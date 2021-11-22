/* File: mesin_kar.h */
/* Definisi Mesin Karakter */

#ifndef Mesin_Kar_H
#define Mesin_Kar_H

#include "../boolean.h"
#include <string.h>

#define MARK '!'
/* State Mesin */
extern char CC;
extern boolean EOP;
extern char fileName [255];

void START(int type);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */

#endif
