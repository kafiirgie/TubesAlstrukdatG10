/* ADT Map */
/* Berisi definisi dan semua primitif pemrosesan tabel untuk map yang berisi '.', '#', dan '*'*/
/* Penempatan elemen selalu rapat kiri */

#ifndef map_H 
#define map_H

#include "boolean.h"

#define IdxMax 200
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;

typedef struct 
{
	char TI [IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
	IdxType Neff; /* banyaknya elemen efektif */
} Map;
// Banyak isi Map N, 2 <= N <= 200. Dibuat IdxMax = 200 //

void CreateEmptyMap(Map *M);

void SetElMap(Map *M, IdxType i, char v);

void SetNeffMap(Map *M, IdxType N);

int GetPosition(Map M);
/* Mengeluarkan posisi player yang ditunjukan oleh character '*' */

void InfoMap(Map M);
/* Mengeluarkan Map dan indeks posisi player */
/* .#.*..#.. 4 */

#endif