/* ADT Map */
/* Berisi definisi dan semua primitif pemrosesan tabel untuk map yang berisi '.', '#', dan '*'*/
/* Penempatan elemen selalu rapat kiri */

#ifndef Map_H 
#define Map_H

#include "../boolean.h"

#define IdxMaxMap 200
#define IdxMinMap 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;

typedef struct {
	char TI [IdxMaxMap-IdxMinMap+1]; /* memori tempat penyimpan elemen (container) */
	IdxType Neff; /* banyaknya elemen efektif */
} Map;
/* Indeks yang digunakan [IdxMinMap..IdxMaxMap] atau [1..200]*/
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */


void CreateEmptyMap(Map *M);

void SetElMap(Map *M, IdxType i, char v);

void SetNeffMap(Map *M, IdxType N);

int GetPosition(Map M);
/* Mengeluarkan posisi player yang ditunjukan oleh character '*' */

void DisplayMap(Map M);
/* Mengeluarkan Map */

void InfoMap(Map M);
/* Mengeluarkan Map dan indeks posisi player */
/* .#.*..#.. 4 */

#endif