/* ADT Teleport */

#ifndef teleport_H 
#define teleport_H

#include "boolean.h"
#include "array.h"
#include "Map.h"

typedef struct 
{
	TabInt in [198]; /* memori tempat penyimpan elemen (container) */
    TabInt out [198];
} TabTP;
/* TabTP adalah tabel yang menyimpan indeks teleporter dan tempat teleporter menuju */
/* in tempat/indeks masuk teleporter dan out tempat/indeks keluar dari teleporter */

void CreateEmptyTabTP(TabTP *TP);

void SetElTP(TabTP *TP, IdxType i, ElType In, ElType Out);

void SetNeffTP(TabTP *TP, IdxType N);

int getPetakOut(TabTP TP, ElType in);
/* mengeluarkan tempat keluar teleporter dari petak tempat masuk teleporter */

boolean Search(TabTP TP, int n);
/* True jika n adalah petak teleporter */

void inspect(Map M, TabTP TP, int X);
/* Inspect suatu petak X */

void teleport(Map *M, TabTP TP, int X);
/* Teleport dari petak X */

#endif