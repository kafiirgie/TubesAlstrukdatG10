/* ADT Teleport */

#ifndef Teleport_H 
#define Teleport_H

#include "../boolean.h"
#include "../Map/Map.h"

#define IdxMaxTP 198
#define IdxMinTP 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct {
    int in; /* in adalah petak masuk teleporter */
    int out; /* out adalah petak keluar dari teleporter */
} Teleport;
typedef struct {
	Teleport TI [IdxMaxTP-IdxMinTP+1]; /* memori tempat penyimpan elemen (container) */
	IdxType Neff; /* banyaknya elemen efektif */
} TabTeleport;
/* Indeks yang digunakan [IdxMinTP..IdxMaxTP] atau [1..198]*/
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */


void CreateEmptyTabTP(TabTeleport *TP);

void SetElTP(TabTeleport *TP, IdxType i, int in, int out);

void SetNeffTP(TabTeleport *TP, IdxType N);

int GetTPOut(TabTeleport TP, int in);
/* mengeluarkan tempat keluar teleporter dari petak tempat masuk teleporter */

boolean SearchTP(TabTeleport TP, int in);
/* True jika n adalah petak teleporter */

void InspectMap(Map M, TabTeleport TP, int X);
/* Inspect suatu petak X */

void RunTeleport(Map *M, TabTeleport TP, int X);
/* Teleport dari petak X */

#endif