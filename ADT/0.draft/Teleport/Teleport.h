/* ADT Teleport */

#ifndef teleport_H 
#define teleport_H

#include "boolean.h"
#include "Map.h"

typedef int IdxType;
typedef int ElType;

typedef struct
{
    ElType in [198];
    ElType out [198];
    IdxType Neff;
} PetakTP;
/* PetakTP adalah tabel yang menyimpan petak teleporter dan petak teleporter menuju */
/* in adalah petak masuk teleporter dan out adalah petak keluar dari teleporter */

/* Selektror */
#define In(TP) TP.in (TP)->in
#define Out(TP) (TP)->out
#define Neff(TP) (TP)->Neff

void CreateEmptyPetakTP(PetakTP *TP);

void SetElTP(PetakTP *TP, IdxType i, ElType In, ElType Out);

void SetNeffTP(PetakTP *TP, IdxType N);

int getPetakOut(PetakTP TP, ElType in);
/* mengeluarkan tempat keluar teleporter dari petak tempat masuk teleporter */

boolean Search(PetakTP TP, int n);
/* True jika n adalah petak teleporter */

void inspect(Map M, PetakTP TP, int X);
/* Inspect suatu petak X */

void teleport(Map *M, PetakTP TP, int X);
/* Teleport dari petak X */

#endif